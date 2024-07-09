/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:25:52 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/09 14:53:45 by zech-chi         ###   ########.fr       */
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
	mlx_image_t		*weapon[WEAPONS];
	mlx_image_t		*minimap;
	mlx_image_t		*player_rays_minimap;
	mlx_image_t		*minimap_big;  // to remove
	mlx_image_t		*black;
	mlx_image_t		*background_start;
	mlx_image_t		*door;
	mlx_image_t		*weapon_magazin;
	mlx_image_t		*circle;
	mlx_image_t		*target;
	mlx_image_t		*sky;
	mlx_image_t		*copy;
	mlx_image_t		*copy_circle;
	bool			init_state;
	bool			normal_shoot1;
	bool			normal_shoot2;
	bool			zome_shoot1;
	bool			zome_shoot2;
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
	float bobbing_amplitude;
	float bobbing_frequency;
	float bobbing_time;
	float bobbing_speed;
	bool is_walking;
	float head_bobbing_offset;
}	t_player;

typedef struct s_ray
{
	float	angle;
	float	distance;
	bool	was_vertical;
	bool	down;
	bool	up;
	bool	left;
	bool	right;
	float	xintercept;
	float	yintercept;
	float	horz_distance;
	float	vert_distance;
	float	hitx;
	float	hity;
	float	hithorzx;
	float	hithorzy;
	float	hitvertx;
	float	hitverty;
	bool	found_door_horz;
	bool	found_door_vert;
	bool	found_door;
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
void	ft_display_list(t_list *head);// to remove 
/*to remove*/
void	ft_display(t_cub *cub);

/*draw*/
uint32_t	ft_color(uint32_t r, uint32_t g, uint32_t b, uint32_t a);
void	ft_build_maze(t_cub *cub);
void	ft_draw_img(t_cub *cub, int x, int y, float distance, mlx_image_t *img);
/*end draw*/

/*player*/
void	ft_player_init(t_cub *cub);
void	ft_render_player(t_cub *cub);
void	ft_player_event(t_cub *cub);
void	ft_update_head_bobbing(t_cub *cub);
/*end player*/

/*math*/
int		ft_between(float alpha, float angle_start, float angle_end);
float	ft_periodic(float angle);
float	ft_min(float a, float b);
float	ft_get_distance(float x1, float y1, float x2, float y2);
int	max(int a, int b);
/*end math*/

/*raycasting*/
// void	ft_raycasting(t_cub *cub);
void	ft_rays(t_cub *cub);
/*end raycasting*/

/// mouse
void	mouse_func(double xpos, double ypos, void *param);
void	ft_enable_mouse(t_cub *cub);
void	ft_disable_mouse(t_cub *cub);
void	mouse_hook(mouse_key_t button, action_t action, modifier_key_t mods, void *param);
// mouse

// walk
void	ft_walk_up(t_cub *cub);
void	ft_walk_down(t_cub *cub);
void	ft_walk_left(t_cub *cub);
void	ft_walk_right(t_cub *cub);
// walk

// turn
void	ft_turn_left(t_cub *cub);
void	ft_turn_right(t_cub *cub);
// turn

// look
void	ft_look_up(t_cub *cub);
void	ft_look_down(t_cub *cub);
// look

// light
void	ft_light_event(t_cub *cub);
// light

// weapon
void	ft_reset_weapon_event(t_cub *cub);
void	ft_set_weapon_normal(t_cub *cub);
void	ft_weapon_event(t_cub *cub);
mlx_image_t	*ft_play_init_state(t_cub *cub);
mlx_image_t	*ft_play_weapon_status(t_cub *cub, int size, char *path);
// weapon

void	ft_render_minimap(t_cub *cub); ////

// big minimap
void 	ft_draw_square(t_cub *cub, int r, int c, uint32_t color);
void	ft_draw_line(int x2, int y2, t_cub *cub, bool is_player);
void	ft_draw_player(t_cub *cub);
void	ft_draw_rays(t_cub *cub);
float	ft_scale_f(float prev);

// play music
void	ft_mtx_init(t_cub *cub);
void	*ft_routine(void *args);
void	*ft_routine2(void *args);
void	ft_mtx_set_stop(t_cub *cub);
bool	ft_mtx_get_stop(t_cub *cub);
void	ft_play_action_sound(t_cub *cub);
// play music
#endif