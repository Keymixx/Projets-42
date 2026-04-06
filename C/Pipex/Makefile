
NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes -I Libft

SRC =  src/pipex.c

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
