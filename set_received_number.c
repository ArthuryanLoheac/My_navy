/*
** EPITECH PROJECT, 2024
** set_received_number
** File description:
** set the sigaction SIGUSR1 and 2 to recieve a number
*/
#include "my.h"

static void print_good_nb(int nb, int nb_save)
{
    if (nb >= nb_save)
        datas.data = nb;
    else
        datas.data = nb_save;
}

static void count_received(int signal, siginfo_t *b, void *c)
{
    static int number = 0;
    static int number_save = 0;
    static int i = 0;

    if (signal == SIGUSR1)
        number += 1;
    if (signal == SIGUSR2) {
        if (i == 0) {
            i = 1;
            number_save = number;
            number = 0;
        } else {
            i = 0;
            print_good_nb(number, number_save);
            number = 0;
        }
    }
    b = b;
    c = c;
}

void set_received_number(void)
{
    struct sigaction act = {0};

    act.sa_sigaction = &count_received;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
}
