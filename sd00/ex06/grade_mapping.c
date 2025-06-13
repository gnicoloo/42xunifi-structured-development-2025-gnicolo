/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grade_mapping.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:54:54 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/11 19:10:10 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grade_mapping.h"

void ft_plusminus_map(int *score, int size,const char **mapped_grade)
{
    int i = 0;
    while ( i < size)
    {
        if (score[i] >= 97)
            mapped_grade[i] = "A+";
        else if (score[i] >= 93)
            mapped_grade[i] = "A";
        else if (score[i] >= 90)
            mapped_grade[i] = "A-";
        else if (score[i] >= 87)
            mapped_grade[i] = "B+";
        else if (score[i] >= 83)
            mapped_grade[i] = "B";
        else if (score[i] >= 80)
            mapped_grade[i] = "B-";
        else if (score[i] >= 77)
            mapped_grade[i] = "C+";
        else if (score[i] >= 73)
            mapped_grade[i] = "C";
        else if (score[i] >= 70)
            mapped_grade[i] = "C-";
        else if (score[i] >= 67)
            mapped_grade[i] = "D+";
        else if (score[i] >= 63)
            mapped_grade[i] = "D";
        else if (score[i] >= 60)
            mapped_grade[i] = "D-";
        else
            mapped_grade[i] = "F";
        i++;
    }
}

void ft_standard_map(int *score, int size,const char **mapped_grade)
{
    int i = 0;
    while (i < size)
    {
        if (score[i] >= 90)
            mapped_grade[i] = "A";
        else if (score[i] >= 80)
            mapped_grade[i] = "B";
        else if (score[i] >= 70)
            mapped_grade[i] = "C";
        else if (score[i] >= 60)
            mapped_grade[i] = "D";
        else
            mapped_grade[i] = "F";
        i++;
    }
}
void ft_passfail_map(int *score, int size,const char **mapped_grade)
{
    int i = 0;
    while (i < size)
    {
        if (score[i] >= 60)
            mapped_grade[i] = "P";
        else
            mapped_grade[i] = "F";
        i++;
    }
}

void map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades)
{
    if (!scores || size <= 0 || !mapped_grades)
        return;

    if (mapper == PLUSMINUS)
        ft_plusminus_map((int *)scores, size, mapped_grades);
    else if (mapper == STANDARD)
        ft_standard_map((int *)scores, size, mapped_grades);
    else if (mapper == PASS_FAIL)
        ft_passfail_map((int *)scores, size, mapped_grades);
    else
        return;
}
