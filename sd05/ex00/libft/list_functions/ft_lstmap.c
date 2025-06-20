/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:14:54 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/06/10 18:01:40 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Creates a new list by applying a
 * function to each element of an existing list.
 *
 * Applies the function 'f' to the content of each node in the list 'lst' and
 * creates a new list with the results. If node creation fails at any point,
 * frees the entire new list created so far using the 'del' function.
 *
 * @param lst Pointer to the first node of the original list.
 * @param f Function to apply to the content of each node.
 * @param del Function used to free the content of a node in case of failure.
 * @return t_list* Pointer to the newly created list, or NULL on failure.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*new_content;

	new_lst = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (new_node == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
/*void	del(void *content)
{
	if (content)
		free(content);
}
void	*f(void *content)
{
	int i = 0;
	char *str = (char *)content;
	char *final = ft_strdup(str);
	while (final[i])
	{
		final[i] -= 32;
		i++;
	}
	return (final);
}
int	main()
{
	t_list *node1 =ft_lstnew(ft_strdup("ciao"));
	t_list *node2 =ft_lstnew(ft_strdup("mondo"));
	t_list *node3 = ft_lstnew(ft_strdup("indiano"));
	node1->next = node2;
	node2->next = node3;
	t_list *new_list = ft_lstmap(node1, f, del);
	t_list	*temp = node1;
	while(temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	temp = new_list;
	while(temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
}*/
