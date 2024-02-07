/*
** EPITECH PROJECT, 2024
** get_move
** File description:
** get_move
*/
#include "my.h"
#include <stdio.h>

static char *remove_backslash_n(char *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            return str;
        }
    }
    return str;
}

int get_move(void)
{
    char *str = NULL;
    size_t size = 0;

    mini_printf("\nattack: ");
    getline(&str, &size, stdin);
    str = remove_backslash_n(str);
    while (convert_square(str) == 84) {
        mini_printf("\nWrong Position\n");
        mini_printf("\nattack: ");
        getline(&str, &size, stdin);
        str = remove_backslash_n(str);
    }
    return convert_square(str);
}
