NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes -I Libft

SRC =  src/main.c \
	   src/lst_utils.c \
       src/parsing/user_input.c \
	   src/parsing/stack.c \
       src/algo/sort.c \
       src/algo/calcul_cost.c \
       src/algo/turk_algo.c \
       src/operation/operation1.c \
       src/operation/operation2.c \
       src/operation/operation3.c

OBJ = $(SRC:.c=.o)

LIBFT = Libft/libft.a

all: $(NAME)

$(LIBFT):
	$(MAKE) -C Libft


$(NAME): $(OBJ) $(LIBFT) 
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all