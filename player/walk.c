/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:06:53 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/03 15:37:19 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


int	ft_iswall2(t_cub *cub, int x, int y, double alpha)
{
	int	r;
	int	c;

	r = y / cub->pixel;
	c = x / cub->pixel;
	if (r == cub->player.pr && c == cub->player.pc)
		return (0);
	if (r < 0 || c < 0 || r > cub->rows || c > cub->cols || cub->map[r][c] == '1' || cub->map[r][c] == ' ')
		return (1);
	if (ft_between(alpha, 0, M_PI / 2) && cub->map[r + 1][c] == '1' && cub->map[r][c - 1] == '1')
		return (1);
	if (ft_between(alpha, 3 * M_PI / 2, 2 * M_PI) && cub->map[r - 1][c] == '1' && cub->map[r][c - 1] == '1')
		return (1);
	if (ft_between(alpha, M_PI, 3 * M_PI / 2) && cub->map[r - 1][c] == '1' && cub->map[r][c + 1] == '1')
		return (1);
	if (ft_between(alpha, M_PI / 2, M_PI) && cub->map[r + 1][c] == '1' && cub->map[r][c + 1] == '1')
		return (1);
	return (0);
}

bool	ft_can_walk(t_cub *cub)
{
	float	angle;
	float	x;
	float	y;

	angle = cub->player.angle;
	x = cub->player.px;
	y = cub->player.py;
	if (ft_between(angle, PI, _3PI2) && ft_iswall2(cub, x, y + SCALE, angle))
		return (false);
	if (ft_between(angle, PI, _3PI2) && ft_iswall2(cub, x - SCALE, y, angle))
		return (false);
	if (ft_between(angle, 0, PI2) && ft_iswall2(cub, x + SCALE, y, angle))
		return (false);
	if (ft_between(angle, 0, PI2) && ft_iswall2(cub, x, y - SCALE, angle))
		return (false);
	if (ft_between(angle, _3PI2, _2PI) && ft_iswall2(cub, x + SCALE, y, angle))
		return (false);
	if (ft_between(angle, _3PI2, _2PI) && ft_iswall2(cub, x, y + SCALE, angle))
		return (false);
	if (ft_between(angle, PI2, PI) && ft_iswall2(cub, x - SCALE, y, angle))
		return (false);
	if (ft_between(angle, PI2, PI) && ft_iswall2(cub, x, y - SCALE, angle))
		return (false);
	return (true);
}


void	ft_walk_up(t_cub *cub)
{
	double	a;
	double	b;

	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_W))
	{
		if (!ft_can_walk(cub))
			return ;
		a = cub->player.walk_speed * cos(cub->player.angle);
		b = -1 * cub->player.walk_speed * sin(cub->player.angle);
		if (!ft_iswall2(cub, cub->player.px + N_STEPS * a, cub->player.py + N_STEPS * b, cub->player.angle))
		{
			cub->player.py += b;
			cub->player.px += a;
			cub->player.pr = cub->player.py / cub->pixel;
			cub->player.pc = cub->player.px / cub->pixel;
			cub->render = true;
		}
	}
}

void	ft_walk_down(t_cub *cub)
{
	double	a;
	double	b;

	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_S))
	{
		a = -1 * cub->player.walk_speed * cos(cub->player.angle);
		b = cub->player.walk_speed * sin(cub->player.angle);
		if (
			(
				ft_between(cub->player.angle, 0, M_PI / 2) && \
				!ft_iswall2(cub, cub->player.px + N_STEPS * a, cub->player.py + N_STEPS * b, cub->player.angle + M_PI)
			) || (
				ft_between(cub->player.angle, M_PI, 3 * M_PI / 2) && \
				!ft_iswall2(cub, cub->player.px + N_STEPS * a, cub->player.py + N_STEPS * b, cub->player.angle - M_PI)
			) || (
				ft_between(cub->player.angle, M_PI / 2, M_PI) && \
				!ft_iswall2(cub, cub->player.px + N_STEPS * a, cub->player.py + N_STEPS * b, cub->player.angle + M_PI)
			) || (
				ft_between(cub->player.angle, 3 * M_PI / 2, 2 * M_PI) && \
				!ft_iswall2(cub, cub->player.px + N_STEPS * a, cub->player.py + N_STEPS * b, cub->player.angle - M_PI)
			)
		)
		{
			cub->player.py += b;
			cub->player.px += a;
			cub->player.pr = cub->player.py / cub->pixel;
			cub->player.pc = cub->player.px / cub->pixel;
			cub->render = true;
		}
	}
}

void	ft_walk_left(t_cub *cub)
{
	double	a;
	double	b;

	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_A))
	{
		a = cub->player.walk_speed * cos(cub->player.angle + M_PI_2);
		b = -1 * cub->player.walk_speed * sin(cub->player.angle + M_PI_2);
		if (!ft_iswall2(cub, cub->player.px + LEFT_RIGHT_STEP * a, cub->player.py + LEFT_RIGHT_STEP * b, cub->player.angle + M_PI_2))
		{
			cub->player.py += b;
			cub->player.px += a;
			cub->player.pr = cub->player.py / cub->pixel;
			cub->player.pc = cub->player.px / cub->pixel;
			cub->render = true;
		}
	}
}

void	ft_walk_right(t_cub *cub)
{
	double	a;
	double	b;

	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_D))
	{
		a = cub->player.walk_speed * cos(cub->player.angle - M_PI_2);
		b = -1 * cub->player.walk_speed * sin(cub->player.angle - M_PI_2);
		if (!ft_iswall2(cub, cub->player.px + LEFT_RIGHT_STEP * a, cub->player.py + LEFT_RIGHT_STEP * b, cub->player.angle - M_PI_2))
		{
			cub->player.py += b;
			cub->player.px += a;
			cub->player.pr = cub->player.py / cub->pixel;
			cub->player.pc = cub->player.px / cub->pixel;
			cub->render = true;
		}
	}
}
