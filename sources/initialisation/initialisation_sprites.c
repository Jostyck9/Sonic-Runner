/*
** EPITECH PROJECT, 2017
** initialisation_sprites.c
** File description:
** initialise all the sprites needed
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my.h"
#include "my_runner.h"

game_object *initialisation_back(int type, char *filepath, sfVector2f position)
{
	sfIntRect rect = {.left = 0, .top = 0, .width = 511, .height = 255};
	sfVector2f scale = {.x = 3, .y = 3};
	game_object *back = NULL;

	back = create_object(filepath, position, rect, scale);
	if (back == NULL) {
		free(back);
		return (NULL);
	}
	back->type = type;
	sfTexture_setRepeated(back->texture, sfTrue);
	return (back);
}

game_object **initialisation_all_back(game_object **sprites)
{
	sfVector2f position = {0, 0};

	sprites[BACK_BACK] = initialisation_back(BACK_BACK, \
"assets/background.png", position);
	if (sprites[BACK_BACK] == NULL)
		return (destroy_all_sprites(sprites));
	position.y += 40;
	sprites[BACK_MIDDLE] = initialisation_back(BACK_MIDDLE, \
"assets/middleground_trees.png", position);
	if (sprites[BACK_MIDDLE] == NULL)
		return (destroy_all_sprites(sprites));
	position.y -= 5;
	sprites[BACK_FRONT] = initialisation_back(BACK_FRONT, \
"assets/font_ground_sea.png", position);
	if (sprites[BACK_FRONT] == NULL)
		return (destroy_all_sprites(sprites));
	return (sprites);
}

game_object **initialisation_sonic(game_object **sprites)
{
	sfVector2f pos = {40, 400};
	sfVector2f scale = {2, 2};
	sfIntRect rect = {.left = 0, .top = 0, .width = 50, .height = 55};
	sfVector2f pos1 = {480, 200};
	sfIntRect rect1 = {.left = 0, .top = 0, .width = 75, .height = 87};
	sfVector2f scale1 = {4, 4};

	sprites[SONIC] = create_object("assets/sonic.png", pos, rect, scale);
	if (sprites[SONIC] == NULL)
		return (destroy_all_sprites(sprites));
	sprites[SONIC]->type = SONIC;
	sprites[SONIC]->offset.x = 0;
	sprites[SONIC]->offset.y = 0;
	sprites[SUPER_SONIC] = create_object("assets/super_sonic.png", \
pos1, rect1, scale1);
	if (sprites[SUPER_SONIC] == NULL)
		return (destroy_all_sprites(sprites));
	sprites[SONIC]->position = pos;
	sprites[SONIC]->type = SUPER_SONIC;
	sprites = initialisation_sprites_menu(sprites);
	return (sprites);
}

game_object **initialisation_ground(game_object **sprites)
{
	sfVector2f pos = {100, 700};
	sfVector2f scale = {1, 1};
	sfIntRect rect = {.left = 0, .top = 0, .width = 100, .height = 0};

	rect.height = SCREEN_WIDTH;
	sprites[GROUND] = create_object("assets/ground.png", pos, rect, scale);
	if (sprites[GROUND] == NULL)
		return (destroy_all_sprites(sprites));
	sprites[GROUND]->type = GROUND;
	sfTexture_setRepeated(sprites[GROUND]->texture, sfTrue);
	return (sprites);
}

game_object **initialise_all_sprites(void)
{
	game_object **sprites = NULL;

	sprites = malloc(sizeof(*sprites) * 8);
	if (sprites == NULL)
		return (sprites);
	sprites[BACK_BACK] = NULL;
	sprites[BACK_MIDDLE] = NULL;
	sprites[BACK_FRONT] = NULL;
	sprites[SONIC] = NULL;
	sprites[SUPER_SONIC] = NULL;
	sprites[SONIC_MENU] = NULL;
	sprites[CADRE] = NULL;
	sprites[GROUND] = NULL;
	sprites = initialisation_all_back(sprites);
	if (sprites == NULL)
		return (sprites);
	sprites = initialisation_ground(sprites);
	if (sprites == NULL)
		return (sprites);
	return (initialisation_sonic(sprites));
}
