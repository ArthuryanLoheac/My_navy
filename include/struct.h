/*
** EPITECH PROJECT, 2023
** struct.h
** File description:
** struct.h
*/

#ifndef STRUCT_
    #define STRUCT_

    #include "navy.h"
    #include "struct.h"
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <signal.h>

typedef struct {
    int length;
    char start[3];
    char end[3];
} boat;

typedef struct {
    pid_t pid_adverse;
    int data;
} id_datas;

#endif /* !STRUCT_ */
