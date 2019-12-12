/*
** EPITECH PROJECT, 2017
** my_put_nbr_str.c
** File description:
** convert a number into a string, works for positive and int value
*/

#include <stdlib.h>

int count_size_nbr(int nbr)
{
	int size = 1;

	if (nbr < 0)
		nbr = nbr * -1;
	while (nbr > 9) {
		nbr /= 10;
		size += 1;
	}
	return (size);
}

char *my_putnbr_str(int nbr)
{
	int size = 0;
	char *str;

	size = count_size_nbr(nbr);
	str = malloc(sizeof(*str) * (size + 1));
	str[size] = '\0';
	if (nbr <= 0) {
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	while (size > 0) {
		str[size - 1] = (nbr % 10) + '0';
		nbr /= 10;
		size -= 1;
	}
	return (str);
}
