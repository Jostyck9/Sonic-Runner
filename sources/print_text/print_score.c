/*
** EPITECH PROJECT, 2017
** print_score.c
** File description:
** print the score
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my_runner.h"
#include "my.h"

void print_score(global *data, int score, int x, int y)
{
	char *str;
	sfVector2f position_text = {x, y};

	str = my_putnbr_str(score);
	sfText_setString(data->texts[TEXT_SCORE]->text, str);
	sfText_setPosition(data->texts[TEXT_SCORE]->text, position_text);
	sfRenderWindow_drawText(data->window.window, \
data->texts[TEXT_SCORE]->text, NULL);
	free(str);
}
