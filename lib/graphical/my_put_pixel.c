/*
** EPITECH PROJECT, 2017
** my_put_pixel.c
** File description:
** put a pixel in the buffer
*/

#include "graphical.h"

void my_put_pixel(framebuffer_t *buffer, unsigned int x, unsigned int y, sfColor color)
{
	int position = 0;

	position = ((y - 1) * buffer->width + x - 1) * 4;
	buffer->pixels[position] = color.r;
	buffer->pixels[position + 1] = color.g;
	buffer->pixels[position + 2] = color.b;
	buffer->pixels[position + 3] = color.a;
	return;
}
