NAME = bsq
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

SRCS = srcs/main.c srcs/utils.c srcs/map_utils.c srcs/map_parsing.c \
       srcs/map_header.c srcs/bsq_solver.c srcs/display.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
