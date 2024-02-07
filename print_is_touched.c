/*
** EPITECH PROJECT, 2024
** print_is_touched
** File description:
** print_is_touched
*/
#include "my.h"

void print_is_touched(int played, char **board)
{
    if (is_touched(played, board) == 0)
        mini_printf("missed\n");
    else
        mini_printf("hit\n");
}

void print_touched_receive(int touched)
{
    if (touched == 2)
        mini_printf("hit\n");
    else
        mini_printf("missed\n");
}
