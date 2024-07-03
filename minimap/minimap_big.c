/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:50:23 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/03 17:51:40 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void ft_draw_square(t_cub *cub, int r, int c, uint32_t color)
{
	for (int y = r; y < r + PIXEL_MINI; y++)
	{
		for (int x = c; x < c + PIXEL_MINI; x++)
		{
			mlx_put_pixel(cub->mlx.minimap_big, x, y, color);
		}
	}
}

void	ft_draw_line(int x2, int y2, t_cub *cub, bool is_player)
{
	int dx;
	int dy;
	int sx;
	int sy;
	int err;
	int e2;
	int	a;
	int	x1;
	int	y1;

	x1 = ft_scale_f(cub->player.px);
	y1 = ft_scale_f(cub->player.py);
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	sx = (x1 < x2) ? 1 : -1;
	sy = (y1 < y2) ? 1 : -1;
	err = dx - dy;
	while (true)
	{
		if (x1 >= 0 && y1 >= 0 && x1 < cub->cols * PIXEL_MINI && y1 < cub->rows * PIXEL_MINI)
		{
			if (is_player)
				mlx_put_pixel(cub->mlx.minimap_big, x1, y1, ft_color(0, 0, 255, 255));
			else
			{
				a = max(255 * exp(-0.008 * ft_get_distance(x1, y1, ft_scale_f(cub->player.px), ft_scale_f(cub->player.py))), 0);
				mlx_put_pixel(cub->mlx.minimap_big, x1, y1, ft_color(255, 255, 0, a));
			}
		}

		if (x1 == x2 && y1 == y2)
			break;

		e2 = 2 * err;
		
		if (e2 > -dy) 
		{
			err -= dy;
			x1 += sx;
		}
		
		if (e2 < dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}

void	ft_draw_player(t_cub *cub)
{
	int	x;
	int	y;
	int	radius;
	int x2, y2;

	x2 = ft_scale_f(cub->player.px) + 10 * cos(cub->player.angle);
	y2 = ft_scale_f(cub->player.py) - 10 * sin(cub->player.angle);
	// printf("%f\n", cub->player.angle);
	ft_draw_line(x2, y2, cub, true); //  ft_color(0, 0, 255, 255)
	radius = 2;
	y = ft_scale_f(cub->player.py) - radius;
	while (y < ft_scale_f(cub->player.py) + radius)
	{
		x = ft_scale_f(cub->player.px) - radius;
		while (x < ft_scale_f(cub->player.px) + radius)
		{
			if (pow(x - ft_scale_f(cub->player.px), 2) + pow(y - ft_scale_f(cub->player.py), 2) < pow(radius, 2))
				mlx_put_pixel(cub->mlx.minimap_big, x, y, ft_color(255, 0, 0, 255));
			x++;
		}
		y++;
	}
}

void	ft_draw_rays(t_cub *cub)
{
	int	x2, y2;
	float	ray_distance;

	for (int i = 0; i < WINDOW_WIDTH; i++) { // WINDOW_WIDTH
		ray_distance = ft_scale_f(cub->rays[i].distance);
		x2 = ft_scale_f(cub->player.px) + (ray_distance - 1) * cos(cub->rays[i].angle);
		y2 = ft_scale_f(cub->player.py) - (ray_distance - 1) * sin(cub->rays[i].angle);
		ft_draw_line(x2, y2, cub, false);
		// printf("horz_distance = %f\n", cub->rays[i].horz_distance);
		// printf("vert_distance = %f\n", cub->rays[i].vert_distance);
		// printf("taken_distance = %f\n", cub->rays[i].distance);
		// printf("facing_up : %d\n", cub->rays[i].up);
		// printf("facing_down : %d\n", cub->rays[i].down);
		// printf("facing_left : %d\n", cub->rays[i].left);
		// printf("facing_right : %d\n", cub->rays[i].right);
		// printf("angle = %f\n\n", cub->rays[i].angle);
	}
}

