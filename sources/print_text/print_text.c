/*
** EPITECH PROJECT, 2017
** print_text.c
** File description:
** print the text added in parameter
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my_runner.h"
#include "my.h"

void print_text(global *data, char *str, int size, sfVector2f position)
{
	sfText *text = data->texts[TEXT_END]->text;

	sfText_setString(text, str);
	sfText_setCharacterSize(text, size);
	sfText_setPosition(text, position);
	sfRenderWindow_drawText(data->window.window, text, NULL);
}
