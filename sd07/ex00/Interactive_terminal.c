/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interactive_terminal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:41:37 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/21 16:24:29 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Library_Software.h"

void    ft_print_value(t_book *books)
{
    ft_printf(1, "ID: %s\nTitle: %s\nAuthor: %s\n", books->book_id, books->title, books->author);
}

void    ft_handle_terminal_input(t_book *books)
{
    char    *input;

    input = ft_strdup("");
    while (input[0] != '1' && input[0] != '2')
    {
        ft_printf(1, "Press 1 for searching books by title, otherwise press 2 for searching by authors\n");
        if (input)
            free(input);
        input = get_next_line(0);
        if (input && input[0] == '1')
        {
            free(input);
            search_books_by_title(books);
            return ;
        }
        else if (input && input[0] == '2')
        {
            free(input);
            search_books_by_author(books);
            return ;
        }
    }
}

int ft_strcasecmp(char *str1, char *str2)
{
    int i = 0;
    int result = -1;
    
    if (!str1 || ! str2)
        return (-1);
    char    *tmp1 = ft_strdup(str1);
    char    *tmp2 = ft_strdup(str2);
    if (!tmp1 || ! tmp2)
       return (-1);
    while (tmp1[i])
    {
        if (ft_isalpha(tmp1[i]))
            tmp1[i] = ft_tolower(tmp1[i]);
        i++;
    }
    i = 0;
    while (tmp2[i])
    {
        if (ft_isalpha(tmp2[i]))
           tmp2[i] = ft_tolower(tmp2[i]);
        i++;
    }
    result = ft_strcmp(tmp1, tmp2);
    return (free(tmp1), free(tmp2), result);
}

void    search_books_by_title(t_book *books)
{
    char    *line;
    t_book  *current = books;
    char    *tmp = NULL;

    line = get_next_line(0);
    if (!line)
        return ;
    while(line && !ft_strcmp(line, ""))
    {
        free(line);
        line = get_next_line(0);
    }
    tmp = ft_strtrim(line, "\n");
    free(line);
    while (tmp && current)
    {
        if (!ft_strcasecmp(tmp, current->title))
            ft_print_value(current);
        current = current->next_book;
    }
    if (tmp)
        free(tmp);
}

void    search_books_by_author(t_book *books)
{
    char    *line;
    t_book  *current = books;
    char    *tmp = NULL;

    line = get_next_line(0);
    if (!line)
        return ;
    while(line && !ft_strcmp(line, ""))
    {
        free(line);
        line = get_next_line(0);
    }
    tmp = ft_strtrim(line, "\n");
    free(line);
    while (tmp && current)
    {
        if (!ft_strcasecmp(tmp, current->author))
            ft_print_value(current);
        current = current->next_book;
    }
    if (tmp)
        free(tmp);
}


