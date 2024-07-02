/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:25:52 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/02 17:33:23 by zech-chi         ###   ########.fr       */
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
	mlx_t		*mlx_ptr;
	mlx_image_t	*maze_img;
	mlx_image_t	*no_img;
	mlx_image_t	*so_img;
	mlx_image_t	*we_img;
	mlx_image_t	*ea_img;
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
}	t_ray;

typedef	struct	s_thread
{
	pthread_t		id_background_music;
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
	int			horizon;
	t_list		*head;
	t_mlx		mlx;
	mlx_t		*mlx_ptr2; // to remove
	mlx_image_t	*maze_img2; // to remove
	t_offset	offset;
	t_player	player;
	t_ray		rays[WINDOW_WIDTH];
	t_thread	thread;
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



void	ft_render_minimap(t_cub *cub); /////

#endif