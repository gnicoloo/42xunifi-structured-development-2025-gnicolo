/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:50:09 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/06/21 16:43:51 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Library_Software.h"

void    ft_free_all(t_book *books)
{
    if (books->title)
        free(books->title);
    if (books->author)
        free(books->author);
    if (books)
        free(books);
}

t_book  *create_book(char *id, const char *title, const char *author)
{
    t_book *books;

    books = malloc(sizeof (t_book));
    if (!books || !id || !title || !author)
        return NULL;
    data_init(books);
    return (books);
}

bool    ft_check_id(char *id_str)
{
    int i = 0;

    while (id_str[i] && id_str[i] != '\n')
    {
        if (!ft_isdigit(id_str[i]))
            return (false);
        i++;
    }
    return (true);
}

bool    ft_check_title(char *title)
{
    int i = 0;

    if (!title)
        return (false);
    while (title[i] && title[i] != '\n')
    {
        if (title[0] == ' ' || title[0] == '\t')
            return (false);
        if ((title[i] == ' ' || title[i] == '\t') && (title[i + 1] == ' ' || title[i + 1] == '\t'))
            return (false);
        i++;
    }
    if (title[i - 1] == ' ' && title[i - 1] == '\t')
        return (false);
    return (true);
}

bool    ft_check_author(char *author)
{
    int i = 0;

    while (author[i] && author[i] != '\n')
    {
        if (!ft_isalpha(author[0]))
            return (false);
        if (!ft_isalpha(author[i]) && author[i] != '.' && author[i] != ' ' && author[i] != '\t')
            return (false);
        if (author[i] == ' ' && (author[i + 1] == ' ' || author[i + 1] == '\t'))
            return (false);
        i++;
    }
    return (true);
}
int ft_check_list(char **line_matrix)
{
    if (!line_matrix || !line_matrix[0] || !line_matrix[1] || !line_matrix[2])
        return (ft_free_matrix(line_matrix), 0);
    if (!ft_check_id(line_matrix[0]) || !ft_check_title(line_matrix[1]) || !ft_check_author(line_matrix[2]))
        return (ft_free_matrix(line_matrix), 0);
    return 1;
}

void ft_iter_trim(char **line_matrix)
{
	int i;

	i = 0;
	while (line_matrix[i])
	{
		char *temp = ft_strtrim(line_matrix[i], " \t\n");
		free(line_matrix[i]);
		line_matrix[i] = temp;
		i++;
	}
}

char    **ft_get_books_value(const char *line)
{
    
    char    **line_matrix;

    line_matrix = ft_split(line, ',');
	if (!line_matrix)
		return NULL;
	if (ft_matrix_len(line_matrix) != 3)
		return (ft_free_matrix(line_matrix), NULL);
	line_matrix[3] = NULL;
	ft_iter_trim(line_matrix);
	if (!ft_check_id(line_matrix[0]))
		return (ft_free_matrix(line_matrix), NULL);
	if (!ft_check_title(line_matrix[1]))
		return (ft_free_matrix(line_matrix), NULL);
	if (!ft_check_author(line_matrix[2]))
		return (ft_free_matrix(line_matrix), NULL);
    return (line_matrix);
}
