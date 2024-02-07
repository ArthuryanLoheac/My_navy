/*
** EPITECH PROJECT, 2024
** print turn
** File description:
** print the board and ennemy board
*/
#include "my.h"

static void display_space(int j)
{
    if (j != 7)
        mini_printf(" ");
    else
        mini_printf("\n");
}

static void print_board(char **board)
{
    mini_printf(" |A B C D E F G H\n");
    mini_printf("-+---------------\n");
    for (int i = 0; i < 8; i++) {
        mini_printf("%d|", i + 1);
        for (int j = 0; j < 8; j++) {
            mini_printf("%c", board[i][j]);
            display_space(j);
        }
    }
}

void print_turn(char **board, char **ennemy_board)
{
    mini_printf("\nmy navy:\n");
    print_board(board);
    mini_printf("\nenemy navy:\n");
    print_board(ennemy_board);
}
