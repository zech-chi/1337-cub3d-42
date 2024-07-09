/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:44:38 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/09 15:51:19 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	ft_iswall2(t_cub *cub, int x, int y, double alpha)
{
	int	r;
	int	c;

	r = y / cub->pixel;
	c = x / cub->pixel;
	if (r == cub->player.pr && c == cub->player.pc)
		return (false);
	if (r < 0 || c < 0 || r > cub->rows || c > cub->cols \
	|| cub->map[r][c] == '1' || cub->map[r][c] == ' ')
		return (true);
	if (ft_between(alpha, 0, M_PI / 2) && cub->map[r + 1][c] == '1' \
	&& cub->map[r][c - 1] == '1')
		return (true);
	if (ft_between(alpha, 3 * M_PI / 2, 2 * M_PI) && cub->map[r - 1][c] == '1' \
	&& cub->map[r][c - 1] == '1')
		return (true);
	if (ft_between(alpha, M_PI, 3 * M_PI / 2) && cub->map[r - 1][c] == '1' \
	&& cub->map[r][c + 1] == '1')
		return (true);
	if (ft_between(alpha, M_PI / 2, M_PI) && cub->map[r + 1][c] == '1' \
	&& cub->map[r][c + 1] == '1')
		return (true);
	return (false);
}

bool	ft_can_walk_up(t_cub *cub)
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

bool	ft_can_walk_down(t_cub *cub, double a, double b)
{
	if (
		(
			ft_between(cub->player.angle, 0, M_PI / 2) && \
			!ft_iswall2(cub, cub->player.px + N_STEPS * a, \
			cub->player.py + N_STEPS * b, cub->player.angle + M_PI)
		) || (
			ft_between(cub->player.angle, M_PI, 3 * M_PI / 2) && \
			!ft_iswall2(cub, cub->player.px + N_STEPS * a, \
			cub->player.py + N_STEPS * b, cub->player.angle - M_PI)
		) || (
			ft_between(cub->player.angle, M_PI / 2, M_PI) && \
			!ft_iswall2(cub, cub->player.px + N_STEPS * a, \
			cub->player.py + N_STEPS * b, cub->player.angle + M_PI)
		) || (
			ft_between(cub->player.angle, 3 * M_PI / 2, 2 * M_PI) && \
			!ft_iswall2(cub, cub->player.px + N_STEPS * a, \
			cub->player.py + N_STEPS * b, cub->player.angle - M_PI)
		)
	)
		return (true);
	return (false);
}
