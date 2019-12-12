/*
** EPITECH PROJECT, 2017
** initialisation_all.c
** File description:
** initialise all the needed ressources
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_runner.h"

global *initialisation_global_music_text(global *all)
{
	all->music = initialise_all_music();
	if (all->music == NULL)
		return (destroy_global(all));
	all->texts = create_all_texts();
	if (all->texts == NULL)
		return (destroy_global(all));
	return (all);
}

global *initialisation_global_sprites(char *filepath, global *all)
{
	if (!all->window.window)
		return (destroy_global(all));
	all->ground = recup_struct(filepath);
	if (all->ground == NULL)
		return (destroy_global(all));
	all->sprites = initialise_all_sprites();
	if (all->sprites == NULL)
		return (destroy_global(all));
	return (all);
}

global *initialise_all_null(global *data)
{
	data->ground = NULL;
	data->sprites = NULL;
	data->music = NULL;
	data->texts = NULL;
	return (data);
}

global *initialisation_all_global(char *filepath)
{
	global *all = malloc(sizeof(*all));

	if (all == NULL)
		return (NULL);
	all = initialise_all_null(all);
	all->window = initialisation_window();
	all = initialisation_global_sprites(filepath, all);
	if (all == NULL || !all->window.window)
		return (destroy_global(all));
	all = initialisation_global_music_text(all);
	if (all == NULL)
		return (NULL);
	all->level = 0;
	all->alpha = 254;
	all->offset_alpha = -2;
	return (all);
}
