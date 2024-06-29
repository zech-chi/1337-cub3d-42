/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:23:48 by zech-chi          #+#    #+#             */
/*   Updated: 2024/06/29 22:12:16 by zelabbas         ###   ########.fr       */
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

bool	ft_find_wall(float x, float y, t_cub *cub, int i)
{
	int	r;
	int	c;

	r = y / PIXEL;
	c = x / PIXEL;
	if (r < 0 || c < 0 || r >= cub->rows || c >= cub->cols)
		return (true);
	if (cub->map[r][c] == '1' || cub->map[r][c] == ' ')  //cub.map[r][c] == ' '
	{
		// printf("found wall at (r, c) = (%d, %d)\n", r, c);
		// if (i == 0)
		// 	printf("found wall at (r, c) = (%d, %d)\n", r, c);
		return (true);
	}
	(void)i;
	return (false);
}

float	ft_horizontal(t_cub *cub, int i)
{
	float	deltax;
	float	deltay;
	float	xintercept;
	float	yintercept;
	float	nextx;
	float	nexty;
	bool	found_horz_hit;
	float	hitx;
	float	hity;

	found_horz_hit = false;
	// yintercept = (floor(cub->player.py / PIXEL) + cub->rays[i].down) * PIXEL;

	yintercept = floor(cub->player.py / PIXEL) * PIXEL;
	yintercept += cub->rays[i].down * PIXEL;

	xintercept = cub->player.px + ((cub->player.py - yintercept) / tan(cub->rays[i].angle));
	deltay = PIXEL;
	if (cub->rays[i].up)
		deltay *= -1;
	deltax = PIXEL / tan(cub->rays[i].angle);
	if ((cub->rays[i].left && deltax > 0) || (cub->rays[i].right && deltax < 0))
		deltax *= -1;
	nextx = xintercept;
	nexty = yintercept;

	// if (i == 0)
	// {
	// 	printf("------start-------\n\n");
	// 	printf("px = %f\n", cub->player.px);
	// 	printf("py = %f\n", cub->player.py);
	// 	printf("xinter = %f\n", xintercept);
	// 	printf("yinter = %f\n", yintercept);
	// 	printf("deltax = %f\n", deltax);
	// 	printf("deltay = %f\n", deltay);
	// 	printf("rangle = %f\n", cub->rays[i].angle);
	// }
	while (nextx >= 0 && nextx <= cub->cols * PIXEL && nexty >= 0 && nexty <= cub->rows * PIXEL)
	{
		// if (i == 0)
		// {
		// 	printf("(%f, %f)\n",nexty / PIXEL,  nextx / PIXEL);
		// 	printf("(%d, %d)\n",  (int)(nexty / PIXEL) , (int)(nextx / PIXEL));
		// }
		if (ft_find_wall(nextx, nexty - cub->rays[i].up + cub->rays[i].down, cub, i))
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

float	ft_vertical(t_cub *cub, int i)
{
	float	deltax;
	float	deltay;
	float	xintercept;
	float	yintercept;
	float	nextx;
	float	nexty;
	bool	found_vert_hit;
	float	hitx;
	float	hity;

	found_vert_hit = false;
	xintercept = (floor(cub->player.px / PIXEL) + cub->rays[i].right) * PIXEL;
	yintercept = cub->player.py + (cub->player.px - xintercept) * tan(cub->rays[i].angle);
	deltax = PIXEL;
	if (cub->rays[i].left)
		deltax *= -1;
	deltay = PIXEL * tan(cub->rays[i].angle);
	if ((cub->rays[i].up && deltay > 0) || (cub->rays[i].down && deltay < 0))
		deltay *= -1;
	nextx = xintercept;
	nexty = yintercept;
	while (nextx >= 0 && nextx <= cub->cols * PIXEL && nexty >= 0 && nexty <= cub->rows * PIXEL)
	{
		if (ft_find_wall(nextx - cub->rays[i].left + cub->rays[i].right, nexty, cub, i))
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

void	ft_raycasting(t_cub *cub, float ray_angle, int	i)
{
	// float	hit_x;
	// float	hit_y;

	ray_angle = ft_periodic(ray_angle);
	cub->rays[i].angle = ray_angle;
	cub->rays[i].up = ray_angle > 0 && ray_angle < M_PI;
	cub->rays[i].down = !cub->rays[i].up;
	cub->rays[i].right = ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI;
	cub->rays[i].left = !cub->rays[i].right;

	cub->rays[i].horz_distance = ft_horizontal(cub, i);
	cub->rays[i].vert_distance = ft_vertical(cub, i);
	cub->rays[i].distance = ft_min(ft_horizontal(cub, i), ft_vertical(cub, i));
}

void	ft_rays(t_cub *cub)
{
	float	ray_angle;
	int		i;

	ray_angle = cub->player.angle + M_PI / 6.0;
	i = -1;
	while (++i < NUMBER_RAYS)
	{
		ft_raycasting(cub, ray_angle, i);
		ray_angle -= (M_PI / (3.0 * NUMBER_RAYS));
	}
}
