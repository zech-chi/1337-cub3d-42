NAME = cub3D

NAMEBON = cub3Dbonus

CC = cc

CFLAGS = -Wall -Wextra -Werror -Ofast #-fsanitize=thread #-g

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

SRCSBON =  bonus/main_bonus.c \
		bonus/music/play_music_bonus.c \
		bonus/music/action_sound_bonus.c \
		bonus/get_next_line/get_next_line_utils_bonus.c \
		bonus/get_next_line/get_next_line_bonus.c \
		bonus/malloc/free_data_bonus.c \
		bonus/malloc/malloc_safely_bonus.c \
		bonus/tools/isvalid_bonus.c \
		bonus/tools/openfile_bonus.c \
		bonus/tools/putstr_fd_bonus.c \
		bonus/tools/skip_space_bonus.c \
		bonus/tools/split_bonus.c \
		bonus/tools/strcmp_bonus.c \
		bonus/tools/strncmp_bonus.c \
		bonus/tools/substr_bonus.c \
		bonus/tools/itoa_bonus.c \
		bonus/parsing/create_map_bonus.c \
		bonus/parsing/get_color_bonus.c \
		bonus/parsing/parsing_bonus.c \
		bonus/parsing/scan_file_bonus.c \
		bonus/parsing/scan_line_1_bonus.c \
		bonus/parsing/scan_line_2_bonus.c \
		bonus/parsing/scan_map_bonus.c \
		bonus/parsing/scan_map_tools_bonus.c \
		bonus/linked_list/linked_list_bonus.c \
		bonus/draw/walls_bonus.c \
		bonus/draw/walls_tools_bonus.c \
		bonus/draw/draw_imgs_bonus.c \
		bonus/draw/mlx_tools_bonus.c \
		bonus/player/player_bonus.c \
		bonus/player/mouse_bonus.c \
		bonus/player/walk_bonus.c \
		bonus/player/walk_check_bonus.c \
		bonus/player/turn_bonus.c \
		bonus/player/look_bonus.c \
		bonus/player/light_bonus.c \
		bonus/player/headbob_bonus.c \
		bonus/player/jump_bonus.c \
		bonus/player/weapon1_bonus.c \
		bonus/player/weapon2_bonus.c \
		bonus/math/math_tools_bonus.c \
		bonus/math/math_tools2_bonus.c \
		bonus/raycasting/rays_bonus.c \
		bonus/raycasting/horizontal_bonus.c \
		bonus/raycasting/vertical_bonus.c \
		bonus/minimap/minimap_bonus.c \
		bonus/minimap/draw_line_bonus.c \
		bonus/minimap/draw_map_tools_bonus.c


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