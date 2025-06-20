/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workout_scheduler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <gpirozzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:56:09 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/06/12 19:15:49 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "workout_scheduler.h"

void	ft_free_all(UserData *user, WorkoutPlan *my_workout)
{
	free_user_data(user);
	free_workout_plan(my_workout);
}
WorkoutPlan *create_workout_schedule(char *username)
{
	UserData	*user;
	WorkoutPlan	*my_workout;
	int			i;

	i = 0;
	my_workout = NULL;
	user = get_user_data(username);
	if (!user)
		return (NULL);
	my_workout = build_base_plan(user);
	if (my_workout && user->preference)
			my_workout = refine_plan(my_workout, user);
	if (!my_workout)
	{
		free_user_data(user);
		return (NULL);
	}
	my_workout->workout_days = determine_duration(my_workout);
	if (my_workout->workout_days <= 0)
	{
		ft_free_all(user, my_workout);
		return (NULL);
	}
	while (i < my_workout->workout_days)
	{
		assign_daily_exercises(my_workout, i);
		assign_daily_tips(my_workout, i);
		i++;
	}
	free_user_data(user);
	return (my_workout);
}
