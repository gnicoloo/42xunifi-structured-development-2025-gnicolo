/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   password_validator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 01:48:01 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/11 17:15:05 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "password_validator.h"

int ft_is_special_char(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '@' || str[i] == '#' || str[i] == '$' || str[i] == '%' ||
			str[i] == '^' || str[i] == '&' || str[i] == '*')
			return (1);
		i++;
	}
	return (-1);
}


int ft_is_lowercase(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			return (1);
		i++;
	}
	return (-1);
}
int ft_is_uppercase(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			return (1);
		i++;
	}
	return (-1);
}
int ft_is_digit(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (1);
		i++;
	}
	return (-1);
}

int ft_strlenksks(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
		i++;
	if (i < 8)
		return (-1);
	return (i);
}

int ft_strcmp(const char *s1, const char *s2)
{
	int i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

PwStatus validate_password(const char *new_pw, const char *curr_pw)
{
	PwStatus status;

	
	if (ft_is_digit((char *)new_pw) == -1 ||
		ft_is_lowercase((char *)new_pw) == -1 ||
		ft_is_uppercase((char *)new_pw) == -1 ||
		ft_is_special_char((char *)new_pw) == -1 ||
		ft_strlenksks((char *)new_pw) == -1 || ft_strcmp((char *)new_pw, (char *)curr_pw) == 0)
	{
		return (INVALID);
	}
	return (VALID);
}