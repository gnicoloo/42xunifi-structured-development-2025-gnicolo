/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   password_validator.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:38:59 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/20 11:39:01 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PASSWORD_VALIDATOR
# define PASSWORD_VALIDATOR

# include <stdbool.h>

typedef enum
{
	VALID,
	INVALID,
}	PwStatus;

PwStatus	validate_password(const char *new_pw, const char *curr_pw);
int			ft_strlen(const char *str);
bool		is_special(const char *str);
bool		check_digit_char(const char *str);
bool		check_lower_char(const char *str);
bool		check_upper_char(const char *str);
int			ft_strlen(const char *str);

#endif
