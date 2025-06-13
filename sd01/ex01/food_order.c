/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   food_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:35:51 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/12 15:43:15 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "food_order.h"

int process_food_order(OrderRequest *request)
{
    OrderConfirmation *confirmation;
    
    if (!request || !request->restaurant_name || !request->food_item || request->quantity <= 0)
        return (-1);
    confirmation = NULL;
    if(check_restaurant_status(request) == 0)
    {
        confirmation = create_preorder_confirmation();
        if (!confirmation)
            return (-1);
    }
    else
    {
        confirmation = create_standard_confirmation();
        if (!confirmation)
            return (-1);
    }
    return (send_confirmation_notification(confirmation), 0);
}