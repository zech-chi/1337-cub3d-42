/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:07:51 by zelabbas          #+#    #+#             */
/*   Updated: 2024/06/30 22:42:06 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

uint32_t ft_color(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

// void ft_draw_rectangle(t_cub *cub, int r, int c, uint32_t color)
// {
// 	for (int i = r; i < r + cub->pixel; i++)
// 	{
// 		for (int j = c; j < c + cub->pixel; j++)
// 		{
// 			mlx_put_pixel(cub->mlx.maze_img, j, i, color);
// 		}
// 	}
// }

void	ft_reset_walls(t_cub *cub)
{
	for (int y = 0; y < WINDOW_HEIGHT; y++) {
		for (int x = 0; x < WINDOW_WIDTH; x++) {
			mlx_put_pixel(cub->mlx.maze_img, x, y, ft_color(255, 255, 255, 0));
		}
	}
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}


void	ft_draw_walls(t_cub *cub, double distance, int x, double angle, int i)
{
	int	wall_height;
	int	y;
	int	xoffset;
	int yoffset;

	wall_height = (cub->pixel / (distance * cos(cub->player.angle - angle))) * ((WINDOW_WIDTH / 2) / tan(M_PI / 6));
	y = (WINDOW_HEIGHT / 2) - (wall_height / 2);
	y = max(y, 0);
	for (int y1 = 0; y1 < y; y1++)
		mlx_put_pixel(cub->mlx.maze_img, x, y1, ft_color(52, 25, 72,255));
	while (y < min(WINDOW_HEIGHT / 2 - wall_height / 2 + wall_height, WINDOW_HEIGHT))
	{
		if (!cub->rays[i].was_vertical)
		{
			xoffset = (int)cub->rays[i].hitx % PIXEL;
			if (cub->rays[i].up)
				mlx_put_pixel(cub->mlx.maze_img, x, y, ft_color(255, 255, 255, 255* exp(-0.002 * cub->rays[i].distance) ));
			else
				mlx_put_pixel(cub->mlx.maze_img, x, y, ft_color(255, 0, 0, 255* exp(-0.002 * cub->rays[i].distance) ));
		}
		else
		{
			yoffset = (int)cub->rays[i].hity % PIXEL;
			if (cub->rays[i].right)
				mlx_put_pixel(cub->mlx.maze_img, x, y, ft_color(0, 0, 0, 255* exp(-0.002 * cub->rays[i].distance) ));
			else
				mlx_put_pixel(cub->mlx.maze_img, x, y, ft_color(0, 255, 0, 255* exp(-0.002 * cub->rays[i].distance) ));
		}
		y++;
	}
	for (int y2 = y; y2 < WINDOW_HEIGHT; y2++)
		mlx_put_pixel(cub->mlx.maze_img, x, y2, ft_color(254,163,3,255));
}

// void	ft_render_map(t_cub *cub)
// {
// 	for (int r = 0; r < cub->rows; r++)
// 	{
// 		for (int c = 0; c < cub->cols; c++)
// 		{
// 			if (cub->map[r][c] == ' ')
// 				ft_draw_rectangle(cub, cub->pixel * r , cub->pixel * c, ft_color(0, 0, 0,255));
// 			else if (cub->map[r][c] == '1')
// 				ft_draw_rectangle(cub, cub->pixel * r , cub->pixel * c , ft_color(255, 255, 255,255));
// 			else if (cub->map[r][c] == '0')
// 				ft_draw_rectangle(cub, cub->pixel * r , cub->pixel * c , ft_color(0,0,0,255));
// 		}
// 	}
// }

// void	ft_resetplayer(t_cub *cub, int save_py, int save_px)
// {
// 	for (int i = save_py - 1; i < save_py + 1; i++)
// 	{
// 		for (int j = save_px - 1; j < save_px + 1; j++)
// 		{
// 			mlx_put_pixel(cub->mlx.maze_img, j, i, ft_color(0, 0, 0, 255));
// 		}
// 	}
// }


void	ft_close_win_event(t_cub *cub)
{
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_ESCAPE))
		mlx_close_window(cub->mlx.mlx_ptr);
	// free and out
}

void	ft_fix_rays(t_cub *cub)
{
	for (int i = 1; i < NUMBER_RAYS - 1; i++) {
		if (cub->rays[i - 1].was_vertical == cub->rays[i + 1].was_vertical)
			cub->rays[i].was_vertical = cub->rays[i - 1].was_vertical;
	}
}

void	ft_render_walls(t_cub *cub)
{
	int	i;

	ft_fix_rays(cub);
	i = -1;
	// printf("----------------\n");
	// printf("[ ");
	while (++i < NUMBER_RAYS)
	{
		// if (i == 0)
			ft_draw_walls(cub, cub->rays[i].distance, i, cub->rays[i].angle, i);
		// printf("%f, ", cub->rays[i].distance);
		// if (i % 50 == 0)
		// 	printf("\n");
	}
	// printf("]\n\n");
}

void	ft_render(void *param)
{
	t_cub		*cub;

	cub = param;
	ft_close_win_event(cub);
	ft_player_event(cub);
	if (!cub->render)
		return ;
	
	// ft_reset_walls(cub);
	ft_rays(cub);
	ft_render_walls(cub);
	// ft_render_minimap(cub);
	cub->render = false;
}

void	ft_build_maze(t_cub *cub)
{

	cub->mlx.mlx_ptr = mlx_init(WINDOW_WIDTH + 930, WINDOW_HEIGHT , "ziko^2", false);
	if (!(cub->mlx.mlx_ptr))
	{
		perror(mlx_strerror(mlx_errno));
		return ;
	}
	cub->mlx.maze_img = mlx_new_image(cub->mlx.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	cub->maze_img2 = mlx_new_image(cub->mlx.mlx_ptr, cub->cols * PIXEL, cub->rows * PIXEL); ///
	if (!cub->mlx.maze_img)
	{
		perror(mlx_strerror(mlx_errno));
		return;
	}
	mlx_image_to_window(cub->mlx.mlx_ptr, cub->maze_img2, 0, 0);
	mlx_image_to_window(cub->mlx.mlx_ptr, cub->mlx.maze_img, 930, 0);
	mlx_loop_hook(cub->mlx.mlx_ptr, ft_render, cub);
	mlx_loop(cub->mlx.mlx_ptr);
}