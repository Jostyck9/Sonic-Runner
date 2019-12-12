/*
** EPITECH PROJECT, 2017
** graphical.h
** File description:
** include for the libgraphical.a
*/

#ifndef GRAPHICAL_H_
#define GRAPHICAL_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

struct framebuffer {
        unsigned int width;
        unsigned int height;
        sfUint8 *pixels;
};
typedef struct framebuffer framebuffer_t;

struct size_rect {
	unsigned int width;
	unsigned int height;
};
typedef struct size_rect size_r;

struct image_sprite {
	sfTexture *texture;
	sfSprite *sprite;
	sfIntRect rect;
	sfVector2f position;
	sfVector2f speed;
	float limit_speed;
	int score;
	int error;
};
typedef struct image_sprite s_picture;

struct clock {
	sfClock *clock;
	sfTime time;
	float seconds;
};
typedef struct clock s_clock;

struct all_pictures {
	s_picture background;
	s_picture menu_back;
	s_picture duck;
	s_picture dog;
	s_picture hearts;
};
typedef struct all_pictures pictures;

framebuffer_t *framebuffer_create(unsigned int, unsigned int);
void my_draw_square(framebuffer_t *, sfVector2i, int, sfColor);
void my_put_pixel(framebuffer_t *, unsigned int, unsigned int, sfColor);
void my_draw_rect(framebuffer_t *buff, sfVector2i pos, size_r siz, sfColor co);

#endif
