/*
** EPITECH PROJECT, 2024
** player_one
** File description:
** player_one
*/
#include "my.h"
#include <stdio.h>

static int play(boat *boats, char **board, char **ennemy_board)
{
    board = set_board_boats(board, boats);
    while (win_loose(board, ennemy_board) == 0) {
        print_turn(board, ennemy_board);
        player_turn(ennemy_board, datas.pid_adverse);
        if (win_loose(board, ennemy_board) != 0)
            break;
        ennemy_turn(board, datas.pid_adverse);
    }
    print_turn(board, ennemy_board);
    if (win_loose(board, ennemy_board) == 2)
        mini_printf("\nI won\n");
    else
        mini_printf("\nEnemy won\n");
    return 0;
}

int player_one(char **argv)
{
    boat *boats = get_boats(argv[1]);
    char **board = create_empty_board();
    char **ennemy_board = create_empty_board();

    if (boats == NULL)
        return -1;
    wait_for_connection();
    set_received_number();
    if (board == NULL)
        return -1;
    return play(boats, board, ennemy_board);
}
