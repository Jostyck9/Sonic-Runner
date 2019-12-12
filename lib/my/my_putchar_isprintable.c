/*
** EPITECH PROJECT, 2017
** my_putchar_isprintable.c
** File description:
** print on the screen the character printable
*/

#include "my.h"

int my_putchar_printable(char c)
{
	if (c > 32 && c <= 127) {
		my_putchar(c);
		return (1);
	}
	else {
		my_putchar('\\');
		if (c < 8)
			my_putstr("00");
		else if (c > 8 && c < 64)
			my_putchar('0');
		my_putnbr_base(c, "01234567");
	}
	return (1);
}
