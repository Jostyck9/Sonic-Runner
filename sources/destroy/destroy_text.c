/*
** EPITECH PROJECT, 2017
** destroy_text.c
** File description:
** destroy all the text
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "my_runner.h"

void destroy_text(text *current)
{
	if (!current || current == NULL)
		return;
	if (current->font)
		sfFont_destroy(current->font);
	if (current->text)
		sfText_destroy(current->text);
	free(current);
}

text **destroy_all_text(text **current)
{
	if (!current || current == NULL)
		return (current);
	destroy_text(current[TEXT_END]);
	destroy_text(current[TEXT_SCORE]);
	free(current);
	return (NULL);
}
