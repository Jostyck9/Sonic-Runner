/*
** EPITECH PROJECT, 2017
** my_runner.c
** File description:
** my_runner_function
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_runner.h"

s_window initialisation_window(void)
{
	s_window window_s;

	window_s.mode.width = SCREEN_WIDTH;
	window_s.mode.height = SCREEN_HEIGHT;
	window_s.mode.bitsPerPixel = 32;
	window_s.position_win.x = 330;
	window_s.position_win.y = 155;
	window_s.window = \
sfRenderWindow_create(window_s.mode, "My_runner", sfDefaultStyle, NULL);
	if (window_s.window) {
		sfRenderWindow_setPosition(window_s.window, \
window_s.position_win);
		sfRenderWindow_setFramerateLimit(window_s.window, 60);
	}
	return (window_s);
}

int my_runner(char *filepath)
{
	int error = 0;

	global *data = NULL;
	data = initialisation_all_global(filepath);
	if (data == NULL)
		return (84);
	data->score = 0;
	data->best_score = 0;
	manage_lvl(data);
	destroy_global(data);
	return (error);
}
