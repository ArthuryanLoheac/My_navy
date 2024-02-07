/*
** EPITECH PROJECT, 2024
** print_help
** File description:
** print_help
*/
#include "my.h"

int print_help(void)
{
    mini_printf("USAGE\n");
    mini_printf("    ./navy [first_player_pid] navy_positions\n");
    mini_printf("DESCRIPTION\n");
    mini_printf("    first_player_pid: only for the 2nd player.");
    mini_printf(" pid of the first player.\n");
    mini_printf("    navy_positions: file representing the positions");
    mini_printf(" of the ships.\n");
    return 0;
}
