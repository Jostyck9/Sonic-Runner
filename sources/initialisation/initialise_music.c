/*
** EPITECH PROJECT, 2017
** initialise_music.c
** File description:
** initialise all the music needed
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "my.h"
#include "my_runner.h"

sounds *initialise_sound_fx(int type, char *filepath, float volume)
{
	sounds *current_music = NULL;

	current_music = malloc(sizeof(*current_music));
	if (current_music == NULL)
		return (current_music);
	current_music->type = type;
	current_music->sound_buff = sfSoundBuffer_createFromFile(filepath);
	if (!current_music->sound_buff) {
		free(current_music);
		return (NULL);
	}
	current_music->sound = sfSound_create();
	if (!current_music->sound) {
		sfSoundBuffer_destroy(current_music->sound_buff);
		free(current_music);
		return (NULL);
	}
	sfSound_setBuffer(current_music->sound, current_music->sound_buff);
	sfSound_setVolume(current_music->sound, volume);
	return (current_music);
}

sounds *initialise_music(int type, char *filepath, float volume, sfBool loop)
{
	sounds *current_music = NULL;

	current_music = malloc(sizeof(*current_music));
	if (current_music == NULL)
		return (current_music);
	current_music->type = type;
	current_music->music = sfMusic_createFromFile(filepath);
	if (!current_music->music) {
		free (current_music);
		return (NULL);
	}
	sfMusic_setVolume(current_music->music, volume);
	sfMusic_setLoop(current_music->music, loop);
	return (current_music);
}

sounds **create_music_1(sounds **music)
{
	music[JUMP] = initialise_sound_fx(SOUND, "assets/music/jump.ogg", 100);
	if (music[JUMP] == NULL)
		return (destroy_all_music(music));
	music[HURT] = initialise_sound_fx(SOUND, "assets/music/pike.ogg", 40);
	if (music[HURT] == NULL)
		return (destroy_all_music(music));
	music[WIN_S] = initialise_music(MUSIC, "assets/music/win.ogg", \
50, sfFalse);
	if (music[WIN_S] == NULL)
		return (destroy_all_music(music));
	return (music);
}

sounds **create_music_2(sounds **music)
{
	music[MENU] = initialise_music(MUSIC, "assets/music/menu.ogg", \
30, sfFalse);
	if (music[MENU] == NULL)
		return (destroy_all_music(music));
	music[LOOSE_S] = initialise_music(MUSIC, "assets/music/loose.ogg", \
20, sfFalse);
	if (music[LOOSE_S] == NULL)
		return (destroy_all_music(music));
	music[GREEN_HILL] = initialise_music(MUSIC, \
"assets/music/GreenHill.ogg", 20, sfTrue);
	if (music[GREEN_HILL] == NULL)
		return (destroy_all_music(music));
	return (music);
}

sounds **initialise_all_music(void)
{
	sounds **music = NULL;

	music = malloc(sizeof(*music) * 6);
	if (music == NULL)
		return (music);
	music[GREEN_HILL] = NULL;
	music[MENU] = NULL;
	music[WIN_S] = NULL;
	music[JUMP] = NULL;
	music[HURT] = NULL;
	music[LOOSE_S] = NULL;
	music = create_music_1(music);
	if (music == NULL)
		return (music);
	music = create_music_2(music);
	if (music == NULL)
		return (music);
	return (music);
}
