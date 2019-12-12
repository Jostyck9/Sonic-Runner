/*
** EPITECH PROJECT, 2017
** creation_ground.c
** File description:
** convert the numbers into their relatives texture
*/

#include <stdlib.h>
#include "my.h"
#include "my_runner.h"

game_object **ground_map(game_object **ground, int *nbr_stru, sfVector2i pos)
{
	sfIntRect rect = {.left = 0, .top = 0, .width = 100, .height = 100};
	sfVector2f scale_ground = {.x = 1, .y = 1};
	sfVector2f pos_sprite;

	pos_sprite.x = 100 * pos.x;
	pos_sprite.y = 100 * pos.y;
	ground[*nbr_stru] = create_object("assets/ground.png", pos_sprite, \
rect, scale_ground);
	if (ground[*nbr_stru] != NULL) {
		ground[*nbr_stru]->type = GROUND;
		ground[*nbr_stru]->position = pos_sprite;
	}
	*nbr_stru += 1;
	return (ground);
}

game_object **pike_map(game_object **ground, int *nbr_stru, sfVector2i pos)
{
	sfIntRect rect = {.left = 0, .top = 0, .width = 100, .height = 100};
	sfVector2f scale_pike = {.x = 1, .y = 0.6};
	sfVector2f pos_sprite;

	pos_sprite.x = 100 * pos.x;
	pos_sprite.y = 100 * pos.y + 40;
	ground[*nbr_stru] = create_object("assets/pike.png", pos_sprite, \
rect, scale_pike);
	if (ground[*nbr_stru] != NULL) {
		ground[*nbr_stru]->type = PIKE;
		ground[*nbr_stru]->position = pos_sprite;
	}
	*nbr_stru += 1;
	return (ground);
}

game_object **flag_map(game_object **ground, int *nbr_stru, sfVector2i pos)
{
	sfIntRect rect = {.left = 0, .top = 0, .width = 100, .height = 130};
	sfVector2f scale_flag = {.x = 1, .y = 1};
	sfVector2f pos_sprite;

	pos_sprite.x = 100 * pos.x;
	pos_sprite.y = 100 * pos.y;
	ground[*nbr_stru] = create_object("assets/flag.png", pos_sprite, \
rect, scale_flag);
	if (ground[*nbr_stru] != NULL) {
		ground[*nbr_stru]->type = FLAG;
		ground[*nbr_stru]->position = pos_sprite;
	}
	*nbr_stru += 1;
	return (ground);
}
