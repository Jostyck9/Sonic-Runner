/*
** EPITECH PROJECT, 2017
** animation_sonic.c
** File description:
** all animation for sonic, including the movement
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my.h"
#include "my_runner.h"

int change_y_origin(game_object *sonic, game_object *ground)
{
	int colision = 0;
	int y = 0;
	sfFloatRect box_ground;
	sfFloatRect box_sonic;

	colision = precise_colision(sonic, ground);
	box_ground = sfSprite_getGlobalBounds(ground->sprite);
	box_sonic = sfSprite_getGlobalBounds(sonic->sprite);
	if (colision == COLISION_UP) {
		y = box_ground.top + box_ground.width - 10;
		return (y);
	}
	if (colision == COLISION_DOWN) {
		y = box_ground.top - box_sonic.width;
		return (y);
	}
	if (colision == COLISION_RIGHT)
		return (0);
	return (box_sonic.top);
}

int move_sonic(game_object **sprites, game_object **ground)
{
	sfFloatRect box_sonic;
	sfVector2f origin;
	game_object *current = NULL;

	sfSprite_move(sprites[SONIC]->sprite, sprites[SONIC]->offset);
	box_sonic = sfSprite_getGlobalBounds(sprites[SONIC]->sprite);
	if ((current = collision_ground(sprites[SONIC], ground)) == NULL) {
		sprites[SONIC]->offset.y += 1.5;
	} else {
		if (current->type == FLAG)
			return (WIN);
		else if (current->type == PIKE)
			return (LOOSE);
		origin.x = box_sonic.left;
		origin.y = change_y_origin(sprites[SONIC], current);
		if (origin.y == 0)
			return (LOOSE);
		sfSprite_setPosition(sprites[SONIC]->sprite, origin);
		sprites[SONIC]->offset.y = 0;
	}
	return (NONE);
}

void jump_animation(game_object **sprites)
{
	int offset = 50;
	int max_value = 400;

	if (sprites[SONIC]->rect.top != 55) {
		sprites[SONIC]->rect.top = 55;
		sprites[SONIC]->rect.left = 0;
	}
	if (sprites[SONIC]->rect.left < max_value)
		sprites[SONIC]->rect.left += offset;
	else
		sprites[SONIC]->rect.left = 0;
}

void run_animation(game_object **sprites)
{
	int offset = 50;
	int max_value = 1500;

	if (sprites[SONIC]->rect.top != 0) {
		sprites[SONIC]->rect.top = 0;
		sprites[SONIC]->rect.left = 1250;
	}
	if (sprites[SONIC]->rect.left < max_value)
		sprites[SONIC]->rect.left += offset;
	else
		sprites[SONIC]->rect.left = 1250;
}

int draw_sonic(game_object **sprites, game_object **ground, \
s_window *window, float limit)
{
	int colision_type = NONE;
	sfVector2f box_sonic;

	sprites[SONIC]->clock_mov.time = sfClock_getElapsedTime\
(sprites[SONIC]->clock_mov.clock);
	sprites[SONIC]->clock_mov.seconds = \
sprites[SONIC]->clock_mov.time.microseconds / 1000000.0;
	if (sprites[SONIC]->clock_mov.seconds >= limit) {
		if (collision_ground(sprites[SONIC], ground) == NULL)
			jump_animation(sprites);
		else
			run_animation(sprites);
		sfClock_restart(sprites[SONIC]->clock_mov.clock);
	}
	sfSprite_setTextureRect(sprites[SONIC]->sprite, sprites[SONIC]->rect);
	colision_type = move_sonic(sprites, ground);
	sfRenderWindow_drawSprite(window->window, sprites[SONIC]->sprite, NULL);
	box_sonic = sfSprite_getPosition(sprites[SONIC]->sprite);
	if ((box_sonic.y) > SCREEN_HEIGHT)
		return (LOOSE);
	return (colision_type);
}
