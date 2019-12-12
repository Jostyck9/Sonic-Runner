/*
** EPITECH PROJECT, 2017
** printf_conversion.c
** File description:
** all the conversions functions for the printf
*/

#include "my.h"
#include <stdarg.h>

int case_b(va_list ap)
{
	my_putnbr_base(va_arg(ap, unsigned int), "01");
	return (1);
}

int case_o(va_list ap)
{
	my_putnbr_base(va_arg(ap, unsigned int), "01234567");
	return (1);
}

int case_x_uppercase(va_list ap)
{
	my_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
	return (1);
}

int case_x(va_list ap)
{
	my_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
	return (1);
}
