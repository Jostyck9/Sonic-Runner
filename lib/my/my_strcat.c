/*
** EPITECH PROJECT, 2017
** my_strcat.c
** File description:
** concatenates two strings
*/

char	*my_strcat(char *dest, char const *src)
{
	int i = 0;
	int n = 0;

	while (dest[i] != '\0') {
		i += 1;
	}
	while (src[n] != '\0') {
		dest[i] = src[n];
		i += 1;
		n += 1;
	}
	dest[i] = src[n];
	return (dest);
}
