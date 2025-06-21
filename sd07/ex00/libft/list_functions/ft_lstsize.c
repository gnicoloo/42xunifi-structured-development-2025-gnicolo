/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:42:13 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/05/20 15:01:41 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Counts the number of nodes in a linked list.
 *
 * Traverses the list starting from the node pointed to by 'lst' and counts
 * how many nodes are present until the end (NULL).
 *
 * @param lst Pointer to the first node of the list.
 * @return int Total number of nodes in the list.
 */
int	ft_lstsize(t_list *lst)
{
	int		count;

	count = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
/*void	printing_lst(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		printf("%s", (char *)tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
}

int	main()
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;


	node1 = ft_lstnew("ciao ");
	node2 = ft_lstnew("mondo");
	node3 = ft_lstnew("!!!!");
	ft_lstadd_front(&node3, node2);
	ft_lstadd_front(&node2, node1);
	printf("%d", ft_lstsize(node1));
	printf("\n");
	printing_lst(node1);

}*/
