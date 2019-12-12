/*
** EPITECH PROJECT, 2017
** transform_map2.c
** File description:
** transform the map into a struct array
*/

#include <stdlib.h>
#include "my_runner.h"

int count_size_struct(char **map)
{
	int y = 0;
	int x = 0;
	int size = 0;

	while (map[y] != NULL) {
		while (map[y][x] != '\0') {
			size += check_chara(map[y][x]);
			x += 1;
		}
		x = 0;
		y += 1;
	}
	return (size);
}
