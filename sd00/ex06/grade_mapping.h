/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grade_mapping.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:55:06 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/11 19:09:53 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADE_MAPPING_H
# define GRADE_MAPPING_H


# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <unistd.h>
typedef enum e_GradeMapper
{
    PLUSMINUS,
    STANDARD,
    PASS_FAIL,
} GradeMapper;

void map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades);

#endif