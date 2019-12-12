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

void move_sonic_death(game_object *sonic)
{
	float gravity = 0.1;

	sfSprite_move(sonic->sprite, sonic->offset);
	sonic->offset.y += gravity;
}

int death_sonic(s_window *window, game_object *spr, int movement, float limit)
{
	spr->clock_mov.time = sfClock_getElapsedTime(spr->clock_mov.clock);
	spr->clock_mov.seconds = spr->clock_mov.time.microseconds / 1000000.0;
	if (spr->clock_mov.seconds >= limit) {
		if (spr->rect.left < 150)
			spr->rect.left += 50;
		else {
			spr->rect.left = 100;
		}
		sfClock_restart(spr->clock_mov.clock);
	}
	if (movement == 1) {
		movement = 2;
		spr->offset.y = -10;
	}
	if (movement == 2)
		move_sonic_death(spr);
	sfSprite_setTextureRect(spr->sprite, spr->rect);
	sfRenderWindow_drawSprite(window->window, spr->sprite, NULL);
	return (movement);
}

int display_end(global *data, int movement)
{
	sfVector2f position1 = {.x = 200, .y = 100};
	sfVector2f position2 = {.x = 400, .y = 300};
	sfVector2f position3 = {.x = 230, .y = 450};
	sfVector2f position4 = {.x = 450, .y = 600};

	sfRenderWindow_clear(data->window.window, sfBlack);
	draw_back(data->sprites[BACK_BACK], &data->window, 0);
	draw_back(data->sprites[BACK_MIDDLE], &data->window, 0);
	draw_back(data->sprites[BACK_FRONT], &data->window, 1);
	draw_ground(data->ground, &data->window, 0);
	print_text(data, "You Loose", 100, position1);
	print_text(data, "Score", 40, position2);
	print_score(data, data->score, 670, 290);
	print_text(data, "High Score", 40, position3);
	print_score(data, data->best_score, 670, 440);
	print_enter_alpha(data, position4, 40);
	movement = death_sonic(&data->window, data->sprites[SONIC], \
movement, 0.5);
	sfRenderWindow_display(data->window.window);
	return (movement);
}

int musique_loose(global *d, int beg, int replay)
{
	if (beg == 1 && sfSound_getStatus(d->music[HURT]->sound) == sfStopped) {
		sfMusic_play(d->music[LOOSE_S]->music);
		return (beg += 1);
	}
	if (beg == 0 && sfSound_getStatus(d->music[HURT]->sound) == sfStopped) {
		sfSound_play(d->music[HURT]->sound);
		return (beg += 1);
	}
	if (replay != 0) {
		if (sfMusic_getStatus(d->music[LOOSE_S]->music) == sfPlaying)
			sfMusic_stop(d->music[LOOSE_S]->music);
		if (sfSound_getStatus(d->music[HURT]->sound) == sfPlaying)
			sfSound_stop(d->music[HURT]->sound);
	}
	return (beg);
}

int animation_loose(global *data)
{
	sfEvent event;
	int movement = 1;
	int beg = 0;
	int replay = 0;
	game_object **sprites = data->sprites;

	sprites[SONIC]->rect.top = 100;
	sprites[SONIC]->rect.left = 0;
	sprites[SONIC]->offset.y = 0;
	sprites[SONIC]->offset.x = 6;
	sfSprite_setTextureRect(sprites[SONIC]->sprite, sprites[SONIC]->rect);
	sprites[SONIC]->clock_mov.clock = sfClock_create();
	while (sfRenderWindow_isOpen(data->window.window) && replay == 0) {
		check_window_size(data->window.window);
		movement = display_end(data, movement);
		replay = analyse_events(data, event);
		beg = musique_loose(data, beg, replay);
	}
	sfClock_destroy(sprites[SONIC]->clock_mov.clock);
	data = re_initialisation(data);
	return (0);
}
