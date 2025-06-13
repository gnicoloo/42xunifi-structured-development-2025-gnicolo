/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:20:09 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/11 17:31:31 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILESYSTEM_H
# define FILESYSTEM_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef enum e_FSNodeType
{
	FS_FILE,
	FS_DIRECTORY
}	FSNodeType;

typedef struct s_FSNode	FSNode;

typedef struct s_FSNode
{
    char		*name;
    int			size;
	FSNodeType	type;
    FSNode		*child;
    FSNode		*sibling;
}	FSNode;

FSNode		*create_file(const char *name, int size);
FSNode		*create_folder(const char *name);
void		add_child(FSNode *parent, FSNode *child);
FSNode		*get_children(const FSNode *parent);
FSNode		*get_sibling(const FSNode *node);

#endif