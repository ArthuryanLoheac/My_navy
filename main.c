/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/
#include "my.h"

int main(int argc, char **argv)
{
    if (argc == 2) {
        if (my_strcmp(argv[1], "-h") == 0)
            return print_help();
        else
            return player_one(argv);
    } else if (argc == 3)
        return player_two(argv);
    else
        return 84;
}
