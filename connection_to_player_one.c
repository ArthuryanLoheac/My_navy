/*
** EPITECH PROJECT, 2024
** connection_to_player_one.c
** File description:
** connecte the player 2 to the player 1
*/
#include "my.h"

int connecte_to_p_one(char *str_id)
{
    int id = 0;

    if (str_id == NULL)
        return -1;
    id = my_getnbr(str_id);
    if (id < 1) {
        return -1;
    }
    if (kill(id, SIGUSR1) == -1)
        return -1;
    print_my_pid();
    mini_printf("successfully connected to enemy\n");
    return id;
}
