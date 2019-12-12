/*
** EPITECH PROJECT, 2017
** destroy_object.c
** File description:
** destroy an object
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my_runner.h"
#include "my.h"

void destroy_object(game_object *obj)
{
	if (obj == NULL)
		return;
	if (obj->texture)
		sfTexture_destroy(obj->texture);
	if (obj->sprite)
		sfSprite_destroy(obj->sprite);
	free(obj);
}
