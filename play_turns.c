/*
** EPITECH PROJECT, 2024
** play_turns.c
** File description:
** ennemy and our play turn
*/
#include "my.h"

void ennemy_turn(char **board, int id)
{
    int played = 0;

    mini_printf("\nwaiting for enemy's attack...");
    played = wait_receive_nb() - 1;
    mini_printf("\n\nresult: %s:", coonvert_to_case(played));
    print_is_touched(played, board);
    send_int(id, is_touched(played, board) + 1);
    play_move_board(board, played, is_touched(played, board));
}

void player_turn(char **ennemy_board, int id)
{
    int played = 0;
    int touched = 0;

    played = get_move();
    send_int(id, played + 1);
    mini_printf("\nresult: %s:", coonvert_to_case(played));
    touched = wait_receive_nb();
    print_touched_receive(touched);
    play_move_board(ennemy_board, played, touched - 1);
}
