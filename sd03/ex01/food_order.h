/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   food_order.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:39:44 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/20 11:39:46 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOOD_ORDER_H
# define FOOD_ORDER_H

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_OrderRequest
{
	char	*restaurant;
	char	*ordered_food;
	int		quantity;
}	OrderRequest;

typedef struct	s_OrderConfirmation
{
	float	order_id;
	float	time_of_the_day;
	char	*message;
}	OrderConfirmation;

// Checks if the restaurant is open based on the order. Returns 1 if open, 0 if closed.
int check_restaurant_status(OrderRequest *request);
// Creates a confirmation for an immediate order. Returns NULL on failure.
OrderConfirmation *create_standard_confirmation(void);
// Creates a confirmation for a future (pre-order). Returns NULL on failure.
OrderConfirmation *create_preorder_confirmation(void);
// Sends the confirmation to the user.
void send_confirmation_notification(OrderConfirmation *confirmation);

int process_food_order(OrderRequest *request);
void	free_request(OrderRequest *request);
void	free_all(OrderRequest *request, OrderConfirmation *confirmation);

#endif