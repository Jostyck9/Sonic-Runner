/*
** EPITECH PROJECT, 2017
** destroy_music.c
** File description:
** destroy all the music
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "my.h"
#include "my_runner.h"

void destroy_sound(sounds *music)
{
	if (music == NULL || !music)
		return;
	if (music->sound_buff)
		sfSoundBuffer_destroy(music->sound_buff);
	if (music->sound)
		sfSound_destroy(music->sound);
	free(music);
}

void destroy_music(sounds *music)
{
	if (music == NULL || !music)
		return;
	if (music->music) {
		sfMusic_destroy(music->music);
	}
	free(music);
}

sounds **destroy_all_music(sounds **music)
{
	sounds **empty = NULL;

	if (!music || music == NULL)
		return (empty);
	destroy_music(music[GREEN_HILL]);
	destroy_sound(music[JUMP]);
	destroy_music(music[LOOSE_S]);
	destroy_music(music[WIN_S]);
	destroy_sound(music[HURT]);
	destroy_music(music[MENU]);
	free(music);
	return (empty);
}
