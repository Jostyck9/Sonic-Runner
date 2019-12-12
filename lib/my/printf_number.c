/*
** EPITECH PROJECT, 2017
** printf_number.c
** File description:
** print numbers for the printf
*/

#include "my.h"
#include <stdarg.h>

int case_u(va_list ap)
{
	my_put_unbr(va_arg(ap, unsigned int));
	return (1);
}

int case_d(va_list ap)
{
	my_put_nbr(va_arg(ap, int));
	return (1);
}

int case_i(va_list ap)
{
	my_put_nbr(va_arg(ap, int));
	return (1);
}
