/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Movie_Watchlist.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:38:43 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/06/20 11:41:30 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVIEWATCHLIST_H
#define MOVIEWATCHLIST_H

#include <stddef.h>

typedef struct s_movie
{
	int			id;
	char		*title;
	char		*genre;
	int			watched;
	int			rating;
	char		*date_watched;
}               t_movie;

typedef struct s_movie_db
{
	t_movie		*movies[1000];
	size_t		count;
	int			max_id;
}               t_movie_db;


int     load_movies_from_file(const char *filename, t_movie_db *db);
int     save_movies_to_file(const char *filename, t_movie_db *db);

t_movie *create_movie(int id, const char *title, const char *genre,
                      int watched, int rating, const char *date_watched);
void    free_movie(t_movie *movie);

int     add_movie(t_movie_db *db, t_movie *movie);
int     delete_movie(t_movie_db *db, int id);
t_movie *find_movie_by_id(t_movie_db *db, int id);
void    update_movie(t_movie *movie, const char *title, const char *genre);
int     mark_movie_watched(t_movie *movie, int rating, const char *date_watched);

// Funzioni di ricerca e filtro
size_t  search_movies_by_title(t_movie_db *db, const char *substr, t_movie **results, size_t max_results);
size_t  search_movies_by_genre(t_movie_db *db, const char *substr, t_movie **results, size_t max_results);
size_t  filter_movies_by_watched(t_movie_db *db, int watched_flag, t_movie **results, size_t max_results);

// Funzioni di validazione campi
int     validate_id(int id, t_movie_db *db);
int     validate_title(const char *title);
int     validate_genre(const char *genre);
int     validate_watched_flag(int flag);
int     validate_rating(int rating, int watched_flag);
int     validate_date_watched(const char *date, int watched_flag);

// Funzione menu principale
void    movie_watchlist_menu(t_movie_db *db, const char *filename);

// Funzioni di statistiche
typedef struct s_stats
{
    size_t  total_movies;
    size_t  watched_count;
    size_t  unwatched_count;
    double  avg_rating_watched;
    // Per semplicità, si potrebbe aggiungere una struttura per il breakdown per genere
}               t_stats;

t_stats calculate_stats(t_movie_db *db);

#endif
