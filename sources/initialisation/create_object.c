/*
** EPITECH PROJECT, 2017
** create_object.c
** File description:
** create a game_object
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my_runner.h"
#include "graphical.h"

struct game_object *create_object(const char *path_to_spritesheet, \
sfVector2f pos, sfIntRect rect, sfVector2f scale)
{
	game_object *object = NULL;

	object = malloc(sizeof(*object));
	if (object == NULL)
		return (object);
	object->texture = sfTexture_createFromFile(path_to_spritesheet, NULL);
	if (!object->texture) {
		free(object);
		return (NULL);
	}
	object->sprite = sfSprite_create();
	if (!object->sprite) {
		destroy_object(object);
		return (NULL);
	}
	object->rect = rect;
	sfSprite_setTexture(object->sprite, object->texture, sfTrue);
	sfSprite_setScale(object->sprite, scale);
	sfSprite_setPosition(object->sprite, pos);
	sfSprite_setTextureRect(object->sprite, rect);
	return (object);
}
