/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segmented_runs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:54:51 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/06/20 11:38:26 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "segmented_runs.h"

int count_segments(const int *arr, int size)
{
	int i;
	int validator_segment;
	int count_valid_segment;

	i = 0;
	validator_segment = 0;
	count_valid_segment = 0;
	if (!arr || size <= 0)
		return (-1);
	while (i < size)
	{
		while (i < size && arr[i] != -1)
		{
			if ((i + 1 < size) && arr[i] < arr[i + 1])
				validator_segment++;
			if (validator_segment >= 2)
			{
				count_valid_segment++;
				break;
			}
			i++;
		}
		validator_segment = 0;
		i++;
	}
	return (count_valid_segment);
}
/* #include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Usage: %s num1 num2 ... (use -1 as segment separator)\n", argv[0]);
		return (1);
	}

	int size = argc - 1;
	int *arr = malloc(size * sizeof(int));
	if (!arr)
	{
		perror("malloc failed");
		return (1);
	}

	for (int i = 0; i < size; i++)
		arr[i] = atoi(argv[i + 1]);

	int result = count_segments(arr, size);
	printf("Valid segments: %d\n", result);

	free(arr);
	return (0);
} */
