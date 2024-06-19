/*
** EPITECH PROJECT, 2023
** B-PSU-100-TLS-1-1-myls-tony.fournales
** File description:
** basic_ls.c
*/

#include <errno.h>
#include <stdio.h>
#include <dirent.h>
#include "my.h"
#include "my_printf.h"

int openning(const char *file)
{
    DIR *pDir = opendir(file);

    if (!pDir) {
        if (errno == EACCES) {
            my_printf("my_ls: cannot open directory '%s': ");
            my_printf("Permission denied\n", file);
        } else {
            my_printf("my_ls: cannot open directory\n");
        }
        return 0;
    }
    return pDir;
}

int just_my_ls(int argc, char **argv)
{
    const char *file = argc == 1 ? "." : argv[1];
    DIR *pDir = openning(file);
    struct dirent *read;

    if (!pDir) {
        return 84;
    }
    read = readdir(pDir);
    while (read != NULL) {
        if (read->d_name[0] != '.') {
            my_printf("%s\n", read->d_name);
        }
        read = readdir(pDir);
    }
    closedir(pDir);
    return 0;
}
