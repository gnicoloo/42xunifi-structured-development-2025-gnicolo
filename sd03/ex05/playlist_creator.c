/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playlist_creator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:40:42 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/20 11:40:44 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "playlist_creator.h"
void	free_all_resources(MoodSettings *mood, FilterSettings *settings, SongData *song_data, Playlist *playlist)
{
	if (mood)
		free_mood_settings(mood);
	if (settings)
		free_filter_settings(settings);
	if (song_data)
		free_song_data(song_data);
	if (playlist)
		free_playlist(playlist);
}

Playlist	*get_playlist_with_variations(MoodSettings *mood, FilterSettings *settings)
{
	FilterSettings	*changed_settings;
	SongData		*song_data;
	Playlist		*playlist;

	song_data = NULL;
	playlist = NULL;
	changed_settings = refine_filters(settings);
	if (!changed_settings)
	{
		free_all_resources(mood, settings, NULL, NULL);
		return (NULL);
	}
	changed_settings->popular = filters_require_popular_song(changed_settings);
	if (changed_settings->popular != 0)
		song_data = fetch_popular_song();
	else
		song_data = fetch_niche_song();
	if (!song_data)
	{
		free_all_resources(mood, changed_settings, NULL, NULL);
		return (NULL);
	}
	playlist = combine_with_mood_playlist(song_data, mood);
	free_all_resources(mood, changed_settings, NULL, NULL);
	return (playlist);
}

Playlist	*get_playlist_with_no_variations(MoodSettings *mood, FilterSettings *settings)
{
	SongData	*song_data;
	Playlist	*playlist;

	playlist = NULL;
	song_data = NULL;
	settings->popular = filters_require_popular_song(settings);
	if (settings->popular != 0)
		song_data = fetch_popular_song();
	else
		song_data = fetch_niche_song();
	if (!song_data)
	{
		free_all_resources(mood, settings, NULL, NULL);
		return (NULL);
	}
	playlist = combine_with_mood_playlist(song_data, mood);
	free_all_resources(mood, settings, NULL, NULL);
	return (playlist);
}

Playlist	*create_playlist(void)
{
	MoodSettings	*mood;
	FilterSettings	*settings;
	int				mood_variations;
	Playlist		*playlist;

	mood_variations = 0;
	playlist = NULL;
	settings = NULL;
	mood = analyze_user_mood();
	if (!mood)
		return (NULL);
	settings = default_filters();
	if (!settings)
	{
		free_all_resources(mood, NULL, NULL, NULL);
		return (NULL);
	}
	mood_variations = get_mood_variations(mood);
	if (mood_variations != 0)
		playlist = get_playlist_with_variations(mood, settings);
	else
		playlist = get_playlist_with_no_variations(mood, settings);
	return (playlist);
}

