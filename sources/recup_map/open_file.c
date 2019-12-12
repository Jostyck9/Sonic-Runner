/*
** EPITECH PROJECT, 2017
** open_file.c
** File description:
** open_a_file
*/

#include "my.h"
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int open_file(char const *filepath)
{
	int value = 0;

	value = open(filepath, O_RDONLY);
	if (value == -1) {
		my_putstr("Fail to open\n");
		return (-1);
	}
	return (value);
}
