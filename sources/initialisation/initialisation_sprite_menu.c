/*
** EPITECH PROJECT, 2017
** initialisation_sprite_menu.c
** File description:
** initialise all the sprites needed for the menu
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my.h"
#include "my_runner.h"

game_object **initialisation_sonic_menu(game_object **sprites)
{
	sfVector2f pos = {490, 62};
	sfVector2f sca = {3, 3};
	sfIntRect rect = {.left = 0, .top = 0, .width = 100, .height = 80};

	sprites[SONIC_MENU] = create_object("assets/title.png", pos, rect, sca);
	if (sprites[SONIC_MENU] == NULL)
		return (destroy_all_sprites(sprites));
	return (sprites);
}

game_object **initialisation_cadre(game_object **sprites)
{
	sfVector2f pos = {180, 60};
	sfVector2f sca = {3, 3};
	sfIntRect rect = {.left = 0, .top = 80, .width = 300, .height = 160};

	sprites[CADRE] = create_object("assets/title.png", pos, rect, sca);
	if (sprites[CADRE] == NULL)
		return (destroy_all_sprites(sprites));
	return (sprites);
}

game_object **initialisation_sprites_menu(game_object **sprites)
{
	if (initialisation_sonic_menu(sprites) == NULL)
		return (NULL);
	initialisation_cadre(sprites);
	return (sprites);
}
