NAME = codexion

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes

SRC =  src/main.c \
       src/parsing/args_parsing.c \
	   src/parsing/get_rules.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all