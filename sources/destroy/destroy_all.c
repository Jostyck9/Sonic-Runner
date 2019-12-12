/*
** EPITECH PROJECT, 2017
** destroy_all.c
** File description:
** destroy all the needed ressources
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_runner.h"

void destroy_window(s_window window)
{
	if (!window.window)
		return;
	if (sfRenderWindow_isOpen(window.window))
		close_window(window.window);
	sfRenderWindow_destroy(window.window);
}

global *destroy_global(global *all)
{
	if (all == NULL || !all)
		return (NULL);
	destroy_window(all->window);
	destroy_all_sprites(all->sprites);
	destroy_all_music(all->music);
	destroy_ground(all->ground);
	destroy_all_text(all->texts);
	free(all);
	return (NULL);
}
