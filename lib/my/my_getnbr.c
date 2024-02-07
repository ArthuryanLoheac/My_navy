/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** get the number from a string
*/
#include "my.h"

static int valid_numbers(int start, char const *str, int len)
{
    for (int i = -start; i < len; i++) {
        if (str[i] > '9' || str[i] < '0') {
            return 1;
        }
    }
    return 0;
}

static int get_start(char const *str)
{
    if (str[0] == '-')
        return -1;
    return 0;
}

static int check_pos_max(int start, char const *str)
{
    char max_pos[] = "2147483647";

    for (int i = 0; i <= (9 - start); i++) {
        if (str[i] > max_pos[i]) {
            return 1;
        }
    }
    return 0;
}

static int check_pos_neg(int start, char const *str)
{
    char max_neg[] = "2147483648";

    for (int i = 1; i <= (9 - start); i++) {
        if (str[i] > max_neg[i - 1])
            return 1;
    }
    return 0;
}

static int is_int(int start, char const *str, int len)
{
    if (len > (10 - start))
        return 1;
    if (len < (9 - start))
        return 0;
    if (start == 0) {
        return check_pos_max(start, str);
    } else {
        return check_pos_neg(start, str);
    }
}

int my_getnbr(char const *str)
{
    int len = my_strlen(str);
    int start = get_start(str);
    int value = 0;

    if (valid_numbers(start, str, len))
        return 0;
    if (is_int(start, str, len))
        return 0;
    if (start == 0) {
        for (int i = len; i > 0; i -= 1) {
            value += (str[len - i] - '0') * my_compute_power_rec(10, i - 1);
        }
    } else {
        for (int i = len - 1; i > 0; i -= 1) {
            value += (str[len - i] - '0') * my_compute_power_rec(10, i - 1);
        }
        value *= -1;
    }
    return value;
}
