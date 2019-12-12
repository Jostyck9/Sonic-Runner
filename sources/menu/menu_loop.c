/*
** EPITECH PROJECT, 2017
** menu_loop.c
** File description:
** the game loop for the start menu
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my.h"
#include "my_runner.h"

float animation_menu(s_window *window, game_object *spr, float limit)
{
	int offset = 100;
	int max_value = 700;

	spr->clock_mov.time = sfClock_getElapsedTime(spr->clock_mov.clock);
	spr->clock_mov.seconds = spr->clock_mov.time.microseconds / 1000000.0;
	if (spr->clock_mov.seconds >= limit) {
		if (spr->rect.left < max_value)
			spr->rect.left += offset;
		else {
			spr->rect.left = 600;
			limit = 0.5;
		}
		sfClock_restart(spr->clock_mov.clock);
	}
	sfSprite_setTextureRect(spr->sprite, spr->rect);
	sfRenderWindow_drawSprite(window->window, spr->sprite, NULL);
	return (limit);
}

float display_menu(global *data, game_object **sprites, float limit)
{
	sfVector2f position2 = {.x = 10, .y = SCREEN_HEIGHT - 40};
	sfVector2f position3 = {.x = 400, .y = 550};
	sfVector2f position4 = {.x = 420, .y = 650};

	sfRenderWindow_clear(data->window.window, sfBlack);
	draw_back(sprites[BACK_BACK], &data->window, 0);
	draw_back(sprites[BACK_MIDDLE], &data->window, 0);
	draw_back(sprites[BACK_FRONT], &data->window, 1);
	sfRenderWindow_drawSprite(data->window.window, \
sprites[CADRE]->sprite, NULL);
	limit = animation_menu(&data->window, sprites[SONIC_MENU], limit);
	print_text(data, "To quit use Escape", 30, position2);
	print_text(data, "High Score", 40, position3);
	print_score(data, data->best_score, 800, 540);
	print_enter_alpha(data, position4, 40);
	sfRenderWindow_display(data->window.window);
	return (limit);
}

void menu_loop(global *data)
{
	float limit = 0.2;
	int replay = 0;
	game_object **sprites = data->sprites;
	sfEvent event;

	sfMusic_play(data->music[MENU]->music);
	sprites[SONIC_MENU]->clock_mov.clock = sfClock_create();
	while (sfRenderWindow_isOpen(data->window.window) && replay == 0) {
		check_window_size(data->window.window);
		limit = display_menu(data, sprites, limit);
		replay = analyse_events(data, event);
	}
	if (sfMusic_getStatus(data->music[MENU]->music) == sfPlaying)
		sfMusic_stop(data->music[MENU]->music);
	sfClock_destroy(sprites[SONIC_MENU]->clock_mov.clock);
	data->level = 1;
	data->sprites[SONIC_MENU]->rect.left = 0;
}
