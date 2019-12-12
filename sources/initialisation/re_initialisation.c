/*
** EPITECH PROJECT, 2017
** re_initialisation.c
** File description:
** re-initialise the sprite to restart the level
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my.h"
#include "my_runner.h"

global *re_initialisation(global *data)
{
	game_object **ground = data->ground;
	game_object *sonic = data->sprites[SONIC];

	for (int i = 0; data->ground[i] != NULL; i++)
		sfSprite_setPosition(ground[i]->sprite, ground[i]->position);
	sfSprite_setPosition(sonic->sprite, sonic->position);
	sonic->offset.x = 0;
	sonic->offset.y = 0;
	data->score = 0;
	data->level = 1;
	return (data);
}
