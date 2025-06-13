/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   critical_windows.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 00:53:15 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/12 14:35:05 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "critical_windows.h"
int average(const int *array, int size)
{
	int	sum;

	sum = 0;
	if (size < 0)
		return (0);
	for (int i = 0; i < size; i++)
		sum += array[i];
	return (sum / size);
}

int is_critical(const int *window)
{
	int count_70_or_more;
	int i;

	count_70_or_more = 0;
	i = 0;
	while( i < 5)
	{
		if (window[i] >= 70)
			count_70_or_more++;
		i++;
	}
	if (count_70_or_more < 3)
		return (0);
	if (average(window, 5) < 90)
		return (0);
	return (1); 
}
int contains_over_150(const int *arr, int size)
{
	int i;
	
	i = 0;
	if (size < 0)
		return (-1);
	while(i < size)
	{
		if (arr[i] >= 150)
			return (-1);
		i++;
	}
	return (0);
}

int count_critical_windows(const int *readings, int size)
{
	int count;
	int i;

	i = 0;	
	if (size < 0)
		return (-1);
	count = contains_over_150(readings, size);
	if (count == -1)
		return (-1);
	while (i <= size - 5)
	{
		if (is_critical(&readings[i]))
		{
			count++;
			// i += 4; per unire che non si conti la stessa finestra più volte
		}
		i++;
	}
	return (count);
}

// int main(int argc, char **argv)
// {
//     int size = argc - 1;
//     int *readings = malloc(size * sizeof(int));
//     if (!readings)
//     {
//         fprintf(stderr, "Error: malloc failed\n");
//         return 1;
//     }

//     for (int i = 0; i < size; i++)
//     {
//         readings[i] = atoi(argv[i + 1]);
//     }

//     int count = count_critical_windows(readings, size);
//     printf("Number of critical windows: %d\n", count);

//     free(readings);
//     return 0;
// }
