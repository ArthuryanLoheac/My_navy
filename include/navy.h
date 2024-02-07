/*
** EPITECH PROJECT, 2023
** navy.h
** File description:
** navy.h
*/

#ifndef NAVY_
    #define NAVY_

    #include "struct.h"

int player_one(char **argv);
int player_two(char **argv);
int print_help(void);
void wait_for_connection(void);
void print_my_pid(void);
int connecte_to_p_one(char *str_id);
void send_int(int pid, int number);
int check_data(char *path);
boat *get_boats(char *path);
void set_received_number(void);
char **create_empty_board(void);
void print_turn(char **board, char **ennemy_board);
int convert_square(char *square);
int get_move(void);
char **set_board_boats(char **board, boat *boats);
char *convert_nbr_to_coord(int nbr);
int win_loose(char **board, char **ennemy_board);
int wait_receive_nb(void);
int is_touched(int pos, char **board);
void print_is_touched(int played, char **board);
char *coonvert_to_case(int played);
void print_touched_receive(int touched);
void play_move_board(char **board, int played, int touched);
void ennemy_turn(char **board, int id);
void player_turn(char **ennemy_board, int id);

#endif /* !NAVY_ */
