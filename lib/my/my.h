/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** header of my library
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>

int my_compute_power_rec(int, int);
int error(int);
int my_compute_square_root(int);
int my_find_prime_sup(int);
int my_getnbr(char const *);
int size(int);
int negative(int, char);
int my_isneg(int);
int my_is_prime(int);
void my_putchar(char);
int my_put_nbr(int);
int my_putstr(char const *);
char *my_revstr(char *);
int size_of(char *);
int my_showmem(char const *, int);
int my_showstr(char const *);
void my_sort_int_array(int *, int);
char *my_strcapitalize(char *);
int if_letter(char *, int);
int if_space(char *, int);
int if_no_letter(char *, int, int);
char *my_strcat(char *, char const *);
int my_strcmp(char const *, char const *);
char *my_strcpy(char *, char const *);
int my_str_isalpha(char const *);
int if_alpha(char *, int);
int my_str_islower(char const *);
int if_lower(char *, int);
int my_str_isnum(char const *);
int if_num(char *, int);
int my_str_isprintable(char const *);
int if_printable(char *, int);
int my_str_isupper(char const *);
int if_upper(char *, int);
int my_strlen(char const *);
char *my_strlowcase(char *);
int if_letter_uppercase(char *, int);
char *my_strncat(char *, char const *, int);
int my_strncmp(char const *, char const *, int);
char *my_strncpy(char *, char const *, int);
char *my_strstr(char *, char const *);
int compare(char *, char const *, int);
char *my_strupcase(char *);
int if_letter_lowercase(char *, int);
void my_swap(int *, int *);
char **my_str_to_word_array(char const *);
int how_many_word(char const *);
int chara_in_word(char const *, int);
char *my_str_double_pointeur(char const *, char **, int, int, int);
int char_alpha(char *);
char *my_strdup(char const *);
char *concat_params(int, char **);
char *my_strcat_double(char *, char const **, int);
char *replace_last_chara(char *);
int my_show_word_array(char * const *);
int print_word(char * const *, int);
int disp_stdarg(char *, ...);
int sum_stdarg(int , int, ...);
int my_putnbr_base(unsigned int, char const*);
int my_putstr_printable(char *);
int my_putchar_printable(char);
void my_printf(char *, ...);
int case_o(va_list ap);
int case_b(va_list ap);
int case_x_uppercase(va_list ap);
int case_x(va_list ap);
int case_s(va_list ap);
int case_s_upper(va_list ap);
int case_c(va_list ap);
int case_mod(va_list ap);
int case_u(va_list ap);
int case_d(va_list ap);
int case_i(va_list ap);
int case_p(va_list ap);
int case_space(va_list ap);
int my_putstr_without_mod(char *str, int i);
int my_put_unbr(unsigned int i);
int which_function(char a);

#endif /* MY_H_ */
