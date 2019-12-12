/*
** EPITECH PROJECT, 2017
** initialisation_text.c
** File description:
** initialise all the text needed
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my.h"
#include "my_runner.h"

text *param_text(text *new, sfVector2f position, int size)
{
	sfText_setPosition(new->text, position);
	sfText_setCharacterSize(new->text, size);
	return (new);
}

text *create_text(char *filepath, sfVector2f position, int size)
{
	text *new = NULL;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->font = sfFont_createFromFile(filepath);
	if (!new->font) {
		free(new);
		return (NULL);
	}
	new->text = sfText_create();
	if (!new->text) {
		sfFont_destroy(new->font);
		free(new);
		return (NULL);
	}
	sfText_setFont(new->text, new->font);
	param_text(new, position, size);
	return (new);
}

text **create_all_texts(void)
{
	text **all = NULL;
	sfVector2f position_end = {.x = 200, .y = 200};
	sfVector2f posi_score = {.x = 300, .y = 400};

	all = malloc(sizeof(*all) * (2));
	if (all == NULL)
		return (NULL);
	all[TEXT_END] = NULL;
	all[TEXT_SCORE] = NULL;
	all[TEXT_END] = create_text("assets/font.ttf", position_end, 100);
	if (all[TEXT_END] == NULL)
		return (destroy_all_text(all));
	all[TEXT_SCORE] = create_text("assets/font_score.ttf", posi_score, 50);
	if (all[TEXT_SCORE] == NULL)
		return (destroy_all_text(all));
	return (all);
}
