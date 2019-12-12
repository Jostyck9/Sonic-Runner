/*
** EPITECH PROJECT, 2017
** fall_detection.c
** File description:
** detect if sonic fall under the screen
*/

#include <SFML/Graphics.h>
#include "my_runner.h"

int fall_detection(game_object **sprites)
{
	sfVector2f position;

	position = sfSprite_getPosition(sprites[SONIC]->sprite);
	if (position.y > SCREEN_HEIGHT)
		return (1);
	return (0);
}
