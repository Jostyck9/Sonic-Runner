/*
** EPITECH PROJECT, 2017
** recup_arg.c
** File description:
** recup the argument
*/

#include <SFML/Graphics.h>
#include "my.h"
#include "my_runner.h"

int recup_arg(char *av)
{
	int error = 0;

	if (av[0] == '-' && av[1] == 'h') {
		option_h();
		return (0);
	}
	if (av[0] == '-' && av[1] == 'i') {
		my_putstr("Infinite mode isn't available but don't worry, it ");
		my_putstr("will come soon ;)\n");
		option_h();
		return (0);
	}
	error = my_runner(av);
	return (error);
}
