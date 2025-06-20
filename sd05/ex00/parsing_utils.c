/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:50:09 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/06/20 11:42:06 by gnicolo          ###   ########.fr       */
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
    return books;
}

bool    ft_check_id(char *id_str)
{
    int i = 0;

    while (id_str[i] && id_str[i] != '\n')
    {
        if (!ft_isdigit(id_str[i]))
            return false;
        i++;
    }
    return true;
}

bool    ft_check_title(char *title)
{
    int i = 0;

    if (!title)
        return false;
    while (title[i] && title[i] != '\n')
    {
        if (title[0] == ' ' || title[0] == '\t')
            return false;
        if ((title[i] == ' ' || title[i] == '\t') && (title[i + 1] == ' ' || title[i + 1] == '\t'))
            return false;
        i++;
    }
    if (title[i - 1] == ' ' && title[i - 1] == '\t')
        return false;
    return true;
}

bool    ft_check_author(char *author)
{
    int i = 0;

    while (author[i] && author[i] != '\n')
    {
        if (!ft_isalpha(author[0]))
            return false;
        if (!ft_isalpha(author[i]) && author[i] != '.' && author[i] != ' ' && author[i] != '\t')
            return false;
        if (author[i] == ' ' && (author[i + 1] == ' ' || author[i + 1] == '\t'))
            return false;
        i++;
    }
    return true;
}

char    **ft_get_books_value(const char *line)
{
    
    char    **line_matrix = ft_split(line, ',');
    int     matrix_len = ft_matrix_len(line_matrix);
    int     i = 0;

    if (!line_matrix)
        return NULL;
    if (matrix_len != 3)
    {
        ft_free_matrix(line_matrix);
        return NULL;
    }
    while (line_matrix[i])
    {
        if (i == 0)
        {
            if (!ft_check_id(line_matrix[i]))
                return (ft_free_matrix(line_matrix), NULL);
        }
        else if (i == 1)
        {
            if (!ft_check_title(line_matrix[i]))
                return (ft_free_matrix(line_matrix), NULL);
        }
        else if (i == 2)
        {
            if (!ft_check_author(line_matrix[i]))
                return (ft_free_matrix(line_matrix), NULL);
        }
        i++;
    }
    return line_matrix;
}
