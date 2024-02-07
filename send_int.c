/*
** EPITECH PROJECT, 2024
** send_int.c
** File description:
** send x USR1 to the pid given then to end send a USR2
*/
#include "my.h"

void send_int(int pid, int number)
{
    for (int i = 0; i < 2; i++) {
        for (int i = 0; i < number; i++) {
            kill(pid, SIGUSR1);
            usleep(100);
        }
        usleep(100);
        kill(pid, SIGUSR2);
        usleep(100);
    }
}
