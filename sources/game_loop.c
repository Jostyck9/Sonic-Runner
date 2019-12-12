/*
** EPITECH PROJECT, 2017
** game_loop.c
** File description:
** level1
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "my.h"
#include "my_runner.h"

void draw_back(game_object *back, s_window *window, int offset)
{
	if (back->rect.left >= back->rect.width)
		back->rect.left = 0;
	else
		back->rect.left += offset;
	sfSprite_setTextureRect(back->sprite, back->rect);
	sfRenderWindow_drawSprite(window->window, back->sprite, NULL);
}

void draw_ground(game_object **grnd, s_window *win, int speed)
{
	int i = 0;
	sfVector2f move = {.x = -speed, .y = 0};

	while (grnd[i] != NULL) {
		sfSprite_move(grnd[i]->sprite, move);
		sfRenderWindow_drawSprite(win->window, grnd[i]->sprite, NULL);
		i += 1;
	}
}

int draw_sprite_window(global *data, game_object **spr, game_object **ground)
{
	int colision_info = NONE;
	sfVector2f position = {.x = 10, .y = 30};

	check_window_size(data->window.window);
	sfRenderWindow_clear(data->window.window, sfBlack);
	draw_back(spr[BACK_BACK], &data->window, 1);
	draw_back(spr[BACK_MIDDLE], &data->window, 2);
	draw_back(spr[BACK_FRONT], &data->window, 3);
	colision_info = draw_sonic(spr, ground, &data->window, 0.1);
	draw_ground(ground, &data->window, 11);
	print_text(data, "Score", 50, position);
	print_score(data, data->score, 300, 30);
	if (colision_info == NONE)
		sfRenderWindow_display(data->window.window);
	return (colision_info);
}

int game_loop(global *data)
{
	sfEvent event;
	int colision_info = NONE;
	game_object **sprites = data->sprites;
	s_window *window = &data->window;

	sfMusic_play(data->music[GREEN_HILL]->music);
	sprites[SONIC]->clock_mov.clock = sfClock_create();
	while (sfRenderWindow_isOpen(window->window) && colision_info == NONE) {
		sprites[SONIC]->clock_mov.time = \
sfClock_getElapsedTime(sprites[SONIC]->clock_mov.clock);
		sprites[SONIC]->clock_mov.seconds = \
sprites[SONIC]->clock_mov.time.microseconds / 1000000.0;
		if (sprites[SONIC]->clock_mov.seconds >= 0.1)
			data->score += 1;
		colision_info = draw_sprite_window(data, sprites, data->ground);
		analyse_events(data, event);
	}
	sfMusic_stop(data->music[GREEN_HILL]->music);
	sfClock_destroy(sprites[SONIC]->clock_mov.clock);
	data->level = 2;
	return (colision_info);
}
