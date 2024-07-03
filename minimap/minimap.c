/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:50:15 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/03 18:25:25 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


float	ft_scale_f(float prev)
{
	float	new;

	new = (prev * PIXEL_MINI) / PIXEL;
	return (new);
}


void	ft_draw_line2(int x2, int y2, t_cub *cub, bool is_player)
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
	int	px;
	int	py;

	// if (x2 > MINIMAP_WIDTH )
	// 	x2 = MINIMAP_WIDTH  - 2;
	// if (y2 > MINIMAP_HEIGHT )
	// 	y2 = MINIMAP_HEIGHT - 2;
	px = MINIMAP_WIDTH / 2;
	py = MINIMAP_HEIGHT / 2;
	x1 = px;
	y1 = py;
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
				mlx_put_pixel(cub->mlx.minimap, x1, y1, ft_color(0, 0, 0, 255));
			else
			{
				if (x1 < 0 || y1 < 0 || x1 >= MINIMAP_WIDTH || y1 >= MINIMAP_HEIGHT)
					break;
				a = max(255 * exp(-0.01 * ft_get_distance(x1, y1, px, py)), 0);
				mlx_put_pixel(cub->mlx.minimap, x1, y1, ft_color(255, 255, 0, a));
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




void	ft_draw_player_minimap(t_cub *cub)
{
	int	x;
	int	y;
	int	px;
	int	py;
	int	x2;
	int	y2;


	px = MINIMAP_WIDTH / 2;
	py = MINIMAP_HEIGHT / 2;
	x2 = px + SENS_LENGTH * cos(cub->player.angle);
	y2 = py - SENS_LENGTH * sin(cub->player.angle);
	ft_draw_line2(x2, y2, cub, true);
	y = py - RADIUS;
	while (y < py + RADIUS)
	{
		x = px - RADIUS;
		while (x < px + RADIUS)
		{
			if (pow(x - px, 2) + pow(y - py, 2) < pow(RADIUS, 2))
				mlx_put_pixel(cub->mlx.minimap, x, y, ft_color(255, 0, 0, 255));
			x++;
		}
		y++;
	}
}

void	ft_draw_rays_minimap(t_cub *cub)
{
	int	x2, y2;
	float	ray_distance;

	for (int i = 0; i < WINDOW_WIDTH; i++)
	{
		ray_distance = ft_scale_f(cub->rays[i].distance);
		x2 = MINIMAP_WIDTH / 2 + (ray_distance) * cos(cub->rays[i].angle);
		y2 = MINIMAP_HEIGHT / 2 - (ray_distance) * sin(cub->rays[i].angle);
		ft_draw_line2(x2, y2, cub, false);
	}
}

void	ft_draw_map(t_cub *cub)
{
	int	newx;
	int	newy;
	int	oldx;
	int	oldy;
	int	r;
	int	c;


	oldy = ft_scale_f(cub->player.py) - MINIMAP_HEIGHT / 2;
	newy = -1;
	while (++newy < MINIMAP_HEIGHT)
	{
		newx = -1;
		oldx = ft_scale_f(cub->player.px) - MINIMAP_WIDTH / 2;
		while (++newx < MINIMAP_WIDTH)
		{
			if (oldx >= 0 && oldy >= 0 && oldx < cub->cols * PIXEL_MINI && oldy < cub->rows * PIXEL_MINI)
			{
				r = oldy / PIXEL_MINI;
				c = oldx / PIXEL_MINI;
				if (cub->map[r][c] == ' ')
					mlx_put_pixel(cub->mlx.minimap, newx, newy, ft_color(0, 0, 0, 255));
				else if (cub->map[r][c] == '1')
					mlx_put_pixel(cub->mlx.minimap, newx, newy, ft_color(38,70,83,255));
				else if (cub->map[r][c] == '0')
					mlx_put_pixel(cub->mlx.minimap, newx, newy, ft_color(40, 19, 55, 255));
			}
			else
				mlx_put_pixel(cub->mlx.minimap, newx, newy, ft_color(0, 0, 0, 255));
			oldx++;
		}
		oldy++;
	}
	ft_draw_rays_minimap(cub);
	ft_draw_player_minimap(cub);
}

void	ft_render_minimap(t_cub *cub)
{
	for (int r = 0; r < cub->rows; r++)
	{
		for (int c = 0; c < cub->cols; c++)
		{
			if (cub->map[r][c] == ' ')
				ft_draw_square(cub, r * PIXEL_MINI, c * PIXEL_MINI, ft_color(0, 0, 0, 255));
			else if (cub->map[r][c] == '1')
				ft_draw_square(cub, r * PIXEL_MINI, c * PIXEL_MINI, ft_color(38,70,83,255));
			else if (cub->map[r][c] == '0')
				ft_draw_square(cub, r * PIXEL_MINI, c * PIXEL_MINI, ft_color(40, 19, 55, 255));
		}
	}
	ft_draw_rays(cub);
	ft_draw_player(cub);
	ft_draw_map(cub);
}