/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 23:41:54 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/11 15:24:18 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "first_last.h"

void first_last(int array[], int size, int target, int *first, int *last)
{
	int		i;

	i = 0;
	if (size <= 0)
		return;
	*first = -1;
	*last = -1;
	while (i < size)
	{
		if (array[i] == target)
		{
			*first = i;
			break;
		}
		i++;
	}
	i = size - 1;
	while (i != 0)
	{
		if (array[i] == target)
		{
			*last = i;
			break;
		}
		i--;
	}
}


// int main()
// {
//	int array[] = {5, 3, 7, 3, 2, 3, 9};
//	int size = sizeof(array) / sizeof(array[0]);
//	int target = 3;
//	int first, last;

//	first_last(array, size, target, &first, &last);

//	if (first != -1 && last != -1)
//		printf("Target %d found: first at index %d, last at index %d\n", target, first, last);
//	else 
//		printf("Target %d not found in the array.\n", target);
//	return (0);
// }
