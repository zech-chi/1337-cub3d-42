NAME =  cub3D

CC = cc

# to remove -fsanitize=address
CFLAGS = -Wall -Wextra -Werror -fsanitize=address

SRCS =  main.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c include/cub3d.h
	@$(CC) $(CFLAGS) -c $< -o $@ && \
	echo "compilation file name $^ done ✅" || \
	(echo "compilation of $^ failed ❌" && exit 1)

$(NAME): $(OBJS)
	@$(CC) $^ -o $@ && \
	echo "create executable file  ${Name} done ✅" || \
	(echo "create executable file ${NAME} failed ❌" && exit 1)

clean:
	@$(RM) $(OBJS) && \
	echo "delete objects files ${OBJS} done ✅" || \
	echo "delete objects files ${OBJS} failed ❌"

fclean: clean
	@$(RM) $(NAME) && \
	echo "delete executable file ${Name} done ✅" || \
	echo "delete executable file ${NAME} failed ❌"

re: fclean all

.PHONY: all clean fclean re
