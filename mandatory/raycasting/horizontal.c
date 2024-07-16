/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:28:55 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/11 17:39:42 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_init_horz_data(t_cub *cub, int i)
{
	cub->rays[i].horz.found_horz_hit = false;
	cub->rays[i].horz.yintercept = floor(cub->player.py / PIXEL) * PIXEL;
	cub->rays[i].horz.yintercept += cub->rays[i].down * PIXEL;
	cub->rays[i].horz.xintercept = cub->player.px + \
	((cub->player.py - cub->rays[i].horz.yintercept) / tan(cub->rays[i].angle));
	cub->rays[i].horz.deltay = PIXEL;
	if (cub->rays[i].up)
		cub->rays[i].horz.deltay *= -1;
	cub->rays[i].horz.deltax = PIXEL / tan(cub->rays[i].angle);
	if ((cub->rays[i].left && cub->rays[i].horz.deltax > 0) \
	|| (cub->rays[i].right && cub->rays[i].horz.deltax < 0))
		cub->rays[i].horz.deltax *= -1;
	cub->rays[i].horz.nextx = cub->rays[i].horz.xintercept;
	cub->rays[i].horz.nexty = cub->rays[i].horz.yintercept;
}

static bool	ft_check_wall_horz(t_cub *cub, int i)
{
	int	r;
	int	c;

	r = (cub->rays[i].horz.nexty - cub->rays[i].up + cub->rays[i].down) / PIXEL;
	c = cub->rays[i].horz.nextx / PIXEL;
	if (r < 0 || c < 0 || r >= cub->rows || c >= cub->cols)
		return (true);
	if (cub->map[r][c] == '1' || cub->map[r][c] == ' ')
		return (true);
	return (false);
}

float	ft_horizontal(t_cub *cub, int i)
{
	ft_init_horz_data(cub, i);
	while (cub->rays[i].horz.nextx >= 0 && cub->rays[i].horz.nextx <= \
	cub->cols * PIXEL && cub->rays[i].horz.nexty >= 0 && \
	cub->rays[i].horz.nexty <= cub->rows * PIXEL)
	{
		if (ft_check_wall_horz(cub, i))
		{
			cub->rays[i].horz.found_horz_hit = true;
			cub->rays[i].horz.hitx = cub->rays[i].horz.nextx;
			cub->rays[i].horz.hity = cub->rays[i].horz.nexty;
			cub->rays[i].horz.hithorzx = cub->rays[i].horz.hitx;
			cub->rays[i].horz.hithorzy = cub->rays[i].horz.hity;
			break ;
		}
		else
		{
			cub->rays[i].horz.nextx += cub->rays[i].horz.deltax;
			cub->rays[i].horz.nexty += cub->rays[i].horz.deltay;
		}
	}
	if (cub->rays[i].horz.found_horz_hit)
		return (ft_get_distance(cub->player.px, cub->player.py, \
		cub->rays[i].horz.hitx, cub->rays[i].horz.hity));
	return (INT_MAX);
}
