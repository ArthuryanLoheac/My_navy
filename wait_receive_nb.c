/*
** EPITECH PROJECT, 2024
** wait to receive
** File description:
** wait to receive a number and return it
*/
#include "my.h"

int wait_receive_nb(void)
{
    int data_save = datas.data;

    while (data_save == datas.data) {
        data_save = datas.data;
        usleep(100);
    }
    return datas.data;
}
