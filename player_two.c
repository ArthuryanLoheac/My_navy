/*
** EPITECH PROJECT, 2024
** player_two
** File description:
** player_two
*/
#include "my.h"

void play_move_board(char **board, int played, int touched)
{
    char *pos = convert_nbr_to_coord(played);

    if (touched == 1) {
        board[pos[0] - '0'][pos[1] - '0'] = 'x';
    } else {
        board[pos[0] - '0'][pos[1] - '0'] = 'o';
    }
}

static int play(boat *boats, int id_one, char **board, char **ennemy_board)
{
    board = set_board_boats(board, boats);
    while (win_loose(board, ennemy_board) == 0) {
        print_turn(board, ennemy_board);
        ennemy_turn(board, id_one);
        if (win_loose(board, ennemy_board) != 0)
            break;
        player_turn(ennemy_board, id_one);
    }
    print_turn(board, ennemy_board);
    if (win_loose(board, ennemy_board) == 2)
        mini_printf("\nI won\n");
    else
        mini_printf("\nEnemy won\n");
    return 0;
}

int player_two(char **argv)
{
    boat *boats = get_boats(argv[2]);
    char **board = create_empty_board();
    char **ennemy_board = create_empty_board();
    int id_one = 0;

    boats = get_boats(argv[2]);
    if (boats == NULL)
        return -1;
    id_one = connecte_to_p_one(argv[1]);
    if (id_one == -1)
        return -1;
    set_received_number();
    usleep(100);
    return play(boats, id_one, board, ennemy_board);
}
