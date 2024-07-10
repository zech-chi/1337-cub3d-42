/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:36:16 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/10 21:18:22 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_init_vert_data(t_cub *cub, int i)
{
	cub->rays[i].vert.found_shoot_target_vert = false;
	cub->rays[i].vert.found_door_vert = false;
	cub->rays[i].vert.found_vert_hit = false;
	cub->rays[i].vert.xintercept = (floor(cub->player.px / PIXEL) \
	+ cub->rays[i].right) * PIXEL;
	cub->rays[i].vert.yintercept = cub->player.py + \
	(cub->player.px - cub->rays[i].vert.xintercept) * tan(cub->rays[i].angle);
	cub->rays[i].vert.deltax = PIXEL;
	if (cub->rays[i].left)
		cub->rays[i].vert.deltax *= -1;
	cub->rays[i].vert.deltay = PIXEL * tan(cub->rays[i].angle);
	if ((cub->rays[i].up && cub->rays[i].vert.deltay > 0) \
	|| (cub->rays[i].down && cub->rays[i].vert.deltay < 0))
		cub->rays[i].vert.deltay *= -1;
	cub->rays[i].vert.nextx = cub->rays[i].vert.xintercept;
	cub->rays[i].vert.nexty = cub->rays[i].vert.yintercept;
}

static bool	ft_check_wall_vert(t_cub *cub, int i)
{
	int	r;
	int	c;

	r = (cub->rays[i].vert.nexty) / PIXEL;
	c = (cub->rays[i].vert.nextx - cub->rays[i].left + \
	cub->rays[i].right) / PIXEL;
	if (r < 0 || c < 0 || r >= cub->rows || c >= cub->cols)
		return (true);
	if (cub->map[r][c] == '1' || cub->map[r][c] == ' ' || \
	cub->map[r][c] == 'D' || cub->map[r][c] == 'T')
	{
		if (cub->map[r][c] == 'D')
			cub->rays[i].vert.found_door_vert = true;
		else if (cub->map[r][c] == 'T')
			cub->rays[i].vert.found_shoot_target_vert = true;
		return (true);
	}
	return (false);
}

float	ft_vertical(t_cub *cub, int i)
{
	ft_init_vert_data(cub, i);
	while (cub->rays[i].vert.nextx >= 0 && cub->rays[i].vert.nextx <= \
	cub->cols * PIXEL && cub->rays[i].vert.nexty >= 0 \
	&& cub->rays[i].vert.nexty <= cub->rows * PIXEL)
	{
		if (ft_check_wall_vert(cub, i))
		{
			cub->rays[i].vert.found_vert_hit = true;
			cub->rays[i].vert.hitx = cub->rays[i].vert.nextx;
			cub->rays[i].vert.hity = cub->rays[i].vert.nexty;
			cub->rays[i].vert.hitvertx = cub->rays[i].vert.hitx;
			cub->rays[i].vert.hitverty = cub->rays[i].vert.hity;
			break ;
		}
		else
		{
			cub->rays[i].vert.nextx += cub->rays[i].vert.deltax;
			cub->rays[i].vert.nexty += cub->rays[i].vert.deltay;
		}
	}
	if (cub->rays[i].vert.found_vert_hit)
		return (ft_get_distance(cub->player.px, cub->player.py, \
		cub->rays[i].vert.hitx, cub->rays[i].vert.hity));
	return (INT_MAX);
}
