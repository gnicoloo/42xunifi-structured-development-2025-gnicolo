/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music_organizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:44:54 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/12 16:41:07 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "music_organizer.h"

void ft_free_all(MusicLibrary *library, const char **filenames)
{
	int i;

	if (library)
	{
		if (library->files)
		{
			for (i = 0; i < library->count; i++)
			{
				if (library->files[i].title)
					free(library->files[i].title);
				if (library->files[i].artist)
					free(library->files[i].artist);
				if (library->files[i].album)
					free(library->files[i].album);
			}
			free(library->files);
		}
		free(library);
	}
	if (filenames)
	{
		for (i = 0; filenames[i]; i++)
			free((char *)filenames[i]);
		free((void *)filenames);
	}
}

MusicLibrary *organize_music_library(const char *directory_path)
{
	MusicLibrary	*library;
	const char		**filenames;
	int				i;
	MusicFile		*song;

	i = 0;
	if (!directory_path || !*directory_path)
		return (NULL);
	library = create_music_library();
	if (!library)
		return (NULL);
	filenames = scan_directory(directory_path);
	if (!filenames) 
		return (free(library), NULL);
    while (filenames[i])
	{
		song = process_music_file(directory_path, filenames[i]);
		if (!song)
			return (ft_free_all(library, filenames), NULL);
		update_music_library(library, song);
		i++;
	}
}