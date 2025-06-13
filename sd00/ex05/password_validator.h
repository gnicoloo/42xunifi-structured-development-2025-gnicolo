/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   password_validator.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 01:45:50 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/11 15:28:10 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PASSWORD_VALIDATOR_H
# define PASSWORD_VALIDATOR_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>


typedef enum status
{
	VALID,
	INVALID
}	PwStatus;
PwStatus validate_password(const char *new_pw, const char *curr_pw);

#endif