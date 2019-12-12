/*
** EPITECH PROJECT, 2017
** pause.c
** File description:
** pause menu
*/

#include <SFML/Graphics.h>
#include "my.h"
#include "my_runner.h"

void check_music_if_play(global *data)
{
	if (sfMusic_getStatus(data->music[GREEN_HILL]->music) == sfPlaying)
		sfMusic_pause(data->music[GREEN_HILL]->music);
	if (sfSound_getStatus(data->music[JUMP]->sound) == sfPlaying)
		sfSound_pause(data->music[JUMP]->sound);
}

void check_music_if_paused(global *data)
{
	if (sfMusic_getStatus(data->music[GREEN_HILL]->music) == sfPaused)
		sfMusic_play(data->music[GREEN_HILL]->music);
	if (sfSound_getStatus(data->music[JUMP]->sound) == sfPaused)
		sfSound_play(data->music[JUMP]->sound);
}

int events_pause(global *data, sfEvent eve)
{
	while (sfRenderWindow_pollEvent(data->window.window, &eve)) {
		if (eve.type == sfEvtClosed || \
(eve.type == sfEvtKeyPressed && eve.key.code == sfKeyEscape))
			close_window(data->window.window);
		if (eve.type == sfEvtKeyPressed && eve.key.code == sfKeyP)
			return (0);
	}
	return (1);
}

void pause_menu(global *data)
{
	sfEvent event;
	sfVector2f position = {.x = 500, .y= 400};
	int pause = 1;

	check_music_if_play(data);
	while (pause == 1 && sfRenderWindow_isOpen(data->window.window)) {
		print_text(data, "PAUSE", 50, position);
		sfRenderWindow_display(data->window.window);
		pause = events_pause(data, event);
	}
	check_music_if_paused(data);
}
