/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:44:30 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/09 18:51:19 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static bool	ft_draw_point(t_cub *cub, t_vector cur, t_vector start)
{
	float		distance;
	int			a;
	uint32_t	color;

	if (cur.x >= 0 && cur.y >= 0 && cur.x < cub->cols * \
	PIXEL_MINI && cur.y < cub->rows * PIXEL_MINI)
	{
		if (cur.x < 0 || cur.y < 0 || cur.x >= MINIMAP_WIDTH || \
		cur.y >= MINIMAP_HEIGHT || pow(cur.x - start.x, 2) + \
		pow(cur.y - start.y, 2) >= pow(MINIMAP_RADIUS, 2))
			return (false);
		distance = ft_get_distance(start.x, start.y, cur.x, cur.y);
		a = max(255 * exp(-0.025 * distance), 0);
		color = ft_color(255, 255, 0, a);
		mlx_put_pixel(cub->mlx.player_rays, cur.x, cur.y, color);
	}
	return (true);
}

static void	ft_step_1(int *err, t_vector *cur, t_vector diff, t_vector step)
{
	(*err) -= diff.y;
	cur->x += step.x;
}

static void	ft_step_2(int *err, t_vector *cur, t_vector diff, t_vector step)
{
	(*err) += diff.x;
	cur->y += step.y;
}

void	ft_draw_line(t_vector start, t_vector end, t_cub *cub)
{
	t_vector	step;
	t_vector	diff;
	t_vector	cur;
	int			err;
	int			e2;

	cur.x = start.x;
	cur.y = start.y;
	diff.x = abs(end.x - cur.x);
	diff.y = abs(end.y - cur.y);
	step.x = 1 * (cur.x < end.x) - 1 * (cur.x >= end.x);
	step.y = 1 * (cur.y < end.y) - 1 * (cur.y >= end.y);
	err = diff.x - diff.y;
	while (true)
	{
		if (!ft_draw_point(cub, cur, start) || \
		(cur.x == end.x && cur.y == end.y))
			break ;
		e2 = 2 * err;
		if (e2 > -diff.y)
			ft_step_1(&err, &cur, diff, step);
		if (e2 < diff.x)
			ft_step_2(&err, &cur, diff, step);
	}
}
