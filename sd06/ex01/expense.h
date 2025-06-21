/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expense.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:36:16 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/06/20 11:41:14 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPENSE_H
# define EXPENSE_H

# include <stdbool.h>

typedef struct s_expense {
	char	*date;         // formato: "YYYY-MM-DD"
	float	amount;        // > 0
	char	*category;     // stringa dinamica
	char	*description;  // stringa dinamica
} t_expense;

// Lista dinamica di spese
typedef struct s_expense_list {
	t_expense	*items;     // array dinamico di spese
	int			count;      // numero di spese attualmente memorizzate
	int			capacity;   // capacità allocata
} t_expense_list;

/* ─── Funzioni di validazione ─────────────────────────────── */
bool	check_date_format(const char *date);
bool	check_amount_format(float amount);

/* ─── Gestione lista dinamica ─────────────────────────────── */
t_expense_list	*create_expense_list(int initial_capacity);
int				add_expense(t_expense_list *list, t_expense e);
void			free_expense_list(t_expense_list *list);

/* ─── Utilità ─────────────────────────────────────────────── */
void	print_warning(const char *message, int errcode);
#endif
