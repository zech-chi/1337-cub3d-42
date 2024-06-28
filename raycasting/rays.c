/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:23:48 by zech-chi          #+#    #+#             */
/*   Updated: 2024/06/28 22:34:21 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
	delta_x;
	delta_y;
	distance;
	xintercept;
	yintercept;
*/

bool	ft_find_wall(double x, double y, t_cub *cub)
{
	int	r;
	int	c;

	r = x / PIXEL;
	c = y / PIXEL;
	if (r < 0 || c < 0 || r >= cub->rows || c >= cub->cols)
		return (true);
	if (cub->map[r][c] == '1') //cub.map[r][c] == ' '
		return (true);
	return (false);
}

double	ft_horizontal(t_cub *cub, int i)
{
	double	deltax;
	double	deltay;
	double	xintercept;
	double	yintercept;
	double	nextx;
	double	nexty;
	bool	found_horz_hit;
	double	hitx;
	double	hity;

	found_horz_hit = false;
	yintercept = (floor(cub->player.py / PIXEL) + cub->rays[i].down) * PIXEL;
	xintercept = cub->player.px + (yintercept - cub->player.py) / tan(cub->rays[i].angle);
	deltay = PIXEL;
	deltax = deltay / tan(cub->rays[i].angle);
	if (cub->rays[i].down)
		deltay *= -1;
	if ((cub->rays[i].left && deltax > 0) || (cub->rays[i].right && deltax < 0))
		deltax *= -1;
	nextx = xintercept;
	nexty = yintercept;
	if (cub->rays[i].up)
		nexty--;
	while (nextx >= 0 && nextx < WINDOW_WIDTH && nexty >= 0 && nexty < WINDOW_HEIGHT)
	{
		if (ft_find_wall(nextx, nexty, cub))
		{
			found_horz_hit = true;
			hitx = nextx;
			hity = nexty;
			break;
		}
		else
		{
			nextx += deltax;
			nexty += deltay;
		}
	}
	if (found_horz_hit)
		return (ft_get_distance(cub->player.px, cub->player.py, hitx, hity));
	return (INT_MAX);
}

double	ft_vertical(t_cub *cub, int i)
{
	double	deltax;
	double	deltay;
	double	xintercept;
	double	yintercept;
	double	nextx;
	double	nexty;
	bool	found_vert_hit;
	double	hitx;
	double	hity;

	found_vert_hit = false;
	xintercept = (floor(cub->player.px / PIXEL) + cub->rays[i].right) * PIXEL;
	yintercept = cub->player.py + (xintercept - cub->player.px) * tan(cub->rays[i].angle);
	deltax = PIXEL;
	deltay = deltax * tan(cub->rays[i].angle);
	if (cub->rays[i].left)
		deltax *= -1;
	if ((cub->rays[i].up && deltay > 0) || (cub->rays[i].down && deltay < 0))
		deltay *= -1;
	nextx = xintercept;
	nexty = yintercept;
	if (cub->rays[i].left)
		nextx--;
	while (nextx >= 0 && nextx < WINDOW_WIDTH && nexty >= 0 && nexty < WINDOW_HEIGHT)
	{
		if (ft_find_wall(nextx, nexty, cub))
		{
			found_vert_hit = true;
			hitx = nextx;
			hity = nexty;
			break;
		}
		else
		{
			nextx += deltax;
			nexty += deltay;
		}
	}
	if (found_vert_hit)
		return (ft_get_distance(cub->player.px, cub->player.py, hitx, hity));
	return (INT_MAX);
}

void	ft_raycasting(t_cub *cub, double ray_angle, int	i)
{
	// double	hit_x;
	// double	hit_y;

	ray_angle = ft_periodic(ray_angle);
	cub->rays[i].angle = ray_angle;
	cub->rays[i].up = ray_angle > 0 && ray_angle < M_PI;
	cub->rays[i].down = !cub->rays[i].up;
	cub->rays[i].right = ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI;
	cub->rays[i].left = !cub->rays[i].right;
	cub->rays[i].distance = ft_min(ft_horizontal(cub, i), ft_vertical(cub, i));
}

void	ft_rays(t_cub *cub)
{
	double	ray_angle;
	int		i;

	ray_angle = cub->player.angle + M_PI / 6.0;
	i = -1;
	while (++i < NUMBER_RAYS)
	{
		ft_raycasting(cub, ray_angle, i);
		ray_angle -= (M_PI / (3.0 * NUMBER_RAYS));
	}
}
