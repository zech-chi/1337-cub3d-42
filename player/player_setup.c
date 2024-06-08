/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:48:07 by zech-chi          #+#    #+#             */
/*   Updated: 2024/06/08 11:10:40 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_draw_player(t_cub *cub)
{
	int	x;
	int	y;
	double	start_angle;
	double	end_angle;

	start_angle = cub->player.rot_angle - M_PI / 6;
	end_angle = cub->player.rot_angle + M_PI / 6;
	ft_draw_rays(cub, start_angle, end_angle);
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

int	ft_between(double alpha, double angle_start, double angle_end)
{
	if (angle_start < alpha && alpha < angle_end)
		return (1);
	return (0);
}

int	ft_iswall(t_cub *cub, int x, int y, double alpha)
{
	int	r;
	int	c;
	int	pr;
	int	pc;

	r = y / cub->pixel;
	c = x / cub->pixel;
	pr = cub->player.r / cub->pixel;
	pc = cub->player.c / cub->pixel;
	if (r < 0 || c < 0 || r > cub->rows || c > cub->cols || cub->map[r][c] == '1' || cub->map[r][c] == ' ')
		return (1);
	if ((ft_between(alpha, 0, M_PI / 2) || ft_between(alpha, 2 * M_PI, 2 * M_PI + M_PI / 2))  && cub->map[r + 1][c] == '1' && cub->map[r][c - 1] == '1' && r != pr && c != pc)
		return (1);
	if ((ft_between(alpha, 3 * M_PI / 2, 2 * M_PI) || ft_between(alpha, -M_PI / 2, 0))  && cub->map[r - 1][c] == '1' && cub->map[r][c - 1] == '1' && r != pr && c != pc)
		return (1);
	if (ft_between(alpha, M_PI, 3 * M_PI / 2)  && cub->map[r - 1][c] == '1' && cub->map[r][c + 1] == '1' && r != pr && c != pc)
		return (1);
	if (ft_between(alpha, M_PI / 2, M_PI) && cub->map[r + 1][c] == '1' && cub->map[r][c + 1] == '1' && r != pr && c != pc)
		return (1);
	(void)alpha;
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
		if (ft_iswall(cub, x, y, alpha))
			break;
		else
			mlx_put_pixel(cub->mlx.image, x, y, ft_pixel(255, 0, 0, 255 * exp(-0.008 * distance)));
			// mlx_put_pixel(cub->mlx.image, x, y, ft_pixel(255, 255, 255, 255 * exp(-0.004 * distance)));
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
	// cub->player.player_color = ft_pixel(255, 0, 0, 255);
	cub->player.ray_color = ft_pixel(255, 0, 0, 100);
	if (cub->player.sens == 'N')
		cub->player.rot_angle = M_PI / 2;
	else if (cub->player.sens == 'W')
		cub->player.rot_angle = M_PI;
	else if (cub->player.sens == 'E')
		cub->player.rot_angle = 0;
	else if (cub->player.sens == 'S')
		cub->player.rot_angle = (3 * M_PI) / 2;
	cub->player.move_speed = 3;
	cub->player.rot_speed = 2 * (M_PI / 180);
}
