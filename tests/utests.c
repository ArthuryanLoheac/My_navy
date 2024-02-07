/*
** EPITECH PROJECT, 2024
** utests 
** File description:
** unit tests
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(NAVY, help, .init = redirect_all_std)
{
    char *str = "USAGE\n    ./navy [first_player_pid] navy_positions\nDESCRIPTION\n    first_player_pid: only for the 2nd player. pid of the first player.\n    navy_positions: file representing the positions of the ships.\n";
    print_help();
    cr_assert_stdout_eq_str(str);
}

Test(NAVY, loose)
{
    char *board[] =    {  ".55555.3",
                            ".......3",
                            ".......3",
                            "..22....",
                            "........",
                            "....4444",
                            "........",
                            "........"};
    char *board_2[] =    {  "........",
                            "........",
                            "........",
                            "........",
                            "........",
                            "........",
                            "........",
                            "........"};
    cr_assert(win_loose(board, board_2) == 0);
}

Test(NAVY, win_our)
{
    char *board[] =    {  ".xxxxx.x",
                            ".......x",
                            ".......x",
                            "..xx....",
                            "........",
                            "....xxxx",
                            "........",
                            "........"};

    char *board_2[] =    {  "........",
                            "........",
                            "........",
                            "........",
                            "........",
                            "........",
                            "........",
                            "........"};
    cr_assert(win_loose(board, board_2) == 1);
}

Test(NAVY, win_ennemy)
{
    char *board[] =    {  ".xxxxx.x",
                            ".......x",
                            ".......x",
                            "..xx....",
                            "........",
                            "....xx2x",
                            "........",
                            "........"};

    char *board_2[] =    {  "........",
                            "x..xxxx.",
                            "x......x",
                            "x......x",
                            "x...x...",
                            "x...x...",
                            "....x...",
                            "........"};
    cr_assert(win_loose(board, board_2) == 2);
}

Test(NAVY, is_touched)
{
    char **empt = create_empty_board();
    boat *boats = get_boats("tests/player1.txt");
    char **board = set_board_boats(empt, boats);
    cr_assert(is_touched(1, board) == 0);
}

Test(NAVY, is_touched_2)
{
    char **empt = create_empty_board();
    boat *boats = get_boats("tests/player1.txt");
    char **board = set_board_boats(empt, boats);
    cr_assert(is_touched(3, board) == 1);
}

Test(NAVY, setsid)
{
    char **empt = create_empty_board();
    boat *boats = get_boats("tests/player1.txt");
    char **board = set_board_boats(empt, boats);
    char *board_2[] =    {  "..2.....",
                            "..2.....",
                            "........",
                            "...333..",
                            ".4......",
                            ".4......",
                            ".4.55555",
                            ".4......"};
    for (int i = 0; i < 8; i++) {
        cr_assert_str_eq(board[i], board_2[i]);
    }
}

Test(NAVY, setsid_2)
{
    char **empt = create_empty_board();
    boat *boats = get_boats("tests/player2.txt");
    char **board = set_board_boats(empt, boats);
    char *board_2[] =    {  ".55555.3",
                            ".......3",
                            ".......3",
                            "..22....",
                            "........",
                            "....4444",
                            "........",
                            "........"};
    for (int i = 0; i < 8; i++) {
        cr_assert_str_eq(board[i], board_2[i]);
    }
}

Test(NAVY, err)
{
    boat *boats = get_boats("tests/error_3.txt");

    cr_assert(boats == NULL);
}

Test(NAVY, 6)
{
    boat *boats = get_boats("tests/6.txt");

    cr_assert(boats == NULL);
}

Test(NAVY, 7)
{
    boat *boats = get_boats("tests/7.txt");

    cr_assert(boats == NULL);
}

Test(NAVY, 8)
{
    boat *boats = get_boats("tests/8.txt");

    cr_assert(boats == NULL);
}

Test(NAVY, 9)
{
    boat *boats = get_boats("tests/9.txt");

    cr_assert(boats == NULL);
}

Test(NAVY, 10)
{
    boat *boats = get_boats("tests/10.txt");

    cr_assert(boats == NULL);
}

Test(NAVY, 11)
{
    boat *boats = get_boats("tests/11.txt");

    cr_assert(boats == NULL);
}

Test(NAVY, 12)
{
    boat *boats = get_boats("tests/12.txt");

    cr_assert(boats == NULL);
}

Test(NAVY, boats_err)
{
    boat *boats = get_boats("FGHYUI");

    cr_assert(boats == NULL);
}

Test(NAVY, boats_err_2)
{
    boat *boats = get_boats("tests/error_void.txt");

    cr_assert(boats == NULL);
}

Test(NAVY, boats_err_3)
{
    boat *boats = get_boats("tests/error_wrong.txt");

    cr_assert(boats == NULL);
}

Test(NAVY, boats_err_4)
{
    boat *boats = get_boats("tests/player1.txt");

    cr_assert(boats[0].length == 2);
    cr_assert(boats[1].length == 3);
    cr_assert(boats[2].length == 4);
    cr_assert(boats[3].length == 5);
}

Test(NAVY, boats_err_5)
{
    boat *boats = get_boats("tests/error_5.txt");

    cr_assert(boats == NULL);
}

Test(NAVY, create_empty_board)
{
    char **empt = create_empty_board();

    for (int i = 0; i < 8; i++) {
        cr_assert_str_eq(empt[i], "........");
    }
}

Test(NAVY, coonvert_to_case)
{
    cr_assert_str_eq(coonvert_to_case(1), "A1");
}

Test(NAVY, convert_square_2)
{
    cr_assert(convert_square("A1") == 1);
    cr_assert(convert_square("B1") == 2);
    cr_assert(convert_square("C1") == 3);
    cr_assert(convert_square("D1") == 4);
    cr_assert(convert_square("E1") == 5);
    cr_assert(convert_square("F1") == 6);
    cr_assert(convert_square("G1") == 7);
    cr_assert(convert_square("H1") == 8);

    cr_assert(convert_square("A2") == 9);
    cr_assert(convert_square("A3") == 17);
    cr_assert(convert_square("A4") == 25);
    cr_assert(convert_square("A5") == 33);
    cr_assert(convert_square("A6") == 41);
    cr_assert(convert_square("A7") == 49);
    cr_assert(convert_square("A8") == 57);

}

Test(NAVY, errors)
{
    cr_assert(convert_square("H9") == 84);
    cr_assert(convert_square("Z1") == 84);
    cr_assert(convert_square("ZZZ1") == 84);
}

Test(NAVY, nbr_to_cord)
{
    char *str = convert_nbr_to_coord(1);
    cr_assert_str_eq(str, "00");
}

Test(NAVY, nbr_to_cord_last)
{
    char *str = convert_nbr_to_coord(64);
    cr_assert_str_eq(str, "77");
}

Test(NAVY, good_file)
{
    cr_assert(check_data("tests/player1.txt") == 0);
}

Test(NAVY, error_file)
{
    cr_assert(check_data("tests/error_1.txt") == 84);
}

Test(NAVY, error_file_2)
{
    cr_assert(check_data("tests/error_2.txt") == 84);
}

Test(NAVY, error_file_3)
{
    cr_assert(check_data("tests/error_3.txt") == 84);
}

Test(NAVY, error_file_4)
{
    cr_assert(check_data("tests/error_4.txt") == 84);
}
