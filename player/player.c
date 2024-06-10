/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:10:21 by zelabbas          #+#    #+#             */
/*   Updated: 2024/06/10 18:58:41 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_render_player(t_cub *cub)
{
	for (int i = cub->player.py - 1; i < cub->player.py + 1; i++)
	{
		for (int j = cub->player.px - 1; j < cub->player.px + 1; j++)
		{
			mlx_put_pixel(cub->mlx.maze_img, j, i, ft_color(255, 0, 0, 255));
		}
	}
}

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

void	ft_walk_up(t_cub *cub)
{
	double	a;
	double	b;

	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_W))
	{
		a = cub->player.walk_speed * cos(cub->player.angle);
		b = -1 * cub->player.walk_speed * sin(cub->player.angle);
		if (!ft_iswall2(cub, cub->player.px + 10 * a, cub->player.py + 10 * b, cub->player.angle))
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
				!ft_iswall2(cub, cub->player.px + 2 * a, cub->player.py + 2 * b, cub->player.angle + M_PI)
			) || (
				ft_between(cub->player.angle, M_PI, 3 * M_PI / 2) && \
				!ft_iswall2(cub, cub->player.px + 2 * a, cub->player.py + 2 * b, cub->player.angle - M_PI)
			) || (
				ft_between(cub->player.angle, M_PI / 2, M_PI) && \
				!ft_iswall2(cub, cub->player.px + 2 * a, cub->player.py + 2 * b, cub->player.angle + M_PI)
			) || (
				ft_between(cub->player.angle, 3 * M_PI / 2, 2 * M_PI) && \
				!ft_iswall2(cub, cub->player.px + 2 * a, cub->player.py + 2 * b, cub->player.angle - M_PI)
			)
		)
		{
			cub->player.py += b;
			cub->player.px += a;
			cub->player.pr = cub->player.py / cub->pixel;
			cub->player.pc = cub->player.px / cub->pixel;
			cub->render = true;
			printf("trmt taha\n");
		}
	}
}


void	ft_turn_left(t_cub *cub)
{
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_LEFT))
	{
		cub->player.angle += cub->player.turn_speed;
		if (cub->player.angle >= 2 * M_PI)
			cub->player.angle -= 2 * M_PI;
		cub->render = true;
		printf("%f\n", cub->player.angle);
	}
}

void	ft_turn_right(t_cub *cub)
{
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_RIGHT))
	{
		cub->player.angle -= cub->player.turn_speed;
		if (cub->player.angle < 0)
			cub->player.angle += 2 * M_PI;
		cub->render = true;
		printf("%f\n", cub->player.angle);
	}
}

void	ft_player_event(t_cub *cub)
{
	ft_walk_up(cub);
	ft_walk_down(cub);
	ft_turn_left(cub);
	ft_turn_right(cub);
	
}

void	ft_player_init(t_cub *cub)
{
	int	r;
	int	c;

	r = cub->player.pr;
	c = cub->player.pc;
	cub->player.py = cub->pixel * (cub->player.pr + 0.5);
	cub->player.px = cub->pixel * (cub->player.pc + 0.5);
	cub->map[r][c] = '0';
	if (cub->player.sens == 'N')
		cub->player.angle = M_PI / 2;
	else if (cub->player.sens == 'W')
		cub->player.angle = M_PI;
	else if (cub->player.sens == 'E')
		cub->player.angle = 0;
	else if (cub->player.sens == 'S')
		cub->player.angle = (3 * M_PI) / 2;
	cub->player.walk_speed = 2;
	cub->player.turn_speed = 2 * (M_PI / 180);
}
