/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_scheduler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:01:52 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/06/20 11:40:56 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "task_scheduler.h"

ScheduleResult *schedule_tasks(TaskList *tasks)
{
	TaskProfile *profile;
	PriorityMap *priorities;
	ScheduleResult *result;
	int core_count;
	int core_id;
	int task_id;

	profile = profile_tasks(tasks);
	if (!profile)
		return (NULL);	
	priorities = compute_priorities_mock(profile);
	if (!priorities)
	{
		free_task_profile(profile);
		return (NULL);
	}	
	core_count = get_available_core_count();
	result = create_schedule_result(core_count);
	if (!result)
	{
		free_priority_map(priorities);
		free_task_profile(profile);
		return (NULL);
	}
	core_id = 0;
	while (core_id < core_count)
	{
		task_id = select_best_task_for_current_priorities(profile, priorities);
		if (task_id == -1)
			break ;
		update_schedule_entry(result, core_id, task_id);
		core_id++;
	}	
	free_priority_map(priorities);
	free_task_profile(profile);
	return (result);
}

