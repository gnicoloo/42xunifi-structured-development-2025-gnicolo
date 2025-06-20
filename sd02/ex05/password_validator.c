/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   password_validator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:38:53 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/20 11:38:56 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "password_validator.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
		i++;
	return (i);
}

bool	check_upper_char(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (false);
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			return (true);
		i++;
	}
	return (false);
}

bool	check_lower_char(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (false);
	while (str[i])
	{
		if (str[i] >= 97 && str[i] <= 122)
			return (true);
		i++;
	}
	return (false);
}

bool	check_digit_char(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (false);
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			return (true);
		i++;
	}
	return (false);
}

bool	is_special(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (false);
	while (str[i])
	{
		if (str[i] == '@' || str[i] == '#' || str[i] == '$' 
			|| str[i] == '%' || str[i] == '^' || str[i] == '&' || str[i] == '*')
			return (true);
		i++;
	}
	return (false);
}

bool	ft_strcmp(const char *new_pw, const char *curr_pw)
{
	int i;

	i = 0;
	while (new_pw[i] && curr_pw[i])
	{
		if (new_pw[i] != curr_pw[i])
			return (true);
		i++;
	}
	if (new_pw[i] || curr_pw[i])
		return true;
	return (false);
}
PwStatus	validate_password(const char *new_pw, const char *curr_pw)
{
	int	new_len;

	new_len = 0;
	if (!new_pw || !curr_pw)
		return (INVALID);
	new_len = ft_strlen(new_pw);
	if (new_len < 8 || !check_upper_char(new_pw) 
		|| !check_lower_char(new_pw) || !check_digit_char(new_pw)
			|| !is_special(new_pw) || !ft_strcmp(new_pw, curr_pw))
		return (INVALID);
	return (VALID);
}
