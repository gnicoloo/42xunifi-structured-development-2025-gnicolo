/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recipe_generator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:00:42 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/13 11:04:33 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recipe_generator.h"
#include <stdlib.h>

Recipe *create_custom_recipe(void)
{
    Recipe *recipe = NULL;
    Ingredients *ingredients = get_current_ingredients();
    if (!ingredients)
        return (NULL);

    TasteProfile *taste = get_user_taste_profile();
    if (!taste)
        return (free_ingredients(ingredients), NULL);
    while (1)
    {
        recipe = create_recipe(ingredients, taste);
        if (!recipe)
            return (free_ingredients(ingredients), free_taste_profile(taste), NULL);
        if (get_user_approval(recipe))
            break;
        free_recipe(recipe);
    }
    free_ingredients(ingredients);
    free_taste_profile(taste);
    return (recipe);
}
