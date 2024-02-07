/*
** EPITECH PROJECT, 2024
** is_touched.c
** File description:
** is_touched.c
*/
#include "my.h"

int is_touched(int pos, char **board)
{
    char *position = convert_nbr_to_coord(pos);

    if (board[position[0] - '0'][position[1] - '0'] == '.')
        return 0;
    if (board[position[0] - '0'][position[1] - '0'] == 'o')
        return 0;
    return 1;
}
