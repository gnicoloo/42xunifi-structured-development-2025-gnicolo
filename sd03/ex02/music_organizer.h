/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music_organizer.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:40:06 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/20 11:40:08 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUSIC_ORGANIZER_H
# define MUSIC_ORGANIZER_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_MusicFile
{
	char	*song_name;
	char	*artist;
	float	song_time;
}	MusicFile;

typedef struct s_MusicLibrary
{
	MusicFile		**songs;
}	MusicLibrary;

// Creates and returns a new music library. Returns NULL on fail
MusicLibrary		*create_music_library();
// Scans a directory for music files. Returns a NULL terminated array of filenames.
const char			**scan_directory(const char *directory_path);
// Processes a single music file. Returns a data structure representing the processed file.
MusicFile			*process_music_file(const char *directory_path, const char *filename);
// Updates the music library with the processed music file information.
void				update_music_library(MusicLibrary *library, MusicFile *song);

MusicLibrary *organize_music_library(const char *directory_path);
void	ft_free_library(MusicLibrary *library);
void	ft_free_matrix(char **matrix);

#endif