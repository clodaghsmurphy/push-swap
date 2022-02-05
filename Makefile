FILES = ./src/checkargs.c \
		./src/costs.c \
		./src/dub_moves.c \
		./src/index.c \
		./src/insert_sort.c \
		./src/list.c \
		./src/main.c \
		./src/moves.c \
		./src/moveto_b.c \
		./src/parse.c \
		./src/push_swap.c \
		./src/set_moves.c \
		./src/tab.c \
		./src/utils.c \
		./src/common_move.c \
		./src/get_cost.c \
		./src/special_case.c \
		./src/checkargs2.c \

BONUS = ./my_checker/checker.c \
		./my_checker/checkargs_checker.c \
		./my_checker/checkargs2_checker.c \
		./my_checker/tab_checker.c \
		./my_checker/moves_checker.c \
		./my_checker/list_checker.c \
		./my_checker/get_next_line.c \
		./my_checker/dub_moves_checker.c \
		./my_checker/get_next_line_utils.c \
		./my_checker/utils_checker.c 

BONUS_OBJS = $(BONUS:.c=.o)

OBJS = $(FILES:.c=.o)

INC = ./src/push_swap.h \

BONUS_NAME = checker

NAME = push_swap

CC = gcc
FLAGS = -Wall -Wextra -Werror


all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJS) $(INC)
		$(CC) $(FLAGS) $(OBJS) $(INC) -g -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJS) 
		$(CC) $(FLAGS) $(BONUS_OBJS) -g -o $(BONUS_NAME)

clean : 
	rm -f ./src/*.o ./my_checker/*.o 

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)


re: fclean all

.PHONY: clean re fclean