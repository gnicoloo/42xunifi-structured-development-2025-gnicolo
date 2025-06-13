/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movie_planner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:11:06 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/12 16:32:17 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movie_planner.h"
void ft_free_preferences(Preferences *prefs)
{
    if (prefs)
    {
        if (prefs->genre)
        {
            free(prefs->genre);
            prefs->genre = NULL;
        }
        free(prefs);
    }
}
void ft_free_list(MovieList *list)
{
	MovieList *temp;
    
	while (list)
	{
		temp = list;
		list = list->next;
		if (temp->movies)
		{
			for (size_t i = 0; i < temp->count; i++)
			{
				if (temp->movies[i].title)
					free(temp->movies[i].title);
				if (temp->movies[i].genre)
					free(temp->movies[i].genre);
			}
			free(temp->movies);
		}
		free(temp);
	}
}
Plan *create_movie_night_plan(void)
{
	Preferences *pref_user;
	MovieList *movie_list;
	Plan *plan;
      
	pref_user = get_user_preferences();
	if (!pref_user)
		return (NULL);
	movie_list = find_movies(pref_user);
	if (!movie_list) 
		return (ft_free_preferences(pref_user), NULL);
	plan = build_plan(movie_list);
	if (!plan)
		return (ft_free_preferences(pref_user), ft_free_list(movie_list), NULL);
	return (plan);
}