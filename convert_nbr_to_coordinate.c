/*
** EPITECH PROJECT, 2024
** convert_nbr_to_coordinates.c
** File description:
** convert the number given to a set of coordinates
*/

#include "my.h"

char *convert_nbr_to_coord(int nbr)
{
    char *coordinate = malloc(sizeof(char)*3);

    coordinate[0] = '0';
    coordinate[1] = '0';
    coordinate[2] = '\0';
    nbr--;
    while (nbr > 0) {
        coordinate[1]++;
        if (coordinate[1] == '8') {
            coordinate[1] = '0';
            coordinate[0]++;
        }
        nbr--;
    }
    return (coordinate);
}
