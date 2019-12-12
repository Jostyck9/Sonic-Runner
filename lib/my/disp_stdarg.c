/*
** EPITECH PROJECT, 2017
** disp_argc.c
** File description:
** display the unknown arguments
*/

#include <stdarg.h>
#include "my.h"

int disp_stdarg(char *s, ...)
{
	va_list ap;
	int i = 0;

	va_start(ap, s);
	while (s[i] != '\0') {
		switch (s[i]) {
		case 'c' :
			my_putchar(va_arg(ap, int));
			break;
		case 's' :
			my_putstr(va_arg(ap, char *));
			break;
		case 'i' :
			my_put_nbr(va_arg(ap, int));
		}
		my_putchar('\n');
		i += 1;
	}
	va_end(ap);
	return (0);
}
