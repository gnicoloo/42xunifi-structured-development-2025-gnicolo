/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:41:59 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/20 11:42:00 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Library_Software.h"

int	list_len(t_book *books)
{
	int	len;

	len = 0;
	if (!books)
		return (0);
	while (books)
	{
		len++;
		books = books->next_book;
	}
	return (len);
}

t_book	*find_last_node(t_book *book)
{
	if (!book)
		return (NULL);
	while (book->next_book)
		book = book->next_book;
	return (book);
}

void	append_node (t_book *book)
{
    t_book	*node;
    t_book	*last_node;

	if (!book)
		return ;
	node = ft_calloc(sizeof (t_book), 1);
	if (!node)
		return ;
    data_init(node);
    node->next_book = NULL;
	if (!(book))
		book = node;
	else
	{
		last_node = find_last_node(book);
		last_node->next_book = node;
	}
}

void	free_stack(t_book *books)
{
	t_book	*tmp;
	t_book	*current;

	if (!books)
		return ;
	current = books;
	while (current)
	{
		tmp = current->next_book;
        ft_free_all(current);
		current = tmp;
	}
	books = NULL;
}