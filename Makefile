NAME = cub3D

NAMEBON = cub3Dbonus

CC = cc

CFLAGS = -Wall -Wextra -Werror -Ofast -fsanitize=address -g

SRCSMAN =  mandatory/main.c \
		mandatory/get_next_line/get_next_line_utils.c \
		mandatory/get_next_line/get_next_line.c \
		mandatory/malloc/free_data.c \
		mandatory/malloc/malloc_safely.c \
		mandatory/tools/isvalid.c \
		mandatory/tools/openfile.c \
		mandatory/tools/putstr_fd.c \
		mandatory/tools/skip_space.c \
		mandatory/tools/split.c \
		mandatory/tools/strcmp.c \
		mandatory/tools/strncmp.c \
		mandatory/tools/substr.c \
		mandatory/tools/itoa.c \
		mandatory/parsing/create_map.c \
		mandatory/parsing/get_color.c \
		mandatory/parsing/parsing.c \
		mandatory/parsing/scan_file.c \
		mandatory/parsing/scan_line_1.c \
		mandatory/parsing/scan_line_2.c \
		mandatory/parsing/scan_map.c \
		mandatory/parsing/scan_map_tools.c \
		mandatory/linked_list/linked_list.c \
		mandatory/draw/walls.c \
		mandatory/draw/walls_tools.c \
		mandatory/draw/draw_imgs.c \
		mandatory/draw/mlx_tools.c \
		mandatory/player/player.c \
		mandatory/player/walk.c \
		mandatory/player/walk_check.c \
		mandatory/player/turn.c \
		mandatory/math/math_tools.c \
		mandatory/math/math_tools2.c \
		mandatory/raycasting/rays.c \
		mandatory/raycasting/horizontal.c \
		mandatory/raycasting/vertical.c \

SRCSBON =  bonus/main.c \
		bonus/music/play_music.c \
		bonus/music/action_sound.c \
		bonus/get_next_line/get_next_line_utils.c \
		bonus/get_next_line/get_next_line.c \
		bonus/malloc/free_data.c \
		bonus/malloc/malloc_safely.c \
		bonus/tools/isvalid.c \
		bonus/tools/openfile.c \
		bonus/tools/putstr_fd.c \
		bonus/tools/skip_space.c \
		bonus/tools/split.c \
		bonus/tools/strcmp.c \
		bonus/tools/strncmp.c \
		bonus/tools/substr.c \
		bonus/tools/itoa.c \
		bonus/parsing/create_map.c \
		bonus/parsing/get_color.c \
		bonus/parsing/parsing.c \
		bonus/parsing/scan_file.c \
		bonus/parsing/scan_line_1.c \
		bonus/parsing/scan_line_2.c \
		bonus/parsing/scan_map.c \
		bonus/parsing/scan_map_tools.c \
		bonus/linked_list/linked_list.c \
		bonus/draw/walls.c \
		bonus/draw/walls_tools.c \
		bonus/draw/draw_imgs.c \
		bonus/draw/mlx_tools.c \
		bonus/player/player.c \
		bonus/player/mouse.c \
		bonus/player/walk.c \
		bonus/player/walk_check.c \
		bonus/player/turn.c \
		bonus/player/look.c \
		bonus/player/light.c \
		bonus/player/headbob.c \
		bonus/player/jump.c \
		bonus/player/weapon1.c \
		bonus/player/weapon2.c \
		bonus/math/math_tools.c \
		bonus/math/math_tools2.c \
		bonus/raycasting/rays.c \
		bonus/raycasting/horizontal.c \
		bonus/raycasting/vertical.c \
		bonus/minimap/minimap.c \
		bonus/minimap/draw_line.c \
		bonus/minimap/draw_map_tools.c


OBJSMAN = $(SRCSMAN:.c=.o)
OBJSBON = $(SRCSBON:.c=.o)

all: $(NAME)

%.o: %.c #bonus/include/cub3d.h bonus/include/consts.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJSMAN)
	$(CC) $(CFLAGS) $^ -o $@ ./MLX42/build/libmlx42.a -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

bonus: $(NAMEBON)

$(NAMEBON): $(OBJSBON) 
	$(CC) $(CFLAGS) $^ -o $@ ./MLX42/build/libmlx42.a -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

clean:
	$(RM) $(OBJSMAN) $(OBJSBON)

fclean: clean
	$(RM) $(NAME) $(NAMEBON)

re: fclean all

.PHONY: all clean fclean re