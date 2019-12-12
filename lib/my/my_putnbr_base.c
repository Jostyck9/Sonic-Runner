/*
** EPITECH PROJECT, 2017
** my_putnbr_base.c
** File description:
** transform a number into another base
*/

#include "my.h"

int div_of(int nbr, int div)
{
	int final = 0;
	int i = 0;

	if (nbr < 0) {
		nbr = nbr * - 1;
	}
	while (nbr >= div) {
		final = final * 10 + nbr % div;
		nbr = nbr / div;
		i += 1;
	}
	final = final * 10 + nbr % div;
	return (i + 1);
}

int count_base(char const *base)
{
	int i = 0;

	while (base[i] != '\0') {
		i += 1;
	}
	return (i);
}

int my_print_final(int *str, char const *base, int i)
{
	while (i >= 0)
	{
		my_putchar(base[str[i]]);
		i -= 1;
	}
	return (0);
}

int if_base_possible(char const *base)
{
	int beg = 0;
	int nb = 1;
	int return_0 = 0;

	while (base[beg] != '\0' && return_0 == 0) {
		while (base[beg] != base[nb] && base[nb] != '\0')
			nb += 1;
		if (base[nb] != '\0') {
			return_0 = 1;
			break;
		}
		beg += 1;
		nb = beg + 1;
	}
	return (return_0);
}

int my_putnbr_base (unsigned int nbr, char const *base)
{
	int nb_base = count_base(base);
	int nb_int[div_of(nbr, nb_base)];
	int i = 0;
	int return_0 = 0;

	return_0 = if_base_possible(base);
	if (nbr < 0 && return_0 == 0) {
		nbr = nbr * - 1;
		my_putchar('-');
	}
	if (return_0 == 1) {
		return (0);
	}
	while (nbr >= nb_base) {
		nb_int[i] = nbr % nb_base;
		nbr = nbr / nb_base;
		i += 1;
	}
	nb_int[i] = nbr;
	my_print_final(nb_int, base, i);
	return (0);
}
