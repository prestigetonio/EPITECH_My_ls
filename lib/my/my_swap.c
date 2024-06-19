/*
** EPITECH PROJECT, 2023
** my_swap.c
** File description:
** emacs
*/

#include "../../include/my.h"

void my_swap(int *a, int *b)
{
    int ptr = *a;

    *a = *b;
    *b = ptr;
}
