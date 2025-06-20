/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movie_planner.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:39:27 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/20 11:39:29 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVIE_PLANNER_H
# define MOVIE_PLANNER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef enum e_genre
{
	ACTION,
	ADVENTURE,
	COMEDY,
	CRIME,
	DRAMA,
	FANTASY,
	HISTORICAL,
	HORROR,
	MYSTERY,
	ROMANCE,
	SCIFI,
	THRILLER,
	WESTERN,
	WAR,
	MUSICAL,
	DOCUMENTARY,
	ANIMATION,
	BIOGRAPHICAL,
	FAMILY,
	SPORT,
	GENRE_COUNT
} genre;

typedef struct	s_Movielist MovieList;

typedef struct	s_Movielist
{
	char		*title;
	int			duration_min;
	float			rating;
	int			year;
	genre		type_film;
	MovieList	*next_film;
}	MovieList;

typedef struct	s_preference
{
	int			duration_min;
	float			rating;
	genre		type_film_to_find;
}	Preferences;

typedef struct	s_Plan
{
	MovieList	*Movie_set;
}	Plan;

// Returns user preferences. Returns NULL on failure.
Preferences	*get_user_preferences(void);
// Returns a list of movies matching the given preferences. Returns NULL on failure.
MovieList	*find_movies(Preferences *prefs);
// Returns a movie night plan from the given list. Returns NULL on failure.
Plan	*build_plan(MovieList *list);

void	free_all(MovieList *film_list, Plan *plan);
Plan	*create_movie_night_plan(void);


#endif