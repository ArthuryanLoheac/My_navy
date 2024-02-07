/*
** EPITECH PROJECT, 2024
** convert_case_to_nbr.c
** File description:
** convert the square of the boat to a number
*/

#include "my.h"

static int get_coord(char coord_chara)
{
    if (coord_chara == 'A')
        return (7);
    if (coord_chara == 'B')
        return (6);
    if (coord_chara == 'C')
        return (5);
    if (coord_chara == 'D')
        return (4);
    if (coord_chara == 'E')
        return (3);
    if (coord_chara == 'F')
        return (2);
    if (coord_chara == 'G')
        return (1);
    if (coord_chara == 'H')
        return (0);
    return (84);
}

static int verif_nbr(char coord_nbr)
{
    if (coord_nbr == '1')
        return (1);
    if (coord_nbr == '2')
        return (2);
    if (coord_nbr == '3')
        return (3);
    if (coord_nbr == '4')
        return (4);
    if (coord_nbr == '5')
        return (5);
    if (coord_nbr == '6')
        return (6);
    if (coord_nbr == '7')
        return (7);
    if (coord_nbr == '8')
        return (8);
    return (84);
}

int convert_square(char *square)
{
    int coord_chara;
    int coord_nbr;

    if (my_strlen(square) != 2){
        return (84);
    }
    coord_nbr = verif_nbr(square[1]);
    coord_chara = get_coord(square[0]);
    if (coord_chara == 84 || coord_nbr == 84){
        return (84);
    }
    return (8 * coord_nbr - coord_chara);
}
