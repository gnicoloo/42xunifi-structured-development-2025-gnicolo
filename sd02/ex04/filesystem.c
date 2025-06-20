/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:23:55 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/06/20 11:38:45 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filesystem.h"

FSNode	*create_file(const char *name, int size)
{
	FSNode	*new_file;

	new_file = NULL;
	if (!name || size <= 0)
		return (NULL);
	new_file = malloc(sizeof(FSNode));
	if (!new_file)
		return (NULL);
	new_file->name = strdup(name);
	if (!new_file->name)
		return (/* free(new_file),  */NULL);
	new_file->child = NULL;
	new_file->sibling = NULL;
	new_file->type = FILE_;
	new_file->size = size;
	return (new_file);
}

FSNode	*create_folder(const char *name)
{
	FSNode	*new_folder;

	new_folder = NULL;
	if (!name)
		return (NULL);
	new_folder = malloc(sizeof(FSNode));
	if (!new_folder)
		return (NULL);
	new_folder->name = strdup(name);
	if (!new_folder->name)
		return (/* free(new_folder),  */NULL);
	new_folder->child = NULL;
	new_folder->sibling = NULL;
	new_folder->type = FOLDER;
	new_folder->size = 0;
	return (new_folder);
}

void	add_child(FSNode *parent, FSNode *child)
{
	FSNode	*head;

	if (!parent || parent->type != FOLDER || !child)
		return ;
	head = parent;
	if (!parent->child)
		parent->child = child;
	while (head->sibling)
		head = head->sibling;
	if (!head->child)
		head->child = child;
	else
		head->sibling = child;
}

FSNode	*get_children(const FSNode *parent)
{
	if (!parent || parent->type != FILE_)
		return (NULL);
	return (parent->child);
}

FSNode	*get_sibling(const FSNode *node)
{
	if (!node || node->type != FILE_)
		return (NULL);
	return (node->sibling);
}