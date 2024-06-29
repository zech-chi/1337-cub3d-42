/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:50:15 by zech-chi          #+#    #+#             */
/*   Updated: 2024/06/29 22:19:33 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void ft_draw_square(t_cub *cub, int r, int c, uint32_t color)
{
	for (int y = r; y < r + PIXEL; y++)
	{
		for (int x = c; x < c + PIXEL; x++)
		{
			mlx_put_pixel(cub->maze_img2, x, y, color);
		}
	}
}

void	ft_draw_line(int x1, int y1, int x2, int y2, t_cub *cub, u_int32_t color)
{
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int sx;
	int sy;
	int err;
	int e2;

	sx = (x1 < x2) ? 1 : -1;
	sy = (y1 < y2) ? 1 : -1;
	err = dx - dy;

	while (true)
	{
		if (!(x1 < 0 || y1 < 0 || x1 > cub->cols * PIXEL || y1 > cub->rows * PIXEL))
			mlx_put_pixel(cub->maze_img2, x1, y1, color);

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

	radius = 2;
	y = cub->player.py - radius;
	while (y < cub->player.py + radius)
	{
		x = cub->player.px - radius;
		while (x < cub->player.px + radius)
		{
			if (pow(x - cub->player.px, 2) + pow(y - cub->player.py, 2) < pow(radius, 2))
				mlx_put_pixel(cub->maze_img2, x, y, ft_color(255, 0, 0, 255));
			x++;
		}
		y++;
	}
	x2 = cub->player.px + 10 * cos(cub->player.angle);
	y2 = cub->player.py - 10 * sin(cub->player.angle);
	printf("%f\n", cub->player.angle);
	ft_draw_line(cub->player.px, cub->player.py, x2, y2, cub, ft_color(0, 0, 255, 255));
}

void	ft_draw_rays(t_cub *cub)
{
	int	x2, y2;

	for (int i = 0; i < WINDOW_WIDTH; i++) { // WINDOW_WIDTH

		x2 = cub->player.px + cub->rays[i].distance * cos(cub->rays[i].angle);
		y2 = cub->player.py - cub->rays[i].distance * sin(cub->rays[i].angle);
		ft_draw_line(cub->player.px, cub->player.py, x2, y2, cub, ft_color(0, 255, 0, 255));
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

void	ft_render_minimap(t_cub *cub)
{
	for (int r = 0; r < cub->rows; r++)
	{
		for (int c = 0; c < cub->cols; c++)
		{
			if (cub->map[r][c] == ' ')
				ft_draw_square(cub, r * PIXEL, c * PIXEL, ft_color(0, 0, 0, 255));
			else if (cub->map[r][c] == '1')
				ft_draw_square(cub, r * PIXEL, c * PIXEL, ft_color(254,163,3,255));
			else if (cub->map[r][c] == '0')
				ft_draw_square(cub, r * PIXEL, c * PIXEL, ft_color(52, 25, 72,255));
		}
	}
	ft_draw_rays(cub);
	ft_draw_player(cub);
}