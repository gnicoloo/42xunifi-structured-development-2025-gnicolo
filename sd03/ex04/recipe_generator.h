/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recipe_generator.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:40:35 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/20 11:40:36 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECIPE_GENERATOR_H
# define RECIPE_GENERATOR_H

#include <unistd.h>
#include <stdlib.h>

typedef struct	s_Ingredients
{
	char	**items;
	int		count_items;
}	Ingredients;

typedef struct	s_Recipe
{
	char	*name;
	char	*how_to_prepare;
	char	**used_items;
	float	cooking_time;
	int		match_score;
}	Recipe;

typedef struct	s_TasteProfile
{
	char	**liked_items;
	char	**disliked_items;
	char	*diet_tipe;
	int		preference_score;
}	TasteProfile;

// Fetch current ingredients from fridge. Returns a new Ingredients* or NULL on failure.
Ingredients *get_current_ingredients(void);
// Fetch user taste profile. Returns a new TasteProfile* or NULL on failure.
TasteProfile *get_user_taste_profile(void);
// Generate a new recipe candidate based on ingredients & taste. Returns a new Recipe* or NULL on
//failure.
Recipe *create_recipe(Ingredients *ingredients, TasteProfile *taste);
// Ask user approval for the given recipe. Returns 1 if approved, 0 otherwise.
int get_user_approval(Recipe *recipe);
// Free functions for cleanup:
void free_ingredients(Ingredients *ing);
void free_taste_profile(TasteProfile *tp);
void free_recipe(Recipe *recipe);
void free_all_resources(Ingredients *fridge, TasteProfile *user_preference, Recipe *recipe);
Recipe *create_custom_recipe(void);
#endif