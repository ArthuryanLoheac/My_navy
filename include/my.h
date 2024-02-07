/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_

    #include "navy.h"
    #include "struct.h"
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <signal.h>

extern id_datas datas;

int my_strlen(char const *str);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);
int mini_printf(const char *format, ...);
int my_compute_power_rec(int nb, int p);
int my_getnbr(char const *str);

#endif /* !MY_H_ */
