/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movie_planner.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:10:58 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/12 15:48:18 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVIE_PLANNER_H
# define MOVIE_PLANNER_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

typedef struct s_Preferences
{
    char *genre;
    int min_rating;
    int max_duration;
} Preferences;

typedef struct s_Movie
{
	char *title;
	char *genre;
	int rating;
	int duration;
} Movie;

typedef struct s_MovieList
{
	Movie *movies;
	size_t count;
	MovieList *next;
} MovieList;

typedef struct s_Plan
{
	Movie *movie;
	char *date;
	char *time;
} Plan;

//  Returns user preferences. Returns NULL on failure.
Preferences *get_user_preferences(void);
// Returns a list of movies matching the given preferences. Returns NULL on failure.
MovieList *find_movies(Preferences *prefs);
// Returns a movie night plan from the given list. Returns NULL on failure.
Plan *build_plan(MovieList *list);
Plan *create_movie_night_plan(void);

#endif