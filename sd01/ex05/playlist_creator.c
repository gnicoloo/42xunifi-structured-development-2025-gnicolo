/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playlist_creator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:06:38 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/13 11:12:45 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "playlist_creator.h"
#include <stdlib.h>


struct Playlist *create_playlist(void)
{
    MoodSettings *mood = analyze_user_mood();
    if (!mood)
        return (NULL);
    FilterSettings *filters = default_filters();
    if (!filters)
		return (free_mood_settings(mood), NULL);
    int variations = get_mood_variations(mood);
    for (int i = 0; i < variations; i++)
	{
        FilterSettings *new_filters = refine_filters(filters);
        if (!new_filters)
		{
            free_filter_settings(filters);
            free_mood_settings(mood);
            return (NULL);
        }
        if (new_filters != filters)
		{
            free_filter_settings(filters);
            filters = new_filters;
        }
    }
    SongData *song = NULL;
    if (filters_require_popular_song(filters))
        song = fetch_popular_song();
    else
        song = fetch_niche_song();
	if (!song) 
		return (free_filter_settings(filters), free_mood_settings(mood), NULL);
	Playlist *playlist = combine_with_mood_playlist(song, mood);
	free_mood_settings(mood);
	free_filter_settings(filters);
	free_song_data(song);
	return (playlist);
}

