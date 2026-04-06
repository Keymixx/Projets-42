NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes -I Libft

SRC =  src/main.c \
	   src/lst_utils/lst_utils1.c \
	   src/lst_utils/lst_utils2.c \
       src/parsing/user_input.c \
	   src/parsing/stack.c \
       src/algo/sort.c \
       src/algo/calcul_cost.c \
       src/algo/turk_algo.c \
	   src/algo/handmade_sort.c \
       src/operation/operation1.c \
       src/operation/operation2.c \
       src/operation/operation3.c \
	   src/parsing/free_split.c

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