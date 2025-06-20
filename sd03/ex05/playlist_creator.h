/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playlist_creator.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:40:50 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/20 11:40:52 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYLIST_CREATOR_H
# define PLAYLIST_CREATOR_H

# include <stdbool.h>
# include <stdlib.h>


typedef enum e_MusicGenre
{
	UNKNOWN,
	POP,
	ROCK,
	HIPHOP,
	JAZZ,
	CLASSICAL,
	ELECTRONIC,
	RNB,
	COUNTRY,
	REGGAE,
	BLUES,
	METAL,
	SOUL,
	FOLK,
	LATIN,
	KPOP,
	LOFI,
	AMBIENT,
	PUNK,
	DANCE
}	MusicGenre;

typedef enum e_UserMood
{
	HAPPY,
	SAD,
	ANGRY,
	RELAXED,
	ANXIOUS,
	LOVE,
	LONELY,
	FOCUSED,
	TIRED,
	PARTY,
	NOSTALGIC,
	MOTIVATED,
	BORED,
	CONFIDENT,
	CURIOUS
}	UserMood;

typedef enum e_ContextCode
{
	NONE,
	WORK,
	EXERCISE,
	RELAX,
	COMMUTE,
	PARTYS,
	SLEEP,
	FOCUS,
	OUTDOORS,
	CLEANING,
	SHOPPING
} ContextCode;

typedef struct	s_MoodSettings
{
	UserMood	user_mood;
	ContextCode	context;
	int			bpm_preference;
}	MoodSettings;

typedef struct	s_FilterSettings
{
	MusicGenre	genre;
	bool		only_instrument;
	float		max_duration_min;
	float		rating;
	int			popular;
}	FilterSettings;

typedef struct s_SongData
{
	MusicGenre  genre;
	char	*title;
	char	*artist;
	int		duration_seconds;
	float	rating;
	int		bpm;
} SongData;

typedef struct	s_Playlist
{
	char		*playlist_name;
	SongData	**my_songs;
	int			songs_count;
	int			songs_capacity;
}	Playlist;

// Analyze user mood. Returns a new MoodSettings or NULL on failure.
MoodSettings *analyze_user_mood(void);
// Return default filter settings. Returns a new FilterSettings or NULL on failure.
FilterSettings *default_filters(void);
// Return the number of mood variations for refinement.
int get_mood_variations(MoodSettings *mood);
// Refine the current filter settings. Returns the same or a new FilterSettings, or NULL on failure.
FilterSettings *refine_filters(FilterSettings *current);
// Check if filters require a popular or niche song. Returns nonzero if popular.
int filters_require_popular_song(FilterSettings *filters);
// Fetch a popular song. Returns a new SongData or NULL on failure.
SongData *fetch_popular_song(void);
// Fetch a niche song. Returns a new SongData or NULL on failure.
SongData *fetch_niche_song(void);
// Combine a song into a playlist given mood settings. Returns a new Playlist or NULL on failure.
Playlist *combine_with_mood_playlist(SongData *song, MoodSettings *mood);
// Free functions for cleanup
void free_mood_settings(MoodSettings *mood);
void free_filter_settings(FilterSettings *filters);
void free_song_data(SongData *song);
void free_playlist(Playlist *playlist);
Playlist *create_playlist(void);
#endif