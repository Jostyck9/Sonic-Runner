/*
** EPITECH PROJECT, 2017
** manage_lvl.c
** File description:
** manage the severals levels
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my.h"
#include "my_runner.h"

void check_score(global *data, int result)
{
	if (result != WIN)
		data->score -= 10;
	if (data->score > data->best_score) {
		data->best_score = data->score;
	}
}

void manage_lvl(global *data)
{
	s_window *window = &data->window;
	int result = 0;

	while (sfRenderWindow_isOpen(window->window)) {
		menu_loop(data);
		result = game_loop(data);
		check_score(data, result);
		if (result == WIN)
			animation_win(data);
		else {
			animation_loose(data);
		}
		data->level = 0;
	}
}
