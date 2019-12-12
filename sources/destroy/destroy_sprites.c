/*
** EPITECH PROJECT, 2017
** destroy_sprites.c
** File description:
** destroy all the sprites needed
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my.h"
#include "my_runner.h"

game_object **destroy_sonic(game_object **sprites)
{
	destroy_object(sprites[SONIC]);
	destroy_object(sprites[SUPER_SONIC]);
	destroy_object(sprites[SONIC_MENU]);
	destroy_object(sprites[CADRE]);
	return (sprites);
}

game_object **destroy_back(game_object **sprites)
{
	destroy_object(sprites[BACK_FRONT]);
	destroy_object(sprites[BACK_MIDDLE]);
	destroy_object(sprites[BACK_BACK]);
	return (sprites);
}

game_object **destroy_ground(game_object **ground)
{
	int i = 0;

	if (ground == NULL || !ground)
		return (NULL);
	while (ground[i] && ground[i] != NULL) {
		destroy_object(ground[i]);
		i += 1;
	}
	free(ground);
	ground = NULL;
	return (ground);
}

game_object **destroy_ground2(game_object **sprites)
{
	destroy_object(sprites[GROUND]);
	return (sprites);
}

game_object **destroy_all_sprites(game_object **sprites)
{
	game_object **empty = NULL;

	if (!sprites || sprites == NULL)
		return (empty);
	destroy_ground2(sprites);
	destroy_back(sprites);
	destroy_sonic(sprites);
	free(sprites);
	return (empty);
}
