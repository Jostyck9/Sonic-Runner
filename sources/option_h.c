/*
** EPITECH PROJECT, 2017
** option_h.c
** File description:
** print the option
*/

#include "my_runner.h"
#include "my.h"

int option_h(void)
{
	my_putstr("Finite runner created with CSFM.\n");
	my_putstr("This runner is based on the Sonic Character\n\n");
	my_putstr("USAGE\n\t./my_runner map.txt\n\n");
	my_putstr("OPTIONS\n\t-i\t\tlaunch the game in infinite mode.\n");
	my_putstr("\t-h\t\tprint the usage and quit.\n\n");
	my_putstr("USER INTERACTIONS\n\tSPACE_KEY jump.\n");
	my_putstr("\tENTER start.\n\tESCAPE quit.\n");
	my_putstr("\tP pause.\n");
	return (0);
}
