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

OBJS = $(FILES: .c=.o)

INC = ./src/push_swap.h \

NAME = push_swap

CC = gcc
FLAGS = -Wall -Wextra -Werror

.c.o : 
	$(CC) $(FLAGS) -g -c $< -o $(<:.c=.o)

$(NAME): $(OBJ) 
		$(CC) $(FLAGS) -g $(OBJS) -o $(NAME)

all: $(NAME)


clean : 
	rm -f *.o 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean re fclean