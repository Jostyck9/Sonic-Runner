/*
** EPITECH PROJECT, 2017
** count_size.c
** File description:
** count the nbr of bytes to read
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int count_size(char *filepath)
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int size = 0;

	stream = fopen(filepath, "r");
	if (stream == NULL) {
		write(2, "fail to open\n", 13);
		return (-1);
	}
	while ((read = getline(&line, &len, stream)) != -1)
		size += read;
	free(line);
	fclose(stream);
	if (size == 0)
		write(2, "Invalid map : empty map\n", 24);
	return (size);
}
