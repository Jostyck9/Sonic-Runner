/*
** EPITECH PROJECT, 2017
** events.c
** File description:
** manage the differents form of events
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my_runner.h"
#include "my.h"

void close_window(sfRenderWindow *window)
{
	if (window)
		sfRenderWindow_close(window);
}

void change_jump_offset(game_object **sprites, game_object **ground, \
sounds **music)
{
	game_object *current;

	if ((current = collision_ground(sprites[SONIC], ground)) != NULL) {
		sprites[SONIC]->offset.y = -25;
		sfSound_play(music[JUMP]->sound);
	}
}

void check_if_pause(global *data, sfEvent eve)
{
	if (eve.type == sfEvtKeyPressed && \
eve.key.code == sfKeyP && data->level == 1)
		pause_menu(data);
}

int analyse_events(global *data, sfEvent eve)
{
	game_object **sprites = data->sprites;

	while (sfRenderWindow_pollEvent(data->window.window, &eve)) {
		if (eve.type == sfEvtClosed || \
(eve.type == sfEvtKeyPressed && eve.key.code == sfKeyEscape))
			close_window(data->window.window);
		if (eve.type == sfEvtKeyPressed && \
eve.key.code == sfKeySpace && data->level == 1)
			change_jump_offset(sprites, data->ground, data->music);
		if (eve.type == sfEvtKeyPressed && \
eve.key.code == sfKeyReturn && data->level != 1)
			return (1);
		check_if_pause(data, eve);
	}
	return (0);
}
