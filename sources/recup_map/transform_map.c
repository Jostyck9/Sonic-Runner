/*
** EPITECH PROJECT, 2017
** transform_map.c
** File description:
** transform the map into a struct array
*/

#include <stdlib.h>
#include "my.h"
#include "my_runner.h"

int check_chara(char letter)
{
	char *str = VALUES;
	int i = 0;

	while (str[i] != letter && str[i] != '\0')
		i += 1;
	if (str[i] == '\0')
		return (0);
	return (1);
}

game_object **choose_game_object(game_object **ground, int *nbr_stru, \
char a, sfVector2i position)
{
	int i = 0;
	game_object **(*creation_ground[3])(game_object **, int *, sfVector2i) \
= {ground_map, pike_map, flag_map};

	while (VALUES[i] != a && VALUES[i] != '\0')
		i += 1;
	if (VALUES[i] == '\0')
		return (ground);
	ground = creation_ground[i](ground, nbr_stru, position);
	return (ground);
}

game_object **put_in_struct_map(char **map, sfVector2i posi, \
game_object **ground, int *nbr_stru)
{
	for (posi.x = 0; map[posi.y][posi.x] != '\0'; posi.x++) {
		ground = choose_game_object(ground, nbr_stru, \
map[posi.y][posi.x], posi);
		if (*nbr_stru > 0 && ground[*nbr_stru - 1] == NULL) {
			return (destroy_ground(ground));
		}
	}
	return (ground);
}

game_object **transform_map(char **map)
{
	int size = 0;
	sfVector2i posi = {.x = 0, .y = 0};
	int nbr_stru = 0;
	game_object **ground = NULL;

	size = count_size_struct(map);
	ground = malloc(sizeof(*ground) * (size + 1));
	if (ground == NULL)
		return (ground);
	for (posi.y = 0; map[posi.y] != NULL; posi.y++) {
		ground = put_in_struct_map(map, posi, ground, &nbr_stru);
		if (ground == NULL) {
			return (NULL);
		}
	}
	ground[size] = NULL;
	return (ground);
}

game_object **recup_struct(char *filepath)
{
	game_object **ground = NULL;
	char **map = NULL;
	int size = 0;
	int i = 0;

	size = count_size(filepath);
	if (size <= 0) {
		return (NULL);
	}
	map = recup_map(size, filepath);
	if (map == NULL)
		return (NULL);
	ground = transform_map(map);
	for (i = 0; map[i] != NULL; i++)
		free(map[i]);
	free(map);
	return (ground);
}
