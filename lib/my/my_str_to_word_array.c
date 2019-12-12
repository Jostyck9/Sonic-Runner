/*
** EPITECH PROJECT, 2017
** my_str_to_word_array.c
** File description:
** slpit a string in differents words separate by non alphabetic chara
*/

#include <stdlib.h>

int	char_alpha(char chara)
{
	if ((chara >= 'A' && chara <= 'Z') || (chara >= 'a' && chara <= 'z')\
|| (chara >= '0' && chara <= '9'))
		return (1);
	else
		return (0);
}

char	**my_str_double_pnt(char const *str, char **resu, int num, int beg)
{
	int i = 0;

	while (char_alpha(str[beg]) == 1) {
		resu[num][i] = str[beg];
		i += 1;
		beg += 1;
	}
	resu[num][i] = '\0';
	return (resu);
}

int	chara_in_word(char const *str, int beg)
{
	int nbr_char = 0;

	while (char_alpha(str[beg] == 0)) {
		beg += 1;
	}
	while (char_alpha(str[beg]) == 1) {
		beg += 1;
		nbr_char += 1;
	}
	return (nbr_char);
}

int	how_many_word(char const *str)
{
	int beg = 0;
	int word = 0;

	if (char_alpha(str[beg] == 1)) {
		word += 1;
		beg += 1;
	}
	while (char_alpha(str[beg]) == 0) {
		beg += 1;
	}
	while (str[beg] != '\0') {
		if (char_alpha(str[beg]) == 1 && char_alpha(str[beg - 1]) == 0)
			word += 1;
		beg += 1;
	}
	return (word);
}

char	**my_str_to_word_array(char const *str)
{
	char **result;
	int i = 0;
	int nb_string = 0;
	int nb_chara = 0;
	int beg = 0;

	nb_string = how_many_word(str);
	result = malloc (sizeof(*result) * (nb_string + 1));
	while (i < nb_string) {
		while (char_alpha(str[beg]) == 0) {
			beg += 1;
		}
		nb_chara = chara_in_word(str, beg);
		result[i] = malloc (sizeof(char) * (nb_chara + 1));
		my_str_double_pnt(str, result, i, beg);
		beg = beg + nb_chara + 1;
		i += 1;
		}
	result[i] = '\0';
	return (result);
}
