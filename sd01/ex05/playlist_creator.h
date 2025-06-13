/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playlist_creator.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:06:35 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/13 11:09:24 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYLIST_CREATOR_H
# define PLAYLIST_CREATOR_H

typedef struct s_song_data
{
    char *title;
    char *artist;
    int duration;
} SongData;

typedef struct s_playlist
{
    SongData **songs;
    int count;
} Playlist;

typedef struct s_mood_settings
{
    char *mood_type; // e.g., "happy", "sad", "energetic"
    int intensity;   // e.g., 1-10 scale
} MoodSettings;

typedef struct s_filter_settings
{
    int require_popular; // 1 for popular songs, 0 for niche
    int max_duration;    // Maximum total duration of the playlist
} FilterSettings;

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