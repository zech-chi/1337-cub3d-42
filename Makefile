NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror -Ofast -fsanitize=address 

SRCS =  main.c \
		to_remove/display.c \
		get_next_line/get_next_line_utils.c \
		get_next_line/get_next_line.c \
		malloc/free_data.c \
		malloc/malloc_safely.c \
		tools/isvalid.c \
		tools/openfile.c \
		tools/putstr_fd.c \
		tools/skip_space.c \
		tools/split.c \
		tools/strcmp.c \
		tools/strncmp.c \
		tools/substr.c \
		tools/itoa.c \
		parsing/create_map.c \
		parsing/get_color.c \
		parsing/parsing.c \
		parsing/scan_file.c \
		parsing/scan_line_1.c \
		parsing/scan_line_2.c \
		parsing/scan_map.c \
		linked_list/linked_list.c \
		draw/walls.c \
		draw/draw_imgs.c \
		player/player.c \
		player/mouse.c \
		player/walk.c \
		player/turn.c \
		player/look.c \
		player/light.c \
		player/weapon.c \
		music/play_music.c \
		math/math_tools.c \
		raycasting/rays.c \
		minimap/minimap.c \
		minimap/minimap_big.c

OBJS = $(SRCS:.c=.o)

all: $(NAME) clean  ############

%.o: %.c include/cub3d.h
	@$(CC) $(CFLAGS) -c $< -o $@  && \
	echo "compilation file name $< done ✅" || \
	(echo "compilation of $< failed ❌" && exit 1)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@ ./MLX42/build/libmlx42.a -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" && \
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