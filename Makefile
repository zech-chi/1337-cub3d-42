NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

SRCS =  main.c \
		get_next_line/get_next_line_utils.c \
		get_next_line/get_next_line.c \
		tools/split.c \
		tools/putstr_fd.c \
		parsing/parsing.c \
		tools/strcmp.c \
		tools/isvalid.c \
		tools/openfile.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c include/cub3d.h
	@$(CC) $(CFLAGS) -c $< -o $@ && \
	echo "compilation file name $< done ✅" || \
	(echo "compilation of $< failed ❌" && exit 1)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@ && \
	echo "create executable file ${NAME} done ✅" || \
	(echo "create executable file ${NAME} failed ❌" && exit 1)

clean:
	@$(RM) $(OBJS) && \
	echo "delete objects files ${OBJS} done ✅" || \
	echo "delete objects files ${OBJS} failed ❌"

fclean: clean
	@$(RM) $(NAME) && \
	echo "delete executable file ${NAME} done ✅" || \
	echo "delete executable file ${NAME} failed ❌"

re: fclean all

.PHONY: all clean fclean re
