/*
** EPITECH PROJECT, 2017
** choose_function_printf.c
** File description:
** choose the function that we have to do
*/

int which_function(char a)
{
	int b = 0;
	char *str_functions = " %iduxXocsSpbm";

	while (a != str_functions[b] && str_functions[b])
		b += 1;
	return (b);
}
