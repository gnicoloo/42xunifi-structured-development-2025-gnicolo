/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   food_order.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:36:01 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/12 15:39:10 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOOD_ORDER_H
# define FOOD_ORDER_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

typedef struct s_OrderRequest
{
    char *restaurant_name;
    char *food_item;
    int quantity;
} OrderRequest;

typedef struct s_OrderConfirmation
{
    char *restaurant_name;
    char *food_item;
    int quantity;
    double total_price;
} OrderConfirmation;


// Checks if the restaurant is open based on the order. Returns 1 if open, 0 if closed.
int check_restaurant_status(OrderRequest *request);
// Creates a confirmation for an immediate order. Returns NULL on failure.
OrderConfirmation *create_standard_confirmation(void);
// Creates a confirmation for a future (pre-order). Returns NULL on failure.
OrderConfirmation *create_preorder_confirmation(void);
// Sends the confirmation to the user.
void send_confirmation_notification(OrderConfirmation *confirmation);
int process_food_order(OrderRequest *request);
#endif