##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	player_one.c	\
		player_two.c	\
		print_help.c 	\
		wait_for_connection.c	\
		connection_to_player_one.c	\
		send_int.c	\
		check_data.c \
		get_boats.c	\
		set_received_number.c	\
		create_empty_board.c	\
		print_turn.c 	\
		convert_square_to_nbr.c	\
		get_move.c	\
		convert_nbr_to_coordinate.c \
		set_board_boats.c	\
		win_loose.c	\
		is_touched.c	\
		wait_receive_nb.c	\
		print_is_touched.c	\
		coonvert_to_case.c	\
		play_turns.c	\

CFLAGS	=	-Wall -Wextra -Werror -I./include/	\
			-L./lib/my/ -lmy	\

SRC_LIB	=	lib/my/my_strcmp.c	\
			lib/my/mini_printf.c	\
			lib/my/my_put_nbr.c	\
			lib/my/my_putchar.c	\
			lib/my/my_putstr.c	\
			lib/my/my_strlen.c	\
			lib/my/my_getnbr.c	\
			lib/my/my_compute_power_rec.c	\

CFLAGS_LIB 	=	-I./include/ -Werror -Wall -Wextra

OBJ	=	$(SRC_LIB:.c=.o)

NAME	=	my_navy

SRC_TESTS =		tests/utests.c	\

FLAGS_TEST	=	-Wall -Wextra -Werror -I./include/	\
				-L./lib/my/ -lmy	\
				-lcriterion --coverage	\

all: libmy.a
	gcc -o $(NAME) $(SRC) main.c $(CFLAGS)

libmy.a:	$(OBJ)
	gcc -c $(SRC_LIB) $(CFLAGS_LIB)
	ar rc lib/my/libmy.a $(OBJ)
	find -name "*.o" -delete

clean:
	rm -f *.gcda
	rm -f *.gcno

fclean: clean
	rm -f lib/my/libmy.a
	rm -f unit_tests
	rm -f $(NAME)

re: fclean all

unit_tests: re
	gcc -o unit_tests $(SRC_TESTS) $(SRC) $(FLAGS_TEST)

tests_run: unit_tests
	./unit_tests
