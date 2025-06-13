/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recipe_generator.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnicolo <gnicolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:57:21 by gnicolo           #+#    #+#             */
/*   Updated: 2025/06/13 11:06:06 by gnicolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECIPE_GENERATOR_H
# define RECIPE_GENERATOR_H

typedef struct s_ingredient
{
} Ingredients;

typedef struct s_recipe
{
} Recipe;

typedef struct TasteProfile
{
} TasteProfile;


// Fetch current ingredients from fridge. Returns a new Ingredients* or NULL on failure.
Ingredients *get_current_ingredients(void);
// Fetch user taste profile. Returns a new TasteProfile* or NULL on failure.
TasteProfile *get_user_taste_profile(void);
//  Generate a new recipe candidate based on ingredients & taste. Returns a new Recipe* or NULL on
// failure.
Recipe *create_recipe(Ingredients *ingredients, struct TasteProfile *taste);
// Ask user approval for the given recipe. Returns 1 if approved, 0 otherwise.
int get_user_approval(Recipe *recipe);
// Free functions for cleanup:
void free_ingredients(Ingredients *ing);
void free_taste_profile(TasteProfile *tp);
void free_recipe(Recipe *recipe);

Recipe *create_custom_recipe(void);

#endif