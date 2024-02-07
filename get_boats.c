/*
** EPITECH PROJECT, 2024
** get_boats
** File description:
** return the list of boats or NULL if there is an error in the file
*/
#include "my.h"

static int check_void(char *path)
{
    int file = open(path, O_RDONLY);
    char c = 0;

    if (read(file, &c, 1) == 0) {
        close(file);
        return -1;
    }
    close(file);
    return 0;
}

static int check_good_file(char *path)
{
    int file = open(path, O_RDONLY);

    if (file == -1)
        return -1;
    close(file);
    return 0;
}

static int count_char(char c, int *nb_line, int *nb_char, int file)
{
    (*nb_char)++;
    if (c == '\n') {
        if (*nb_char != 8) {
            close(file);
            return -1;
        }
        *nb_char = 0;
        (*nb_line)++;
    }
    return 0;
}

static int return_error(int file, char c, int nb_line)
{
    if (read(file, &c, 1) > 0)
        return -1;
    if (nb_line != 4) {
        close(file);
        return -1;
    }
    close(file);
    return 0;
}

static int check_number_line(char *path)
{
    int file = open(path, O_RDONLY);
    char c = 0;
    int nb_line = 0;
    int nb_char = 0;

    while (read(file, &c, 1) > 0) {
        if (count_char(c, &nb_line, &nb_char, file) == -1)
            return -1;
        if (nb_line == 4)
            break;
    }
    return return_error(file, c, nb_line);
}

static int check_str(char *str)
{
    if (str[0] < '2' || str[0] > '5')
        return -1;
    if (str[1] != ':')
        return -1;
    if (str[2] < 'A' || str[2] > 'H')
        return -1;
    if (str[3] < '1' || str[3] > '8')
        return -1;
    if (str[4] != ':')
        return -1;
    if (str[5] < 'A' || str[5] > 'H')
        return -1;
    if (str[6] < '1' || str[6] > '8')
        return -1;
    return 0;
}

static boat *stock_value(char *path)
{
    int file = open(path, O_RDONLY);
    boat *boats = malloc(sizeof(boat) * 4);
    char c[8] = {0};
    int i = 0;

    while (read(file, c, 7) > 0) {
        if (check_str(c) == -1)
            return NULL;
        boats[i].length = c[0] - '0';
        boats[i].start[0] = c[2];
        boats[i].start[1] = c[3];
        boats[i].start[2] = 0;
        boats[i].end[0] = c[5];
        boats[i].end[1] = c[6];
        boats[i].end[2] = 0;
        read(file, c, 1);
        i++;
    }
    return boats;
}

boat *get_boats(char *path)
{
    boat *boats = NULL;

    if (check_good_file(path) == -1)
        return NULL;
    if (check_void(path) == -1)
        return NULL;
    if (check_number_line(path) == -1)
        return NULL;
    boats = stock_value(path);
    if (boats == NULL)
        return NULL;
    if (check_data(path) == 84)
        return NULL;
    return boats;
}
