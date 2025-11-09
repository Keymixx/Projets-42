NAME = push_swap.a
SRCS = Libft/*.c ft_printf/*.c main.c
OBJS = $(SRCS:.c=.o)

CC = cc
RM = rm -f
CFLAGS	= -Wall -Wextra -Werror -I.


all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus