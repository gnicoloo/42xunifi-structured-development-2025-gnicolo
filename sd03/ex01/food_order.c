/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   food_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:39:33 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/20 11:39:35 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "food_order.h"

void	free_all(OrderRequest *request, OrderConfirmation *confirmation)
{
	free_request(request);
	if (confirmation)
	{
		free(confirmation->message);
		free(confirmation);
	}
}

void	free_request(OrderRequest *request)
{
	if (request->ordered_food)
		free(request->ordered_food);
	if (request->restaurant)
		free(request->restaurant);
	free(request);
}

int	process_food_order(OrderRequest *request)
{
	OrderConfirmation	*confirmation;
	int					open_restaurant;

	confirmation = NULL;
	open_restaurant = 0;
	if (!request || !request->ordered_food || !request->quantity)
		return (-1);
	open_restaurant = check_restaurant_status(request);
	if (open_restaurant == 1)
		confirmation = create_standard_confirmation();
	else if (open_restaurant == 0)
		confirmation = create_preorder_confirmation();
	else
		return (-1);
	if (!confirmation)
	{
		free_request(request);
		return (-1);
	}
	send_confirmation_notification(confirmation);
	free_all(request, confirmation);
	return (open_restaurant);
}