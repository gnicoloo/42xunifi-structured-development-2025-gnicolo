/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:19:48 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/11 17:41:20 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filesystem.h"

FSNode		*get_children(const FSNode *parent)
{
	if (!parent || parent->type != FS_DIRECTORY)
		return (NULL);
	return (parent->child);
}

FSNode    *get_sibling(const FSNode *node)
{
	if (!node || !node->sibling)
		return (NULL);
	return (node->sibling);
}

FSNode		*create_folder(const char *name)
{
	FSNode	*folder;

	if (!name || !*name)
		return (NULL);
	folder = (FSNode *)malloc(sizeof(FSNode));
	if (!folder)
		return (NULL);
	folder->name = strdup(name);
	folder->size = 0;
	folder->type = FS_DIRECTORY;
	folder->child = NULL;
	folder->sibling = NULL;
	return (folder);
}

FSNode		*create_file(const char *name, int size)
{
	FSNode	*file;

	if (!name || !*name || size < 0)
		return (NULL);
	file = (FSNode *)malloc(sizeof(FSNode));
	if (!file)
		return (NULL);
	file->name = strdup(name);
	file->size = size;
	file->type = FS_FILE;
	file->child = NULL;
	file->sibling = NULL;
	return (file);
}

void		add_child(FSNode *parent, FSNode *child)
{
	if (!parent || !child || parent->type != FS_DIRECTORY)
		return;
	if (parent->child == NULL)
		parent->child = child;
	else
	{
		FSNode *current = parent->child;
		while (current->sibling != NULL)
			current = current->sibling;
		current->sibling = child;
	}
}