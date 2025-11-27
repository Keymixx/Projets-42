NAME		= so_long

CC		= cc
CFLAGS		= -Wall -Wextra -Werror
MLXFLAGS	= -Lminilibx-linux -lmlx -lXext -lX11 -lm

SRCS		=	srcs/so_long.c \
				srcs/parsing/check_map_size.c \
				srcs/parsing/check_file.c \
				srcs/parsing/create_map.c \
				srcs/event/close_win.c

OBJS		= $(SRCS:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(MLXFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re