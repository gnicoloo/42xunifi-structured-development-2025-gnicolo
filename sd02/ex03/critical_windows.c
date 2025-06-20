/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   critical_windows.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:53:03 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/06/20 11:38:36 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "critical_windows.h"

bool	ft_check_window(int i, const int *readings, int *valid_number, int *average)
{
	int j;

	j = 0;
	while (j < 5)
	{
		if (readings[i + j] > 150)
			return (true);
		if (readings[i + j] >= 70)
			(*valid_number)++;
		(*average) += readings[i + j];
		j++;
	}
	return (false);
}

int count_critical_windows(const int *readings, int size)
{
	int		i;
	int		average;
	int		valid_number;
	bool	invalid_n_detected;
	int		critical_w;

	i = 0;
	average = 0;
	invalid_n_detected = false;
	critical_w = 0;
	valid_number = 0;
	if (size <= 0)
		return (-1);
	while (i <= size - 5)
	{
		invalid_n_detected = ft_check_window(i, readings, &valid_number, &average);
		if (valid_number >= 3 && !invalid_n_detected)
			if (average / 5 >= 90)
				critical_w++;
		valid_number = 0;
		average = 0;
		i++;
	}
	return (critical_w);
}
/* 
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int size = argc - 1;
	int *readings = malloc(size * sizeof(int));
	if (!readings)
	{
		perror("malloc failed");
		return (1);
	}

	for (int i = 0; i < size; i++)
	{
		readings[i] = atoi(argv[i + 1]);
	}

	int result = count_critical_windows(readings, size);
	printf("Critical windows: %d\n", result);

	free(readings);
	return(0);
} */