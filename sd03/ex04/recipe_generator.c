/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recipe_generator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:40:27 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/20 11:40:28 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recipe_generator.h"

void	free_all_resources(Ingredients *fridge, TasteProfile *user_preference, Recipe *recipe)
{
	free_ingredients(fridge);
	free_taste_profile(user_preference);
	if (recipe)
		free_recipe(recipe);
}
Recipe	*find_user_approve(int *user_approval, Ingredients *fridge, Recipe *recipe, TasteProfile *user_preference)
{
	while (*user_approval != 1)
	{
		*user_approval = get_user_approval(recipe);
		if (*user_approval == 1)
		{
			free_all_resources(fridge, user_preference, NULL);
			return (recipe);
		}
		free_recipe(recipe);
		recipe = create_recipe(fridge, user_preference);
		if (!recipe)
		{
			free_all_resources(fridge, user_preference, NULL);
			return (NULL);
		}
	}
	return (NULL);
}
Recipe *create_custom_recipe(void)
{
	Ingredients	*fridge;
	TasteProfile	*user_preference;
	Recipe		*recipe;
	int			user_approval;

	user_approval = -1;
	recipe = NULL;
	user_preference = NULL;
	fridge = get_current_ingredients();
	if (!fridge)
		return (NULL);
	user_preference = get_user_taste_profile();
	if (!user_preference)
	{
		free_ingredients(fridge);
		return (NULL);
	}
	recipe = create_recipe(fridge, user_preference);
	if (!recipe)
	{
		free_all_resources(fridge, user_preference, NULL);
		return (NULL);
	}
	recipe = find_user_approve(&user_approval, fridge, recipe, user_preference);
	return (recipe);
}
