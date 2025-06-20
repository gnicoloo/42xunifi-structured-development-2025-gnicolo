/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:15:40 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/06/20 11:38:49 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILESYSTEM_H
# define FILESYSTEM_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef enum s_type_node
{
	FILE_,
	FOLDER,
}	t_type_node;

typedef struct s_FSNode FSNode;

typedef struct s_FSNode
{
	char		*name;
	int			size;
	t_type_node	type;
	FSNode		*child;
	FSNode		*sibling;
}	FSNode;

FSNode	*create_file(const char *name, int size);
FSNode	*create_folder(const char *name);
void	add_child(FSNode *parent, FSNode *child);
FSNode	*get_children(const FSNode *parent);
FSNode	*get_sibling(const FSNode *node);

#endif