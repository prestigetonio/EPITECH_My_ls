/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** emacs
*/

#ifndef MY
    #define MY

int my_ls_r(int argc, char **argv);
int just_my_ls(int argc, char **argv);
int my_ls_choose(int argc, char **argv);
int my_ls_a(int argc, char **argv);
int my_ls_d(int argc, char **argv);
int my_put_nbr(int nb);
unsigned int my_put_nbru(unsigned int nb);
int my_putchar(char l);
int my_sort_alpha(int argc, char argv, char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
char *my_strdup(char *str);
void my_swap(int *a, int *b);
char *my_strcpy(char *dest, char const *src);
#endif
