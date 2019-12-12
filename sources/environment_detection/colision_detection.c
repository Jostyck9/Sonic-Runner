/*
** EPITECH PROJECT, 2017
** colision_detection.c
** File description:
** all colision detections functions
*/

#include <SFML/Graphics.h>
#include "my_runner.h"
#include "my.h"

game_object *collision_ground(game_object *sonic, game_object **ground)
{
	int i = 0;
	sfFloatRect box_sonic;
	sfFloatRect box_ground;

	box_sonic = sfSprite_getGlobalBounds(sonic->sprite);
	box_sonic.top += 10;
	box_sonic.height -= 10;
	while (ground[i] != NULL) {
		box_ground = sfSprite_getGlobalBounds(ground[i]->sprite);
		if (sfFloatRect_intersects(&box_sonic, &box_ground, NULL))
			return (ground[i]);
		i += 1;
	}
	return (NULL);
}

int colision_right(sfFloatRect box_sonic, sfFloatRect box_ground)
{
	sfVector2f pos_right2;
	pos_right2.x = box_sonic.left + box_sonic.height - 30;
	pos_right2.y = box_sonic.top + box_sonic.width / 2;

	if (sfFloatRect_contains(&box_ground, pos_right2.x, pos_right2.y)) {
		return (1);
	}
	return (0);
}

int colision_top(sfFloatRect box_sonic, sfFloatRect box_ground)
{
	sfVector2f pos_top1 = {.x = box_sonic.width / 3, .y = 0};
	sfVector2f pos_top2 = {.x = box_sonic.width / 2, .y = 0};
	sfVector2f pos_top3 = {.x = box_sonic.width / 1.1, .y = 0};

	pos_top1.y = box_sonic.top + 10;
	pos_top2.y = box_sonic.top + 10;
	pos_top3.y = box_sonic.top + 10;
	if (sfFloatRect_contains(&box_ground, pos_top1.x, pos_top1.y)) {
		return (1);
	}
	if (sfFloatRect_contains(&box_ground, pos_top2.x, pos_top2.y)) {
		return (1);
	}
	if (sfFloatRect_contains(&box_ground, pos_top3.x, pos_top3.y)) {
		return (1);
	}
	return (0);
}

int colision_down(sfFloatRect box_sonic, sfFloatRect box_ground)
{
	sfVector2f pos_down1 = {.x = box_sonic.left, .y = 0};
	sfVector2f pos_down2 = {.x = box_sonic.left, .y = 0};
	sfVector2f pos_down3 = {.x = box_sonic.left, .y = 0};

	pos_down1.y = box_sonic.top + (box_sonic.width);
	pos_down2.y = box_sonic.top + (box_sonic.width / 2);
	pos_down3.y = box_sonic.top + (box_sonic.width / 1.1);
	if (sfFloatRect_contains(&box_ground, pos_down1.x, pos_down1.y)) {
		return (1);
	}
	if (sfFloatRect_contains(&box_ground, pos_down2.x, pos_down2.y)) {
		return (1);
	}
	if (sfFloatRect_contains(&box_ground, pos_down3.x, pos_down3.y)) {
		return (1);
	}
	return (0);
}

int precise_colision(game_object *sonic, game_object *ground)
{
	sfFloatRect box_sonic = sfSprite_getGlobalBounds(sonic->sprite);
	sfFloatRect box_ground = sfSprite_getGlobalBounds(ground->sprite);

	if (colision_right(box_sonic, box_ground) == 1) {
		return (COLISION_RIGHT);
	}
	if (colision_top(box_sonic, box_ground) == 1) {
		return (COLISION_UP);
	}
	if (colision_down(box_sonic, box_ground) == 1) {
		return (COLISION_DOWN);
	}
	return (0);
}
