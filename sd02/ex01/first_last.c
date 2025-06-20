/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:38:12 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/20 11:38:14 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "first_last.h"

void first_last(int arr[], int size, int target, int *first, int *last)
{
	int i;

	i = 0;
	if (size < 0)
		return ;
	*first = -1;
	*last = -1;
	while (i < size)
	{
		if (arr[i] == target)
		{
			if (*first == -1)
				*first = i;
			*last = i;
		}
		i++;
	}
}

/* 
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		printf("Usage: %s target num1 num2 num3 ...\n", argv[0]);
		return (1);
	}

	int target = atoi(argv[1]);
	int size = argc - 2;
	int *arr = malloc(size * sizeof(int));
	if (!arr)
	{
		perror("malloc failed");
		return (1);
	}

	for (int i = 0; i < size; i++)
		arr[i] = atoi(argv[i + 2]);

	int first, last;
	first_last(arr, size, target, &first, &last);

	printf("First occurrence: %d\n", first);
	printf("Last occurrence: %d\n", last);

	free(arr);
	return (0);
} */