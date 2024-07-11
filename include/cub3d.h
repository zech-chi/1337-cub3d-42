/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:25:52 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/11 04:06:17 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

# include "consts.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h> // threads
#include <signal.h>
# include <fcntl.h>
# include "../MLX42/include/MLX42/MLX42.h"

/* cub3d struct */

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_mlx
{
	mlx_t			*mlx_ptr;
	mlx_image_t		*maze_img;
	mlx_image_t		*canva;
	mlx_image_t		*no_img;
	mlx_image_t		*so_img;
	mlx_image_t		*we_img;
	mlx_image_t		*ea_img;
	mlx_image_t		*minimap;
	mlx_image_t		*player_rays;
	mlx_image_t		*black;
	mlx_image_t		*background_start;
	mlx_image_t		*door;
	mlx_image_t		*weapon_magazin;
	mlx_image_t		*circle;
	mlx_image_t		*target;
	mlx_image_t		*sky;
	mlx_image_t		*shoot_target;
	int				index_weapon;
	bool			init_state;
	bool			normal_shoot1;
	bool			zome_shoot1;
	bool			reload;
	bool			walk;
	int				frame;
	int				cur_index;
	int				weapon_magazin_index;
	mouse_mode_t	status;
}	t_mlx;

typedef struct	s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

typedef struct s_offset
{
	int	x_offset;
	int	y_offset;
}	t_offset;

typedef struct s_player
{
	char	sens;
	int		pr;
	int		pc;
	float	py;
	float	px;
	float	angle;
	float	walk_speed;
	float	turn_speed;
	bool	jump;
	float	offeset_jump;
	float	amplitude_jump;
	float	frequency_jump;
	float	bobbing_amplitude;
	float	bobbing_frequency;
	float	bobbing_time;
	float	bobbing_speed;
	bool	is_walking;
	float	head_bobbing_offset;
}	t_player;

typedef struct s_horz_data
{
	float	deltax;
	float	deltay;
	float	xintercept;
	float	yintercept;
	float	nextx;
	float	nexty;
	float	hitx;
	float	hity;
	float	hithorzx;
	float	hithorzy;
	float	horz_distance;
	bool	found_horz_hit;
	bool	found_door_horz;
	bool	found_shoot_target_horz;
}	t_horz_data;

typedef struct	s_vert_data
{
	float	deltax;
	float	deltay;
	float	xintercept;
	float	yintercept;
	float	nextx;
	float	nexty;
	bool	found_vert_hit;
	float	hitx;
	float	hity;
	float	vert_distance;
	float	hitvertx;
	float	hitverty;
	bool	found_door_vert;
	bool	found_shoot_target_vert;
}	t_vert_data;

typedef struct s_ray
{
	float		angle;
	float		distance;
	bool		was_vertical;
	bool		down;
	bool		up;
	bool		left;
	bool		right;
	float		xintercept;
	float		yintercept;
	float		hitx;
	float		hity;
	bool		found_door;
	bool		found_shoot_target;
	t_horz_data	horz;
	t_vert_data	vert;
}	t_ray;

typedef	struct	s_thread
{
	pthread_t		id_background_music;
	pthread_t		id_sound;
	pthread_mutex_t	mtx_stop;
}	t_thread;

typedef struct s_cub
{
	char		**map;
	char		*line;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			*cf;
	int			*cc;
	int			rows;
	int			cols;
	int			fd;
	int			pixel;
	bool		render;
	bool		stop;
	bool		play_weapon;
	bool		light_on;
	int			horizon;
	t_list		*head;
	t_mlx		mlx;
	t_offset	offset;
	t_player	player;
	t_ray		rays[WINDOW_WIDTH];
	t_thread	thread;
	float		angle_minimap;
}	t_cub;

/* get_next_line/get_next_line_utils.c */
size_t	ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
void	shift_buff_or_clean_it(char *buff, size_t j);
int		has_the_end(char *buff, char **line);

/* get_next_line/get_next_line.c */
char	*get_next_line(int fd);

/* tools */
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *str, int fd, int endl, char *color);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_valid_name(char *name);
int		ft_open_file(char *path);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	ft_skip_space(char *str, int *i);
char	*ft_itoa(int n);

/* malloc */
void	*allocate_memory_safely(size_t bytes, t_cub *cub);
void	ft_free_data(t_cub *cub);
void	ft_free_list(t_list **head);

