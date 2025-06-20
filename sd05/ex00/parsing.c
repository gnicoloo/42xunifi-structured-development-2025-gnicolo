/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:42:10 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/20 11:42:11 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Library_Software.h"


bool	ft_check_file(char *filename)
{
	int i;

	i = 0;
	if (!filename)
		return false;
	if (ft_strncmp(filename + (ft_strlen(filename) - 4), ".csv", 4) == 0)
		return true;
	return false;
}

void    data_init(t_book *books)
{
	books->book_id = NULL;
	books->title = NULL;
	books->author = NULL;
}

bool	ft_fill_books(t_book *books, char **splitted_line)
{
	char	*tmp = NULL;
	for (int i = 0; i < 3; i++)
	{
		tmp = ft_strtrim(splitted_line[i], "\n");
		if (i == 0)
			books->book_id = ft_strdup (tmp);
		if (i == 1)
			books->title = ft_strdup (tmp);
		if (i == 2)
			books->author = ft_strdup (tmp);
		free(tmp);
	}
	if (!books->book_id || !books->title || !books->author)
		return (ft_free_all(books), false);
	return true;
}

int		load_and_fill_catalogue(int fd, t_book *books)
{
	char		*line;
	static int	added_books = 0;
	char		**splitted_line = NULL;
	int			count_line = 0;
	t_book		*current = books;

    line = get_next_line(fd);
	if (!line)
		return 0;
	while (line && added_books < 1000)
	{
		splitted_line = ft_get_books_value(line);
		if (!splitted_line)
			ft_printf(2, "Warning: Bad line at index: %d\n", count_line);
		else
		{
			append_node(books);
			ft_fill_books(current, splitted_line);
			current = current->next_book;
			added_books++;
		}
		count_line++;
		free(line);
		line = get_next_line(fd);
		if (splitted_line)
			ft_free_matrix(splitted_line);
    }
	return 1;
}


