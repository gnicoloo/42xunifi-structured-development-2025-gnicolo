/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segmented_runs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 00:17:12 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/11 18:51:37 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "segmented_runs.h"

int count_segments(const int *arr, int size)
{
	if (size <= 0)
		return 0;
	int count = 0;
	int i = 0;
	int curr_len = 1;
	int has_sequence = 0;
	while (i < size)
	{
		if (arr[i] == -1)
		{
			if (has_sequence)
				count++;
			curr_len = 1;
			has_sequence = 0;
			i++;
			continue;
		}
		if (i + 1 < size && arr[i + 1] != -1 && arr[i + 1] > arr[i])
		{
			curr_len++;
			if (curr_len >= 3)
				has_sequence = 1;
		}
		else
			curr_len = 1;
		i++;
	}
	if (has_sequence)
		count++;
	return (count);
}


// int main(void)
// {
// 	int arr[] = {2, 3, 4, -1, 5, 6, -1, 1, 2, 3, 4, -1, 2, 3 , 10};
// 	int size = sizeof(arr) / sizeof(arr[0]);

// 	int result = count_segments(arr, size);

// 	printf("Numero di segmenti con sequenza crescente di almeno 3 elementi: %d\n", result);
// 	return 0;
// }
