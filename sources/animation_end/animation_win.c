/*
** EPITECH PROJECT, 2017
** animation_win.c
** File description:
** animation if we win
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "my.h"
#include "my_runner.h"

void super_sonic(s_window *window, game_object *spr, float limit)
{
	int offset = 75;
	int max_value = 2850;

	spr->clock_mov.time = sfClock_getElapsedTime(spr->clock_mov.clock);
	spr->clock_mov.seconds = spr->clock_mov.time.microseconds / 1000000.0;
	if (spr->clock_mov.seconds >= limit) {
		if (spr->rect.left < max_value)
			spr->rect.left += offset;
		else
			spr->rect.left = 1500;
		sfClock_restart(spr->clock_mov.clock);
	}
	sfSprite_setTextureRect(spr->sprite, spr->rect);
	sfRenderWindow_drawSprite(window->window, spr->sprite, NULL);
}

void display_win(global *data)
{
	s_window *window = &data->window;
	game_object **sprites = data->sprites;
	sfVector2f position1 = {.x = 150, .y = 100};
	sfVector2f position2 = {.x = 30, .y = 620};
	sfVector2f position3 = {.x = 450, .y = 700};
	sfVector2f position4 = {.x = 550, .y = 620};

	sfRenderWindow_clear(window->window, sfBlack);
	draw_back(sprites[BACK_BACK], window, 0);
	draw_back(sprites[BACK_MIDDLE], window, 0);
	draw_back(sprites[BACK_FRONT], window, 1);
	print_text(data, "Well Played", 100, position1);
	print_text(data, "Score", 50, position2);
	print_enter_alpha(data, position3, 40);
	print_text(data, "High Score", 50, position4);
	print_score(data, data->score, 290, 620);
	print_score(data, data->best_score, 1080, 620);
	super_sonic(window, sprites[SUPER_SONIC], 0.1);
	sfRenderWindow_display(window->window);
}

int animation_win(global *data)
{
	sfEvent event;
	int replay = 0;

	data->sprites[SUPER_SONIC]->clock_mov.clock = sfClock_create();
	sfMusic_play(data->music[WIN_S]->music);
	while (sfRenderWindow_isOpen(data->window.window) && replay == 0) {
		check_window_size(data->window.window);
		display_win(data);
		replay = analyse_events(data, event);
	}
	if (sfMusic_getStatus(data->music[WIN_S]->music) == sfPlaying)
		sfMusic_stop(data->music[WIN_S]->music);
	sfClock_destroy(data->sprites[SUPER_SONIC]->clock_mov.clock);
	data = re_initialisation(data);
	return (0);
}
