/*
** EPITECH PROJECT, 2017
** check_window_size.c
** File description:
** check the size of the window and resize if wa need
*/

#include <SFML/Graphics.h>
#include "my.h"
#include "my_runner.h"

sfVector2u check_size_y(sfVector2u size)
{
	if (size.y < 600)
		size.y = 600;
	if (size.y > 1080)
		size.y = 1080;
	return (size);
}

sfVector2u check_size_x(sfVector2u size)
{
	if (size.x < 800)
		size.x = 800;
	if (size.x > 1920)
		size.x = 1920;
	return (size);
}

void check_window_size(sfRenderWindow *window)
{
	sfVector2u size;

	if (window) {
		size = sfRenderWindow_getSize(window);
		size = check_size_x(size);
		size = check_size_y(size);
		sfRenderWindow_setSize(window, size);
	}
}
