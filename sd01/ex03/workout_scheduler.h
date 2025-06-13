/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workout_scheduler.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:44:00 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/12 18:52:22 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKOUT_SCHEDULER_H
# define WORKOUT_SCHEDULER_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

typedef struct s_Exercise
{
    char		*name;
    int			sets;
    int			repetitions;
} Exercise;

typedef struct s_WorkoutPlan
{
    Exercise	*exercises;
	char		*tips;
    int			days;
    int			repetitions;
} WorkoutPlan;

typedef struct s_UserData
{
    char		*username;
    int			age;
    int			weight;
    int			height;
    int			fitness_level;
} UserData;

// Returns a new UserData (mocked). Returns NULL on failure.
UserData *get_user_data(char *username);
// Build a base WorkoutPlan from raw user data. Returns NULL on failure.
WorkoutPlan *build_base_plan(UserData *data);
// Optionally refine an existing plan. Returns the same pointer (or a new one) or NULL on failure.
WorkoutPlan *refine_plan(WorkoutPlan *plan, UserData *data);
// Determine how many days the workout schedule should span. Returns positive int, or <=0 on failure.
int determine_duration(WorkoutPlan *plan);
// Assign daily exercises for the next day into the plan.
void assign_daily_exercises(WorkoutPlan *plan, int day);
// Assign daily tips for the next day into the plan.
void assign_daily_tips(WorkoutPlan *plan, int day);
// Free functions for cleanup.
void free_user_data(UserData *data);
void free_workout_plan(WorkoutPlan *plan);

WorkoutPlan *create_workout_schedule(char *username);

#endif