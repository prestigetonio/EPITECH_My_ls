/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** Project My_LS
*/

#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include "my.h"
#include "my_printf.h"

int my_ls_a(int argc, char **argv)
{
    DIR *pDir;
    struct dirent *read;

    if (argc > 1 && argc < 3)
        pDir = opendir(".");
    if (argc > 2 && argc < 4) {
        if (argv[1][0] == '-' && argv[1][1] == 'a') {
            pDir = opendir(argv[2]);
        } else {
            pDir = opendir(argv[1]);
        }
    }
    if (pDir) {
        read = readdir(pDir);
        while (read != NULL) {
            my_printf("%s\n", read->d_name);
            read = readdir(pDir);
        }
        closedir(pDir);
    }
}

int my_ls_d(int argc, char **argv)
{
    DIR *pDir;

    for (int i = 1; i < argc; i++) {
        pDir = opendir(argv[i]);
        if ((opendir(argv[i]) != NULL)) {
            my_printf("%s\n", argv[i]);
            pDir = opendir(argv[i]);
        }
        closedir(pDir);
    }
    return 0;
}

static int choose_two(int argc, char **argv, int i)
{
    if (argv[1][0] == '-' && argv[1][1] == 'a') {
        my_ls_a(argc, argv);
        return 0;
    }
    if (argv[1][0] == '-' && argv[1][1] == 'r') {
        my_ls_r(argc, argv);
        return 0;
    }
    if (argv[1][0] == '-' && argv[1][1] == 'd') {
        my_ls_d(argc, argv);
        return 0;
    }
    if (argv[1][0] != '-') {
        just_my_ls(argc, argv);
        return 0;
    }
    return 0;
}

static int choose_three(int argc, char **argv, int i)
{
    if (argv[1][0] == '-' && argv[1][1] == 'a' ||
        argv[2][0] == '-' && argv[2][1] == 'a') {
        my_ls_a(argc, argv);
        return 0;
    }
    if (argv[1][0] == '-' && argv[1][1] == 'r' ||
        argv[2][0] == '-' && argv[2][1] == 'r') {
        my_ls_r(argc, argv);
        return 0;
    }
    if (argv[1][0] == '-' && argv[1][1] == 'd') {
        my_ls_d(argc, argv);
        return 0;
    }
    if (argv[1][0] != '-') {
        just_my_ls(argc, argv);
        return 0;
    }
    return 0;
}

int my_ls_choose(int argc, char **argv)
{
    int i = 0;

    if (argc == 1) {
        just_my_ls(argc, argv);
        return 0;
    }
    if (argc > 1 && argc < 3) {
        choose_two(argc, argv, i);
        return 0;
    }
    if (argc > 2 && argc < 4) {
        choose_three(argc, argv, i);
        return 0;
    }
    if (argc != 0 && argc != 1 && argc != 2 && argc != 3) {
        my_printf("%s\n", "ERROR");
        return 84;
    }
    return 0;
}
