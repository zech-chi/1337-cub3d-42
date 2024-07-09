/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:50:15 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/08 19:47:18 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


void	ft_copy_img(mlx_image_t	*from, mlx_image_t *to)
{
	int	x;
	int	y;
	int	i;
	int	r,g, b, a;

	y = -1;
	while (++y < (int)from->height)
	{
		x = -1;
		while (++x < (int)from->width)
		{
			i = (y * from->width + x) * 4;
			r = from->pixels[i];
			g = from->pixels[i + 1];
			b = from->pixels[i + 2];
			a = from->pixels[i + 3];
			mlx_put_pixel(to, x, y, ft_color(r, g, b, a));
		}
	}
}

void	ft_rotate_img(mlx_image_t *from, mlx_image_t *to, float angle)
{
	int	x;
	int	y;
	int	sx, sy;
	int i;
	int r, g, b, a;
	float cos_angle = cos(angle);
	float sin_angle = sin(angle);

	y = -1;
	while (++y < (int)to->height) {
		x = -1;
		while (++x < (int)to->width) {
			sx = (int)(cos_angle * (x - (int)to->width / 2) + sin_angle * (y - (int)to->height / 2) + (int)to->width / 2);
			sy = (int)(-sin_angle * (x - (int)to->width / 2) + cos_angle * (y - (int)to->height / 2) + (int)to->height / 2);
			if (sx >= 0 && sy >= 0 && sx < (int)to->width && sy < (int)to->height) {
				i = (sy * (int)to->width + sx) * 4;
				r = from->pixels[i];
				g = from->pixels[i + 1];
				b = from->pixels[i + 2];
				a = from->pixels[i + 3];
				mlx_put_pixel(to, x, y, ft_color(r, g, b, a));
			} else {
				mlx_put_pixel(to, x, y, ft_color(0, 0, 0, 0));
			}
		}
	}
}


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
	int	x1;
	int	y1;
	int	px;
	int	py;

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
				mlx_put_pixel(cub->mlx.player_rays_minimap, x1, y1, ft_color(255, 0, 0, 255));
			else
			{
				if (x1 < 0 || y1 < 0 || x1 >= MINIMAP_WIDTH || y1 >= MINIMAP_HEIGHT \
					|| pow(x1 - px, 2) + pow(y1 - py, 2) >= pow(MINIMAP_RADIUS, 2))
					break;
				mlx_put_pixel(cub->mlx.player_rays_minimap, x1, y1, ft_color(255, 255, 0, max(0, 255 * exp(-0.025 * ft_get_distance(px, py, x1, y1)))));
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
	// ft_draw_line2(x2, y2, cub, true);
	y = py - RADIUS;
	while (y < py + RADIUS)
	{
		x = px - RADIUS;
		while (x < px + RADIUS)
		{
			if (pow(x - px, 2) + pow(y - py, 2) < pow(RADIUS, 2))
				mlx_put_pixel(cub->mlx.player_rays_minimap, x, y, ft_color(255, 0, 0, 255));
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
		x2 = MINIMAP_WIDTH / 2 + (ray_distance - 1) * cos(cub->rays[i].angle);
		y2 = MINIMAP_HEIGHT / 2 - (ray_distance - 1) * sin(cub->rays[i].angle);
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
	int	px;
	int	py;
	int	static i;
	// int	pr;
	// int	pc;

	px = MINIMAP_WIDTH / 2;
	py = MINIMAP_HEIGHT / 2;
	oldy = ft_scale_f(cub->player.py) - MINIMAP_HEIGHT / 2;
	newy = -1;
	while (++newy < MINIMAP_HEIGHT)
	{
		newx = -1;
		oldx = ft_scale_f(cub->player.px) - MINIMAP_WIDTH / 2;
		while (++newx < MINIMAP_WIDTH)
		{
			if (oldx >= 0 && oldy >= 0 && oldx < cub->cols * PIXEL_MINI && oldy < cub->rows * PIXEL_MINI && \
				pow(newx - px, 2) + pow(newy - py, 2) < pow(MINIMAP_RADIUS, 2))
			{
				r = oldy / PIXEL_MINI;
				c = oldx / PIXEL_MINI;
				if (cub->map[r][c] == ' ')
					mlx_put_pixel(cub->mlx.minimap, newx, newy, ft_color(150, 0, 0, 255));
				else if (cub->map[r][c] == '1')
					mlx_put_pixel(cub->mlx.minimap, newx, newy, ft_color(255, 255, 255, 255));
				else if (cub->map[r][c] == '0')
					mlx_put_pixel(cub->mlx.minimap, newx, newy, ft_color(0, 0, 0,255));
				else if (cub->map[r][c] == 'D')
				{
					if (r == cub->player.pr && c == cub->player.pc)
						mlx_put_pixel(cub->mlx.minimap, newx, newy, ft_color(0, 0, 0, 255));
					else
						mlx_put_pixel(cub->mlx.minimap, newx, newy, ft_color(139,69,19, 255));
						// mlx_put_pixel(cub->mlx.minimap, newx, newy, ft_color(30,129,176, 255));
				}
			}
			else if (pow(newx - px, 2) + pow(newy - py, 2) < pow(MINIMAP_RADIUS, 2))
				mlx_put_pixel(cub->mlx.minimap, newx, newy, ft_color(150, 0, 0, 255));
			oldx++;
		}
		oldy++;
	}
	ft_draw_rays_minimap(cub);
	ft_draw_player_minimap(cub);
	// ft_rotate_img(cub->mlx.minimap, cub->mlx.copy, cub->angle_minimap);
	// // ft_copy_img(cub->mlx.minimap, cub->mlx.copy);
	// ft_copy_img(cub->mlx.copy, cub->mlx.minimap);

	// ft_rotate_img(cub->mlx.player_rays_minimap, cub->mlx.copy, cub->angle_minimap);
	// // ft_copy_img(cub->mlx.player_rays_minimap, cub->mlx.copy);
	// ft_copy_img(cub->mlx.copy, cub->mlx.player_rays_minimap);

	// ft_rotate_img(cub->mlx.circle, cub->mlx.copy_circle, cub->angle_minimap);
	// // // ft_copy_img(cub->mlx.circle, cub->mlx.copy_circle);
	// ft_copy_img(cub->mlx.copy_circle, cub->mlx.circle);
	i++;
}

void	ft_reset_player_rays_minimap(t_cub *cub)
{
	int	y;
	int	x;

	y = -1;
	while (++y < MINIMAP_HEIGHT)
	{
		x = -1;
		while (++x < MINIMAP_WIDTH)
			mlx_put_pixel(cub->mlx.player_rays_minimap, x, y, ft_color(0, 0, 0, 0));
	}
}

void	ft_render_minimap(t_cub *cub)
{
	// mlx_texture_t	*texture;
	// for (int r = 0; r < cub->rows; r++)
	// {
	// 	for (int c = 0; c < cub->cols; c++)
	// 	{
	// 		if (cub->map[r][c] == ' ')
	// 			ft_draw_square(cub, r * PIXEL_MINI, c * PIXEL_MINI, ft_color(0, 0, 0, 255));
	// 		else if (cub->map[r][c] == '1')
	// 			ft_draw_square(cub, r * PIXEL_MINI, c * PIXEL_MINI, ft_color(38,70,83,255));
	// 		else if (cub->map[r][c] == '0')
	// 			ft_draw_square(cub, r * PIXEL_MINI, c * PIXEL_MINI, ft_color(40, 19, 55, 255));
	// 	}
	// }
	// ft_draw_rays(cub);
	// ft_draw_player(cub);
	ft_reset_player_rays_minimap(cub);
	ft_draw_map(cub);
	// if (cub->mlx.circle)
	// 	mlx_delete_image(cub->mlx.mlx_ptr, cub->mlx.circle);
	// texture = mlx_load_png("circle.png");
	// cub->mlx.circle = mlx_texture_to_image(cub->mlx.mlx_ptr, texture);
	// mlx_image_to_window(cub->mlx.mlx_ptr, cub->mlx.circle, POS_MINIMAP, POS_MINIMAP - 29);
	
}
