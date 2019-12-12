/*
** EPITECH PROJECT, 2017
** framebuffer_create.c
** File description:
** initialise the buffer for graphical projects
*/

#include "graphical.h"
#include <stdlib.h>

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
	framebuffer_t *framebuffer;

	framebuffer = malloc(sizeof(*framebuffer));
	framebuffer->width = width;
	framebuffer->height = height;
	framebuffer->pixels = malloc(width * height * (sizeof(sfUint8)) * 4);
	return (framebuffer);
}
