/*
** EPITECH PROJECT, 2023
** B-PSU-100-TLS-1-1-myls-tony.fournales
** File description:
** reverse_ls.c
*/

#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <dirent.h>
#include "my.h"
#include "my_printf.h"

void display_r(char **buf, int compt)
{
    for (int i = 0; i < compt / 2; i++) {
        my_swap(&buf[i], &buf[compt - i - 1]);
    }
    for (int i = 0; i < compt; i++) {
        my_printf("%s\n", buf[i]);
        free(buf[i]);
    }
}

void limit(DIR *pDir, char **buf, int *compt)
{
    struct dirent *read;

    while ((*compt < 256) && (read = readdir(pDir)) != NULL) {
        if (read->d_name[0] != '.')
            buf[(*compt)++] = my_strdup(read->d_name);
    }
}

int my_ls_r(int argc, char **argv)
{
    DIR *pDir = NULL;
    char *buf[256];
    int compt = 0;

    if (argc > 1 && argc < 3);
        pDir = opendir(".");
    if (argc > 2 && argc < 4) {
        if (argv[1][0] == '-' && argv[1][1] == 'r') {
            pDir = opendir(argv[2]);
        } else {
            pDir = opendir(argv[1]);
        }
    }
    limit(pDir, buf, &compt);
    display_r(buf, compt);
    closedir(pDir);
    return 0;
}
