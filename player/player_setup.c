/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:48:07 by zech-chi          #+#    #+#             */
/*   Updated: 2024/06/07 14:18:13 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_draw_player(t_cub *cub)
{
	int	x;
	int	y;

	ft_draw_rays(cub, cub->player.rot_angle - M_PI / 6 , cub->player.rot_angle + M_PI / 6);
	y = cub->player.r - cub->player.radius;
	while (y < cub->player.r + cub->player.radius)
	{
		x = cub->player.c - cub->player.radius;
		while (x < cub->player.c + cub->player.radius)
		{
			if (pow(x - cub->player.c, 2) + pow(y - cub->player.r, 2) < pow(cub->player.radius, 2))
				mlx_put_pixel(cub->mlx.image, x, y, cub->player.player_color);
			x++;
		}
		y++;
	}
}

// void	ft_bresenham_line(int x1, int y1, int x2, int y2, t_cub *cub)
// {
// 	int	dx;
// 	int	dy;
// 	int	sens_x;
// 	int	sens_y;
// 	int	err;

// 	dx = abs(x2 - x1);
// 	dy = abs(y2 - y1);
// 	sens_x = 1 - 2 * (x1 > x2);
// 	sens_y = 1 - 2 * (y1 > y2);
// 	err = dy - dx;
// 	while (1)
// 	{
// 		printf("target -> (%d, %d)\n", x1, y1);
// 		if (x1 < 0 || y1 < 0)
// 			break;
// 		mlx_put_pixel(cub->mlx.image, x1, y1, cub->player.player_color);
// 		if (x1 == x2 && y1 == y2)
// 			break;
// 		if (2 * err > -dx)
// 		{
// 			err -= dx;
// 			y1 += sens_y;
// 		}
// 		if (2 * err < dy)
// 		{
// 			err += dy;
// 			x1 += sens_x;
// 		}
// 	}
// }
// int	x;
	// int	y;

	// x = cub->player.c + distance * cos(alpha);
	// y = cub->player.r - distance * sin(alpha);
	// printf("player -> (%d, %d)\n", cub->player.c, cub->player.r);
	// printf("target -> (%d, %d)\n", x, y);
	// ft_bresenham_line(cub->player.c, cub->player.r, x, y, cub);

int	ft_iswall(t_cub *cub, int x, int y)
{
	int	r;
	int	c;

	r = y / cub->pixel;
	c = x / cub->pixel;

	if (r < 0 || c < 0 || r > cub->rows || c > cub->cols || cub->map[r][c] == '1' || cub->map[r][c] == ' ')
		return (1);
	return (0);
}

void	ft_draw_ray(t_cub *cub, double alpha)
{
	int		distance;
	double	a;
	double	b;
	int		y;
	int		x;

	distance = 0;
	while (1)
	{
		a = distance * cos(alpha);
		b = distance * sin(-alpha);
		x = cub->player.c + a;
		y = cub->player.r + b;
		if (ft_iswall(cub, x, y))
			break;
		else
			mlx_put_pixel(cub->mlx.image, x, y, ft_pixel(255, 0, 0, 255 * exp(-0.0065 * distance)));
		distance++;
	}
}

void	ft_draw_rays(t_cub *cub, double start_angle, double end_angle)
{
	while (start_angle <= end_angle)
	{
		ft_draw_ray(cub, start_angle);
		start_angle +=  0.001;
	}
}

void	ft_player_init(t_cub *cub)
{
	int	r;
	int	c;

	r = cub->player.r;
	c = cub->player.c;
	cub->player.r = cub->pixel * (cub->player.r + 0.5);
	cub->player.c = cub->pixel * (cub->player.c + 0.5);
	cub->map[r][c] = '0';
	cub->player.radius = 5;
	cub->player.turn = 0;
	cub->player.walk = 0;
	cub->player.player_color = ft_pixel(255, 255, 0, 255);
	cub->player.ray_color = ft_pixel(255, 0, 0, 100);
	if (cub->player.sens == 'N')
		cub->player.rot_angle = M_PI / 2;
	else if (cub->player.sens == 'W')
		cub->player.rot_angle = M_PI;
	else if (cub->player.sens == 'E')
		cub->player.rot_angle = 0;
	else if (cub->player.sens == 'S')
		cub->player.rot_angle = (3 * M_PI) / 2;
	cub->player.move_speed = 5;
	cub->player.rot_speed = 2 * (M_PI / 180);
}
