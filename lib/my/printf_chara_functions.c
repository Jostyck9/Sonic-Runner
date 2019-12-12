/*
** EPITECH PROJECT, 2017
** printf_chara_funstions.c
** File description:
** all the the function that print a letter
*/

#include <stdarg.h>
#include "my.h"

int case_s(va_list ap)
{
	my_putstr(va_arg(ap, char *));
	return (1);
}

int case_s_upper(va_list ap)
{
	my_putstr_printable(va_arg(ap, char *));
	return (1);
}

int case_c(va_list ap)
{
	my_putchar(va_arg(ap, unsigned int));
	return (1);
}

int case_mod(va_list ap)
{
	my_putstr("%");
	return (1);
}

int my_putstr_without_mod(char *str, int i)
{
	while (str[i] != '%' && str[i] != '\0') {
		my_putchar(str[i]);
		i += 1;
	}
	if (str[i] == '\0')
		return (i);
	i += 1;
	return (i);
}
