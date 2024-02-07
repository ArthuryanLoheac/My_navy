/*
** EPITECH PROJECT, 2024
** create_empty_board.c
** File description:
** create an empty board of 8x8
*/
#include "my.h"

char **create_empty_board(void)
{
    char **board = malloc(sizeof(char *) * 8);

    if (board == NULL)
        return NULL;
    for (int i = 0; i < 8; i++) {
        board[i] = malloc(sizeof(char)*9);
        if (board[i] == NULL) {
            return NULL;
        }
        for (int j = 0; j < 8; j++)
            board[i][j] = '.';
    }
    return board;
}
