/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filters.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:44:36 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/06/20 11:41:18 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILTERS_H
# define FILTERS_H

# include <stdbool.h>
# include "expense.h"

typedef enum s_filter_type
{
	DATE_FILTER,
	RANGE_DATE_FILTER,
	CATEGORY_FILTER,
}	t_filter_type;

typedef struct s_filters
{
	t_filter_type	filter_type;
	char			*category_filter;
	char			*start_date;
	char			*end_date;
}	t_filters;

/* ───── Funzioni di filtro specifiche ───── */

/**
 * Ritorna una nuova lista con tutte le spese (senza filtro).
 */
t_expense_list	*filter_all(const t_expense_list *list);

/**
 * Ritorna una nuova lista contenente solo le spese con categoria contenente la sottostringa (case-insensitive).
 */
t_expense_list	*filter_by_category(const t_expense_list *list, const char *category_substring);

/**
 * Ritorna una nuova lista contenente solo le spese con data compresa nell’intervallo [start_date, end_date].
 */
t_expense_list	*filter_by_date_range(const t_expense_list *list, const char *start_date, const char *end_date);

/* ───── Funzione principale che chiama la giusta funzione ───── */

t_expense_list	*filter_expenses(const t_expense_list *list, const t_filters *filter);

/* ───── Funzioni helper ───── */

/**
 * Restituisce true se 'category' contiene la sottostringa 'substr' (case-insensitive).
 */
bool	category_contains(const char *category, const char *substr);

/**
 * Restituisce true se 'date' è compresa tra 'start' e 'end' (incluse).
 */
bool	date_between(const char *date, const char *start, const char *end);

#endif