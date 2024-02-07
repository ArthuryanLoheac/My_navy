/*
** EPITECH PROJECT, 2024
** win_loose
** File description:
** win_loose
*/
#include "my.h"

static int is_number(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

static int is_x(char c)
{
    if (c == 'x')
        return 1;
    return 0;
}

int win_loose(char **board, char **ennemy_board)
{
    int loose = 0;
    int win = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
            loose += is_number(board[i][j]);
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
            win += is_x(ennemy_board[i][j]);
    }
    if (loose == 0)
        return 1;
    if (win == 14)
        return 2;
    return 0;
}
