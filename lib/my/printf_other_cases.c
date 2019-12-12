/*
** EPITECH PROJECT, 2017
** printf_other_cases.c
** File description:
** several precision flags cases
*/

#include "my.h"
#include <stdarg.h>

void my_put_nbr_plus(int value)
{
	if (value >= 0)
		my_putchar('+');
	my_put_nbr(value);
}

int case_precision(int *b, char *str, int incrementation, va_list ap)
{
	int i = incrementation;
	int choose = 0;
	int value;

	if (b[0] == 15) {
		while (str[i] == '+')
			i += 1;
		choose = which_function(str[i]);
		if (choose == 2) {
			value = va_arg(ap, int);
			my_put_nbr_plus(value);
			i += 1;
		} else
			b[0] = choose;
	}
	return (incrementation - i);
}
