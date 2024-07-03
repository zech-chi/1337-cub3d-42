/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 21:10:21 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/03 12:30:32 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// void	ft_render_player(t_cub *cub)
// {
// 	for (int i = cub->player.py - 1; i < cub->player.py + 1; i++)
// 	{
// 		for (int j = cub->player.px - 1; j < cub->player.px + 1; j++)
// 		{
// 			mlx_put_pixel(cub->mlx.maze_img, j, i, ft_color(255, 0, 0, 255));
// 		}
// 	}
// }

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
		if (ft_between(cub->player.angle, 1.5 * M_PI, 2 * M_PI) && ft_iswall2(cub, cub->player.px + 100, cub->player.py, cub->player.angle))
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

void	ft_turn_left(t_cub *cub)
{
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_LEFT))
	{
		cub->player.angle += cub->player.turn_speed;
		cub->player.angle = ft_periodic(cub->player.angle);
		cub->render = true;
		// printf("%f\n", cub->player.angle);
	}
}

void	ft_turn_right(t_cub *cub)
{
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_RIGHT))
	{
		cub->player.angle -= cub->player.turn_speed;
		cub->player.angle = ft_periodic(cub->player.angle);
		cub->render = true;
		// printf("%f\n", cub->player.angle);
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
		if (!ft_iswall2(cub, cub->player.px + N_STEPS * a, cub->player.py + N_STEPS * b, cub->player.angle + M_PI_2))
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
		if (!ft_iswall2(cub, cub->player.px + N_STEPS * a, cub->player.py + N_STEPS * b, cub->player.angle - M_PI_2))
		{
			cub->player.py += b;
			cub->player.px += a;
			cub->player.pr = cub->player.py / cub->pixel;
			cub->player.pc = cub->player.px / cub->pixel;
			cub->render = true;
		}
	}
}

void	ft_look_up(t_cub *cub)
{
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_UP))
	{
		if (cub->horizon < HORIZON)
		{
			(cub->horizon) += LOOK_SPEED;
			cub->render = true;
		}
	}
}
void	ft_look_down(t_cub *cub)
{
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_DOWN))
	{
		if (cub->horizon > -(HORIZON))
		{
			(cub->horizon) -= LOOK_SPEED;
			cub->render = true;
		}
	}
}


// void	ft_play_weapon(t_cub *cub)
// {
// 	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_P))
// 	{
// 		printf("p pressd\n");
// 		// cub->play_weapon = true;
// 		printf("\n\n\n");
// 		for (int i = 0; i < WEAPONS; i++) {
// 			mlx_image_to_window(cub->mlx.mlx_ptr, cub->mlx.black_img, 930, 0);
// 			mlx_image_to_window(cub->mlx.mlx_ptr, cub->mlx.weapon[i], 930, 0);
// 			for (size_t i = 0; i < 99999999999999999999; i++);0

// 			printf("%d\n", i);
// 		}
// 	}
// }

// void mouse_hook(mouse_key_t button, action_t action, modifier_key_t mods, void *param)
// {
//     (void)param;
//     (void)mods;
//     if (action == MLX_PRESS)
//     {
//         if (button == MLX_MOUSE_BUTTON_LEFT)
//         {
//             printf("Left mouse button pressed\n");
//         }
//         else if (button == MLX_MOUSE_BUTTON_RIGHT)
//         {
//             printf("Right mouse button pressed\n");
//         }
//         else if (button == MLX_MOUSE_BUTTON_MIDDLE)
//         {
//             printf("Middle mouse button pressed\n");
//         }
//     }
// }
void	ft_enable_mouse(t_cub *cub)
{
	// if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_E))
	// {
		mlx_set_cursor_mode(cub->mlx.mlx_ptr, MLX_MOUSE_HIDDEN);
		cub->mlx.status = MLX_MOUSE_HIDDEN;
	// }
}
void	ft_disable_mouse(t_cub *cub)
{
	// if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_I))
	// {
		mlx_set_cursor_mode(cub->mlx.mlx_ptr, MLX_MOUSE_NORMAL);
		cub->mlx.status = MLX_MOUSE_NORMAL;
	// }
}

void	mouse_func(double xpos, double ypos, void *param)
{
	t_cub	*cub;

	cub = param;
	if (cub->mlx.status == MLX_MOUSE_NORMAL)
		return ;
	(void)ypos;
	if (ypos > (WINDOW_HEIGHT / 2))
	{
		if (cub->horizon > -(HORIZON))
		{
			(cub->horizon) -= LOOK_SPEED;
			cub->render = true;
		}
	}
	else if (ypos < (WINDOW_HEIGHT / 2))
	{
		if (cub->horizon < HORIZON)
		{
			(cub->horizon) += LOOK_SPEED;
			cub->render = true;
		}
	}
	if (xpos > (WINDOW_WIDTH / 2 + 930) + 10)
	{
		cub->player.angle -= cub->player.turn_speed;
		cub->player.angle = ft_periodic(cub->player.angle);
		cub->render = true;
	}
	else if (xpos < (WINDOW_WIDTH / 2 + 930) - 10)
	{
		cub->player.angle += cub->player.turn_speed;
		cub->player.angle = ft_periodic(cub->player.angle);
		cub->render = true;
	}
	mlx_set_mouse_pos(cub->mlx.mlx_ptr, WINDOW_WIDTH / 2 + 930, WINDOW_HEIGHT / 2);
}

void	ft_player_event(t_cub *cub)
{
	ft_walk_up(cub);
	ft_walk_down(cub);
	ft_turn_left(cub);
	ft_turn_right(cub);
	ft_walk_left(cub);
	ft_walk_right(cub);
	ft_look_up(cub);
	ft_look_down(cub);
	// ft_enable_mouse(cub);
	// ft_disable_mouse(cub);
	// mlx_cursor_hook(cub->mlx.mlx_ptr, mouse_func, cub);
	// ft_play_weapon(cub);
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
	cub->player.walk_speed = WALK_SPEED;
	cub->player.turn_speed = TURN_SPEED;
}
