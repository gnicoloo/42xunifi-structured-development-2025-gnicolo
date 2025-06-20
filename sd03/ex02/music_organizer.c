/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music_organizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:39:56 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/20 11:39:57 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "music_organizer.h"

void	free_all(MusicLibrary *library, char **matrix)
{
	ft_free_matrix(matrix);
	ft_free_library(library);
}

void	ft_free_library(MusicLibrary *library)
{
	int	i;

	i = 0;
	while (library->songs[i])
	{
		free(library->songs[i]->artist);
		free(library->songs[i]->song_name);
		free(library->songs[i]);
		i++;
	}
	free(library);
}

void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
}

MusicLibrary	*organize_music_library(const char *directory_path)
{
	char		**songs_files;
	MusicLibrary	*library;
	int				i;

	i = 0;
	library = NULL;
	songs_files = scan_directory(directory_path);
	if (!songs_files)
		return (NULL);
	library = create_music_library();
	if (!library)
		return (ft_free_matrix(songs_files), NULL);
	while (songs_files[i])
	{
		library->songs[i] = process_music_file(directory_path, songs_files[i]);
		if (!library->songs[i])
		{
			free_all(library, songs_files);
			return ( NULL);
		}
		update_music_library(library, library->songs[i]);
		i++;
	}
	ft_free_matrix(songs_files);
	return (library);
}