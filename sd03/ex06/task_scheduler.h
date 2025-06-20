/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_scheduler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:02:08 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/06/20 11:41:00 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TASK_SCHEDULER
# define TASK_SCHEDULER

# include <stdlib.h>

typedef struct s_TaskList
{

}	TaskList;

typedef struct s_TaskProfile
{

}	TaskProfile;

typedef struct s_PriorityMap
{

}	PriorityMap;

typedef struct s_ScheduleResult
{

}	ScheduleResult;

typedef struct s_LoadInfo
{

}	LoadInfo;
// Analyze task load and I/O behavior. Returns a new TaskProfile or NULL on failure.
TaskProfile *profile_tasks(TaskList *tasks);
// Compute a priority map from task profiling. Returns a new PriorityMap or NULL on failure.
PriorityMap *compute_priorities_mock(TaskProfile *profile);
// Return the number of available CPU cores.
int get_available_core_count(void);
// Select the best task to assign next based on the profile. Returns a task ID or -1 on failure.
int select_best_task_for_current_priorities(TaskProfile *profile,PriorityMap *priorities);
// Create a ScheduleResult re for the specified number of cores. Returns NULL on failure.
ScheduleResult *create_schedule_result(int core_count);
// Update the result schedule with a task assignment.
void update_schedule_entry(ScheduleResult *result, int core_id, int task_id);
// Free functions for cleanup
void free_task_profile(TaskProfile *profile);
void free_priority_map(PriorityMap *priorities);
void free_loadinfo(LoadInfo *load);
ScheduleResult *schedule_tasks(TaskList *tasks);
#endif