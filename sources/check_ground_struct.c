/*
** EPITECH PROJECT, 2017
** check_ground_struct.c
** File description:
** check if the struct is correctly made
*/

#include <stdlib.h>
#include "my.h"
#include "my_runner.h"

int check_ground_struct(game_object **ground, int size)
{
	int i = 0;

	while (ground[i] != NULL)
		i += 1;
	if (i != size) {
		destroy_ground(ground);
		ground = NULL;
		return (84);
	}
	return (0);
}
