/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main function
*/

#include "my_runner.h"
#include "my.h"

int main(int ac, char **av)
{
	if (ac == 2)
		return (recup_arg(av[1]));
	my_putstr("./my_runner: bad arguments: 0 given but 1 is required\n");
	my_putstr("retry with -h\n");
	return (84);
}
