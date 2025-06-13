/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   average.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 23:38:22 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/10 23:39:34 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVERAGE_H
# define AVERAGE_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>


float	average(const int *array, int size);

# endif