/*
** EPITECH PROJECT, 2024
** set_board_boats.c
** File description:
** set_the boats in the empty board
*/
#include "my.h"
#include <stdio.h>

static void place_boat_horizontal(char **board, char *start,
    char *end, int len)
{
    for (int i = start[1]; i <= end[1]; i++) {
        board[start[0] - '0'][i - '0'] = len + '0';
    }
}

static void place_boat_horizontal_reverse(char **board, char *start,
    char *end, int len)
{
    for (int i = end[1]; i <= start[1]; i++) {
        board[start[0] - '0'][i - '0'] = len + '0';
    }
}

static void place_boat_vertical(char **board, char *start,
    char *end, int len)
{
    for (int i = start[0]; i <= end[0]; i++) {
        board[i - '0'][start[1] - '0'] = len + '0';
    }
}

static void place_boat_vertical_reverse(char **board, char *start,
    char *end, int len)
{
    for (int i = end[0]; i <= start[0]; i++) {
        board[i - '0'][start[1] - '0'] = len + '0';
    }
}

static void set_boat(char **board, char *start, char *end, int len)
{
    if (start[0] == end[0]) {
        if (start[1] < end[1]) {
            place_boat_horizontal(board, start, end, len);
        } else {
            place_boat_horizontal_reverse(board, start, end, len);
        }
    } else {
        if (start[0] < end[0]) {
            place_boat_vertical(board, start, end, len);
        } else {
            place_boat_vertical_reverse(board, start, end, len);
        }
    }
}

char **set_board_boats(char **board, boat *boats)
{
    char *start = NULL;
    char *end = NULL;

    for (int i = 0; i < 4; i++) {
        start = convert_nbr_to_coord(convert_square(boats[i].start));
        end = convert_nbr_to_coord(convert_square(boats[i].end));
        set_boat(board, start, end, boats[i].length);
    }
    return board;
}
