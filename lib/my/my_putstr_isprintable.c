/*
** EPITECH PROJECT, 2017
** my_putstr_isprintable.c
** File description:
** display the printables characters from a str
*/

#include "my.h"

int my_putstr_printable(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		my_putchar_printable(str[i]);
		i += 1;
	}
	return (1);
}
