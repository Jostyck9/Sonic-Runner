/*
** EPITECH PROJECT, 2017
** recup_map.c
** File description:
** recup the map in an array in 2 dimension
*/

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "my_runner.h"

void count_x(char *buffer, int *x)
{
	int i = 0;

	while (buffer[i] != '\n') {
		i += 1;
		*x += 1;
	}
}

void count_y(char *buffer, int *y, int size)
{
	int i = 0;

	while (i < size) {
		if (buffer[i] == '\n')
			*y += 1;
		i += 1;
	}
}

int size_line(int beg, char *buffer)
{
	int i = 0;
	int letter = 0;
	int size = 0;

	while (i < beg) {
		if (buffer[letter] == '\n')
			i += 1;
		letter += 1;
	}
	while (buffer[letter] != '\n') {
		size += 1;
		letter += 1;
	}
	return (size);
}

char **put_in_map(char *buffer, int *y)
{
	char **map = malloc(sizeof(*map) * (*y + 1));
	int i = 0;
	int b = 0;
	int c = 0;
	int nbr_columns = 0;

	for (;i < *y; c++, i++) {
		nbr_columns = size_line(i, buffer);
		map[i] = malloc(sizeof(**map) * (nbr_columns + 1));
		while (b < nbr_columns) {
			map[i][b] = buffer[c];
			b += 1;
			c += 1;
		}
		map[i][b] = '\0';
		b = 0;
	}
	map[i] = NULL;
	return (map);
}

char **recup_map(int size, char *filepath)
{
	int fd;
	char *buffer = malloc(sizeof(char) * (size + 1));
	char **map;
	int x = 0;
	int y = 0;

	if ((fd = open_file(filepath)) == -1) {
		write(2, "Fail to open file\n", 18);
		return (NULL);
	}
	if (read(fd, buffer, size) == - 1) {
		write(2, "Fail to read\n", 13);
		return (NULL);
	}
	buffer[size] = '\0';
	close(fd);
	count_y(buffer, &y, size);
	count_x(buffer, &x);
	map = put_in_map(buffer, &y);
	free(buffer);
	return (map);
}
