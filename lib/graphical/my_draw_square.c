/*
** EPITECH PROJECT, 2017
** my_draw_square.c
** File description:
** draw a square in the buffer in a certain position
*/

#include "graphical.h"

void my_draw_square(framebuffer_t *buff, sfVector2i pos, \
int size, sfColor color)
{
	for (int i = pos.y; i <= pos.y + size; i++) {
		for (int b = pos.x; b <= pos.x + size; b++)
			my_put_pixel(buff, b, i, color);
	}
	return;
}
