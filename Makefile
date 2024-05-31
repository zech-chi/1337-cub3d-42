NAME =  cub3D

CC = cc

# to remove -fsanitize=address
CFLAGS = -Wall -Wextra -Werror -fsanitize=address

SRCS =  main.c \
		get_next_line/get_next_line_utils.c \
		get_next_line/get_next_line.c \
		tools/split.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c include/cub3d.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $^ -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