/* parsing/parsing.c */
void	ft_parsing(int ac, char **av, t_cub *cub);
int		*ft_get_color(char *line, t_cub *cub);
int		ft_set_color(t_cub *cub, int **color, char *line, int *i);
void	ft_scan_file(t_cub *cub, char *path);
void	ft_create_map(t_cub *cub);
void	ft_scan_map(t_cub *cub);
void	ft_check_neighbours_door(t_cub *cub);
int	ft_check_neighbours(t_cub *cub, int r, int c);

/* parsing/scan_file.c*/
int		ft_part1_full(t_cub *cub);

/* parsing/scan_line_1&2.c*/
void	ft_scan_line(t_cub *cub, int *check);
int		ft_is_full_spaces(char *line);
int		ft_is_full_spaces_newline(char *line);
int		ft_check_content_line(char *line, int *check);
int		ft_set_coordonates_textures(char **texture, char *line, int *i);

/*linked_list*/
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);

/*draw*/
uint32_t	ft_color(uint32_t r, uint32_t g, uint32_t b, uint32_t a);
void	ft_build_maze(t_cub *cub);
void	ft_draw_img(t_cub *cub, int x, int y, mlx_image_t *img);
void	ft_render_walls(t_cub *cub);
/*end draw*/
// mlx_tools
void		ft_mlx_init(t_cub *cub);
void		ft_load_img(t_cub *cub);
void		ft_mlx_image_to_window(t_cub *cub, mlx_image_t *img, int x, int y);
mlx_image_t	*ft_get_image(t_cub *cub, char *path);
mlx_image_t	*ft_mlx_new_image(t_cub *cub, uint32_t width, uint32_t height);

/*math*/
int		ft_between(float alpha, float angle_start, float angle_end);
float	ft_periodic(float angle);
float	ft_min(float a, float b);
int		ft_min_d(int a, int b);
float	ft_get_distance(float x1, float y1, float x2, float y2);
int		ft_max_d(int a, int b);
float	ft_scale_f(float prev);
/*end math*/

/*raycasting*/
bool	ft_find_wall(float x, float y, t_cub *cub, int i, bool *found_door, bool *found_shoot_target);
float	ft_vertical(t_cub *cub, int i);
float	ft_horizontal(t_cub *cub, int i);
void	ft_rays(t_cub *cub);
/*end raycasting*/

/// mouse
void	mouse_func(double xpos, double ypos, void *param);
void	mouse_hook(mouse_key_t button, action_t action, modifier_key_t mods, void *param);
// mouse

/*player*/
void	ft_player_init(t_cub *cub);
void	ft_player_event(t_cub *cub);
// walk
void	ft_walk_up(t_cub *cub);
void	ft_walk_down(t_cub *cub);
void	ft_walk_left(t_cub *cub);
void	ft_walk_right(t_cub *cub);
// walk_check
bool	ft_iswall2(t_cub *cub, int x, int y, double alpha);
bool	ft_can_walk_up(t_cub *cub);
bool	ft_can_walk_down(t_cub *cub, double a, double b);
// turn
void	ft_turn_left(t_cub *cub);
void	ft_turn_right(t_cub *cub);
// look
void	ft_look_up(t_cub *cub);
void	ft_look_down(t_cub *cub);
// light
void	ft_light_event(t_cub *cub);
// jump
void	ft_jump(t_cub *cub);
// headbob
void ft_head_bobbing(t_cub *cub);
// weapon
bool	ft_there_is_active_event(t_cub *cub);
void		ft_reset_weapon_event(t_cub *cub);
void		ft_weapon_event(t_cub *cub);
mlx_image_t	*ft_play_init_state(t_cub *cub);
mlx_image_t	*ft_play_weapon_status(t_cub *cub, int size, char *path);
mlx_image_t	*ft_play_weapon(t_cub *cub);
void		ft_play_weapon_frame(t_cub *cub);
mlx_image_t	*ft_get_image2(t_cub *cub, char *path);
void		ft_draw_weapon_magazine(t_cub *cub);
void		ft_check_last_frame(t_cub *cub, int size);
/*end player*/

// minimap
void	ft_render_minimap(t_cub *cub);
void	ft_draw_line(t_vector start, t_vector end, t_cub *cub);
void	ft_draw_pixel(t_cub *cub, t_vector old, t_vector new, t_vector pos_p);
// play music
void	ft_mtx_init(t_cub *cub);
void	*ft_routine(void *args);
void	*ft_routine2(void *args);
void	ft_mtx_set_stop(t_cub *cub);
bool	ft_mtx_get_stop(t_cub *cub);
void	ft_play_action_sound(t_cub *cub);
// play music

#endif
