/*
** EPITECH PROJECT, 2017
** my_draw_rect.c
** File description:
** draw a square in the buffer in a certain position
*/

#include "graphical.h"

void my_draw_rect(framebuffer_t *buff, sfVector2i pos, size_r siz, sfColor co)
{
	for (unsigned int i = pos.y; i < pos.y + siz.height; i++) {
		for (unsigned int b = pos.x; b < pos.x + siz.width; b++) {
			my_put_pixel(buff, b + 1, i + 1, co);
		}
	}
	return;
}
