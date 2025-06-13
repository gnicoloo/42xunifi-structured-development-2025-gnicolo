/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workout_scheduler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:43:52 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/12 18:56:35 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "workout_scheduler.h"

// UserData *get_user_data(char *username);
// // Build a base WorkoutPlan from raw user data. Returns NULL on failure.
// WorkoutPlan *build_base_plan(UserData *data);
// // Optionally refine an existing plan. Returns the same pointer (or a new one) or NULL on failure.
// WorkoutPlan *refine_plan(WorkoutPlan *plan, UserData *data);
// // Determine how many days the workout schedule should span. Returns positive int, or <=0 on failure.
// int determine_duration(WorkoutPlan *plan);
// // Assign daily exercises for the next day into the plan.
// void assign_daily_exercises(WorkoutPlan *plan, int day);
// // Assign daily tips for the next day into the plan.
// void assign_daily_tips(WorkoutPlan *plan, int day);
// // Free functions for cleanup.
// void free_user_data(UserData *data);
// void free_workout_plan(WorkoutPlan *plan);

WorkoutPlan *create_workout_schedule(char *username)
{
	UserData		*user_data;
	WorkoutPlan		*plan;

	user_data = get_user_data(username);
	if (!user_data)
		return (NULL);
	plan = build_base_plan(user_data);
	if (!plan)
		return (free_user_data(user_data), NULL);
	plan = refine_plan(plan, user_data);
	if (!plan)
		return (free_user_data(user_data), NULL);
	plan->days = determine_duration(plan);
	if (plan->days <= 0)
		return (free_workout_plan(plan), free_user_data(user_data), NULL);
	assign_daily_exercises(plan, plan->days);
	assign_daily_tips(plan, plan->days);
	free_user_data(user_data);
	return (plan);
}
