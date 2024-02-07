/*
** EPITECH PROJECT, 2024
** check_data.c
** File description:
** check if the boat are correct
*/

#include "my.h"

static int check_size(char *path)
{
    int file = open(path, O_RDONLY);
    char data[32];
    int i = 0;
    int size_boat = 2;

    read(file, data, 32);
    while (i < 4){
        if (data[0 + (8 * i)] != size_boat + 48){
            return (84);
        }
        i = i + 1;
        size_boat = size_boat + 1;
    }
    return (0);
}

static int check_position(char *path)
{
    int file = open(path, O_RDONLY);
    char data[32];
    int i = 0;
    int verif = 0;

    read(file, data, 32);
    while (i < 4){
        if (data[2 + (8 * i)] != data[5 + (8 * i)]){
            verif = verif + 1;
        }
        if (data[3 + (8 * i)] != data[6 + (8 * i)]){
            verif = verif + 1;
        }
        if (verif != 1){
            return (84);
        }
        i = i + 1;
        verif = 0;
    }
    return (0);
}

static int wich_equal(char *data, int coll, int line, int line_data)
{
    if (data[coll + (8 * line_data)] == data[coll + 3 + (8 * line_data)]){
        return (1);
    }
    if (data[line + (8 * line_data)] == data[line + 3 + (8 * line_data)]){
        return (2);
    }
    return (0);
}

int real_size(int start, int end, int size)
{
    int verif = abs(end - start) + 1;

    if (verif != size){
        return (84);
    }
    return (verif);
}

int check_size_coordinate(char *path)
{
    int file = open(path, O_RDONLY);
    char data[32];
    int i = 0;
    int verif = 0;
    int line_or_col = 0;

    read(file, data, 32);
    while (i < 4){
        line_or_col = wich_equal(data, 2, 3, i);
        if (line_or_col == 1)
            verif = real_size(data[3 + (8 * i)], data[6 + (8 * i)], i + 2);
        if (line_or_col == 2)
            verif = real_size(data[2 + (8 * i)], data[5 + (8 * i)], i + 2);
        if (verif != i + 2)
            return (84);
        i = i + 1;
    }
    return (0);
}

int check_data(char *path)
{
    if (check_size(path) == 84){
        return (84);
    }
    if (check_position(path) == 84){
        return (84);
    }
    if (check_size_coordinate(path) == 84){
        return (84);
    }
    return (0);
}
