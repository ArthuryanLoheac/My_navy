/*
** EPITECH PROJECT, 2024
** wait_for_connection
** File description:
** wiat for the connection of the player 2
*/
#include "my.h"

id_datas datas = {0};

static void wait_receive(int signal, siginfo_t *b, void *c)
{
    signal = signal;
    datas.pid_adverse = b->si_pid;
    b = b;
    c = c;
}

void print_my_pid(void)
{
    pid_t pid = getpid();

    mini_printf("my_pid: %d\n\n", pid);
}

void wait_for_connection(void)
{
    struct sigaction act = {0};

    act.sa_sigaction = &wait_receive;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &act, NULL);
    print_my_pid();
    mini_printf("waiting for enemy...\n");
    while (datas.pid_adverse == 0) {
    }
    mini_printf("\nenemy connected\n", datas.pid_adverse);
}
