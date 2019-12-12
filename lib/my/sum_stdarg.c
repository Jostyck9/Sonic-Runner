/*
** EPITECH PROJECT, 2017
** sum_stdarg.c
** File description:
** returns the sum of last nb or the sum of the size of the last nb arguments
*/

#include <stdarg.h>
#include "my.h"

int sum_stdarg(int i, int nb, ...)
{
	int result = 0;
	int inc = 0;
	va_list ap;

	va_start(ap, nb);
	if (i == 0) {
		while (inc < nb) {
			result += va_arg(ap, int);
			inc += 1;
		}
	} else if (i == 1) {
		while (inc < nb) {
			result += my_strlen(va_arg(ap, char *));
			inc += 1;
		}
	} else
		return (84);
	va_end(ap);
	return (result);
}
