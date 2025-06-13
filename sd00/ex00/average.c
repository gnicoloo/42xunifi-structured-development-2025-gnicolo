/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   average.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 23:39:37 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/11 17:18:30 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "average.h"

float	average(const int *array, int size)
{
	int			valid_size;
	int			i;
	float		sum;

	sum = 0.0f;
	i = 0;
	valid_size = 0;
	if (size < 0)
		return (0);
	while (i < size)
	{
		if (array[i] >= 0 && array[i] <= 100)
		{	
			valid_size++;
			sum += array[i];
		}
		i++;
	}
	return ((float )sum / valid_size);
}
