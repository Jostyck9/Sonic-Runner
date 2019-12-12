/*
** EPITECH PROJECT, 2017
** my_printf.c
** File description:
** print a string withs some converted variables
*/

#include <stdarg.h>
#include "my.h"

int case_p(va_list ap)
{
	my_putstr("0x");
	my_putnbr_base(va_arg(ap, int), "0123456789abcdef");
	return (1);
}

int case_m(va_list ap)
{
	my_putstr("Success");
	return (1);
}

int case_space(va_list ap)
{
	my_putstr("% ");
	return (1);
}

int case_invali(void)
{
	my_putchar('%');
	return (1);
}

void my_printf(char *str, ...)
{
	va_list ap;
	int i = 0;
	int b = 0;
	int (*functions[14])(va_list) = {case_space, case_mod, case_i, case_d, \
case_u, case_x, case_x_uppercase, case_o, case_c, case_s, case_s_upper, \
case_p, case_b, case_m};

	va_start(ap, str);
	while (str[i] != '\0') {
		i = my_putstr_without_mod(str, i);
		if (str[i] == '\0')
			break;
		b = which_function(str[i]);
		if (b < 14) {
			i += functions[b](ap);
		} else
			case_invali();
		b = 0;
	}
	va_end(ap);
}
