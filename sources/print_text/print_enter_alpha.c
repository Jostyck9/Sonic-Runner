/*
** EPITECH PROJECT, 2017
** print_enter_alpha.c
** File description:
** print the enter message with a modification of the alpha
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my.h"
#include "my_runner.h"

void print_enter_alpha(global *data, sfVector2f position, int size)
{
	sfColor color = {.r = 255, .g = 255, .b = 255, .a = 255};

	if (data->alpha <= 10) {
		data->offset_alpha *= -1;
		data->alpha = 10;
	}
	if (data->alpha >= 250) {
		data->offset_alpha *= -1;
		data->alpha = 250;
	}
	data->alpha += data->offset_alpha;
	color.a = data->alpha;
	sfText_setColor(data->texts[TEXT_END]->text, color);
	print_text(data, "Press Enter", size, position);
	color.a = 255;
	sfText_setColor(data->texts[TEXT_END]->text, color);
}
