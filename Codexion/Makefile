NAME = codexion

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes

SRC =  src/main.c \
       src/parsing/args_parsing.c \
	   src/parsing/get_data.c \
	   src/init/init.c \
	   src/routine/work.c \
	   src/utils/ft_message.c \
	   src/utils/ft_usleep.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all