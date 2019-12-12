/*
** EPITECH PROJECT, 2017
** my_show_word_array.c
** File description:
** display one word for one line
*/

#include "my.h"

int	print_word(char * const *tab, int i)
{
	int n = 0;

	while (tab[i][n] != '\0') {
		my_putchar(tab[i][n]);
		n += 1;
	}
	my_putchar('\n');
	return (0);
}

int	my_show_word_array(char * const *tab)
{
	int i = 0;

	while (tab[i] != 0) {
		print_word(tab, i);
		i += 1;
	}
	return (0);
}
