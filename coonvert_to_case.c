/*
** EPITECH PROJECT, 2024
** coonvert_to_case
** File description:
** coonvert_to_case
*/
#include "my.h"

char *coonvert_to_case(int played)
{
    char *str = malloc(sizeof(char) * 3);
    char *played_convert = convert_nbr_to_coord(played);

    str[0] = played_convert[1] + 17;
    str[1] = played_convert[0] + 1;
    str[2] = '\0';
    return str;
}
