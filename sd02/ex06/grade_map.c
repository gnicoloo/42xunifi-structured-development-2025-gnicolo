/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grade_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:39:05 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/20 11:39:09 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grade_map.h"

// Plusminus
const char *A  = "A+";
const char *A1 = "A";
const char *A2 = "A-";
const char *B  = "B+";
const char *B1 = "B";
const char *B2 = "B-";
const char *C  = "C+";
const char *C1 = "C";
const char *C2 = "C-";
const char *D  = "D+";
const char *D1 = "D";
const char *D2 = "D-";
const char *F  = "F";

// Standard
const char *A3 = "A";
const char *B3 = "B";
const char *C3 = "C";
const char *D3 = "D";

// Pass/Fail
const char *P = "P";

void	ft_plusminus_mapper(const int scores, const char **mapped_grades)
{
	if (scores >= 97)
		*mapped_grades = A;
	else if (scores >= 93)
		*mapped_grades = A1;
	else if (scores >= 90)
		*mapped_grades = A2;
	else if (scores >= 87)
		*mapped_grades = B;
	else if (scores >= 83)
		*mapped_grades = B1;
	else if (scores >= 80)
		*mapped_grades = B2;
	else if (scores >= 77)
		*mapped_grades = C;
	else if (scores >= 73)
		*mapped_grades = C1;
	else if (scores >= 70)
		*mapped_grades = C2;
	else if (scores >= 67)
		*mapped_grades = D;
	else if (scores >= 63)
		*mapped_grades = D1;
	else if (scores >= 60)
		*mapped_grades = D2;
	else if (scores >= 0)
		*mapped_grades = F;
	else
		return ;
}

void	ft_passfail_mapper(const int scores, const char **mapped_grades)
{
	if (scores >= 60)
		*mapped_grades = P;
	else if (scores >= 0)
		*mapped_grades = F;
}

void	ft_standard_mapper(const int scores, const char **mapped_grades)
{
	if (scores >= 90)
		*mapped_grades = A3;
	else if (scores >= 80)
		*mapped_grades = B3;
	else if (scores >= 70)
		*mapped_grades = C3;
	else if (scores >= 60)
		*mapped_grades = D3;
	else if (scores >= 0)
		*mapped_grades = F;
}

void map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (mapper == PLUSMINUS)
			ft_plusminus_mapper(scores[i], &mapped_grades[i]);
		else if (mapper == PASSFAIL)
			ft_passfail_mapper(scores[i], &mapped_grades[i]);
		else if (mapper == STANDARD)
			ft_standard_mapper(scores[i], &mapped_grades[i]);
		else
			return ;
		i++;
	}
}

/* #include <stdio.h>

int main(void)
{
	int scores[] = {100, 95, 89, 76, 62, 50};
	int size = sizeof(scores) / sizeof(scores[0]);
	const char *mapped[size];

	printf("Mappatura PLUSMINUS:\n");
	map_scores(scores, size, PLUSMINUS, mapped);
	for (int i = 0; i < size; i++)
		printf("Score: %d => Grade: %s\n", scores[i], mapped[i]);

	printf("\nMappatura STANDARD:\n");
	map_scores(scores, size, STANDARD, mapped);
	for (int i = 0; i < size; i++)
		printf("Score: %d => Grade: %s\n", scores[i], mapped[i]);

	printf("\nMappatura PASSFAIL:\n");
	map_scores(scores, size, PASSFAIL, mapped);
	for (int i = 0; i < size; i++)
		printf("Score: %d => Grade: %s\n", scores[i], mapped[i]);

	return 0;
} */
