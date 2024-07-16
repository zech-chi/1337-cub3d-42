/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:25:52 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/15 19:52:43 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "consts.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include "../../MLX42/include/MLX42/MLX42.h"

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
	mlx_image_t		*no_img;
	mlx_image_t		*so_img;
	mlx_image_t		*we_img;
	mlx_image_t		*ea_img;
}	t_mlx;

typedef struct s_color
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
}	t_horz_data;

typedef struct s_vert_data
{
	float	deltax;
	float	deltay;
	float	xintercept;
	float	yintercept;
	float	nextx;
	float	nexty;
	float	hitx;
	float	hity;
	float	hitvertx;
	float	hitverty;
	float	vert_distance;
	bool	found_vert_hit;
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
	t_horz_data	horz;
	t_vert_data	vert;
}	t_ray;

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
	t_list		*head;
	t_mlx		mlx;
	t_offset	offset;
	t_player	player;
	t_ray		rays[WINDOW_WIDTH];
}	t_cub;

/* get_next_line/get_next_line_utils.c */
size_t		ft_strlen(char *str);
char		*ft_strdup(char *str);
char		*ft_strjoin(char *s1, char *s2);
void		shift_buff_or_clean_it(char *buff, size_t j);
int			has_the_end(char *buff, char **line);

/* get_next_line/get_next_line.c */
char		*get_next_line(int fd);

/* tools */
char		**ft_split(char const *s, char c);
void		ft_putstr_fd(char *str, int fd, int endl, char *color);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_valid_name(char *name);
int			ft_open_file(char *path);
char		*ft_substr(char *s, unsigned int start, size_t len);
void		ft_skip_space(char *str, int *i);
char		*ft_itoa(int n);

/* malloc */
void		*allocate_memory_safely(size_t bytes, t_cub *cub);
void		ft_free_data(t_cub *cub);
void		ft_free_list(t_list **head);

/* parsing/parsing.c */
void		ft_parsing(int ac, char **av, t_cub *cub);
int			*ft_get_color(char *line, t_cub *cub);
int			ft_set_color(t_cub *cub, int **color, char *line, int *i);
void		ft_scan_file(t_cub *cub, char *path);
void		ft_create_map(t_cub *cub);
void		ft_scan_map(t_cub *cub);

/* parsing/scan_file.c*/
int			ft_part1_full(t_cub *cub);

/* parsing/scan_line_1&2.c*/
void		ft_scan_line(t_cub *cub, int *check);
int			ft_is_full_spaces(char *line);
int			ft_is_full_spaces_newline(char *line);
int			ft_check_content_line(char *line, int *check);
int			ft_set_coordonates_textures(char **texture, char *line, int *i);

/*linked_list*/
t_list		*ft_lstnew(void *content);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);

/*draw*/
uint32_t	ft_color(uint32_t r, uint32_t g, uint32_t b, uint32_t a);
void		ft_build_maze(t_cub *cub);
void		ft_draw_img(t_cub *cub, int x, int y, mlx_image_t *img);
void		ft_render_walls(t_cub *cub);
/*end draw*/
// mlx_tools
void		ft_mlx_init(t_cub *cub);
void		ft_load_img(t_cub *cub);
void		ft_mlx_image_to_window(t_cub *cub, mlx_image_t *img, int x, int y);
mlx_image_t	*ft_get_image(t_cub *cub, char *path);
mlx_image_t	*ft_mlx_new_image(t_cub *cub, uint32_t width, uint32_t height);

/*math*/
int			ft_between(float alpha, float angle_start, float angle_end);
float		ft_periodic(float angle);
float		ft_min(float a, float b);
int			ft_min_d(int a, int b);
float		ft_get_distance(float x1, float y1, float x2, float y2);
int			ft_max_d(int a, int b);
/*end math*/

/*raycasting*/
float		ft_vertical(t_cub *cub, int i);
float		ft_horizontal(t_cub *cub, int i);
void		ft_rays(t_cub *cub);
/*end raycasting*/

/*player*/
void		ft_player_init(t_cub *cub);
void		ft_player_event(t_cub *cub);
// walk
void		ft_walk_up(t_cub *cub);
void		ft_walk_down(t_cub *cub);
void		ft_walk_left(t_cub *cub);
void		ft_walk_right(t_cub *cub);
// walk_check
bool		ft_iswall2(t_cub *cub, int x, int y, double alpha);
bool		ft_can_walk_up(t_cub *cub);
bool		ft_can_walk_down(t_cub *cub, double a, double b);
bool		ft_can_walk_down2(t_cub *cub);
// turn
void		ft_turn_left(t_cub *cub);
void		ft_turn_right(t_cub *cub);
/*end player*/

#endif
