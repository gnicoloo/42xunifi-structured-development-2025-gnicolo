/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:09:27 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/06/10 18:02:57 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Frees a NULL-terminated matrix of strings.
 *
 * Iterates over each string in the matrix, frees it,
 * and sets the pointer to NULL.
 * Finally, frees the matrix itself and sets its pointer to NULL.
 *
 * @param matrix The NULL-terminated matrix of strings to free.
 */
void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (matrix)
	{
		while (matrix[i] != NULL)
		{
			free(matrix[i]);
			matrix[i] = NULL;
			i++;
		}
		free(matrix);
		matrix = NULL;
	}
}
