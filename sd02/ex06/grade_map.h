/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grade_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:39:12 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/20 11:39:13 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADE_MAP_H
# define GRADE_MAP_H

//PLUSMINUS MAPPER
extern const char *A;
extern const char *A1;
extern const char *A2;
extern const char *B;
extern const char *B1;
extern const char *B2;
extern const char *C;
extern const char *C1;
extern const char *C2;
extern const char *D;
extern const char *D1;
extern const char *D2;
extern const char *F;
//STANDARD MAPPER
extern const char *A3;
extern const char *B3;
extern const char *C3;
extern const char *D3;
//PASSFAIL MAPPER
extern const char *P;

typedef	enum	s_GradeMapper
{
	PLUSMINUS,
	PASSFAIL,
	STANDARD,
}	GradeMapper;

void map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades);
void	ft_standard_mapper(const int scores, const char **mapped_grades);
void	ft_passfail_mapper(const int scores, const char **mapped_grades);
void	ft_plusminus_mapper(const int scores, const char **mapped_grades);

#endif