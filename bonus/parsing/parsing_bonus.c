/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:21:03 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/15 19:29:05 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static void	ft_data_init2(t_cub *cub)
{
	cub->mlx.frame = 0;
	cub->mlx.cur_index = 0;
	cub->mlx.status = MLX_MOUSE_NORMAL;
	cub->mlx.init_state = true;
	cub->mlx.normal_shoot1 = false;
	cub->mlx.zome_shoot1 = false;
	cub->mlx.reload = false;
	cub->mlx.weapon_magazin_index = 0;
	cub->mlx.index_weapon = 0;
	cub->mlx.maze_img = NULL;
	cub->mlx.canva = NULL;
	cub->mlx.no_img = NULL;
	cub->mlx.so_img = NULL;
	cub->mlx.we_img = NULL;
	cub->mlx.ea_img = NULL;
	cub->mlx.minimap = NULL;
	cub->mlx.player_rays = NULL;
	cub->mlx.black = NULL;
	cub->mlx.background_start = NULL;
	cub->mlx.door = NULL;
	cub->mlx.weapon_magazin = NULL;
	cub->mlx.circle = NULL;
	cub->mlx.target = NULL;
	cub->mlx.sky = NULL;
	cub->mlx.shoot_target = NULL;
}

static void	ft_data_init(t_cub *cub)
{
	cub->map = NULL;
	cub->no = NULL;
	cub->so = NULL;
	cub->we = NULL;
	cub->ea = NULL;
	cub->cf = NULL;
	cub->cc = NULL;
	cub->line = NULL;
	cub->head = NULL;
	cub->rows = 0;
	cub->cols = 0;
	cub->player.pr = -1;
	cub->player.pc = -1;
	cub->fd = -1;
	cub->pixel = PIXEL;
	cub->render = true;
	cub->horizon = 0;
	cub->stop = false;
	cub->angle_minimap = 0;
	cub->player.jump = false;
	cub->play_weapon = false;
	cub->light_on = false;
	cub->mlx.mlx_ptr = NULL;
	cub->thread.mtx_count = 0;
	ft_data_init2(cub);
}

void	ft_parsing(int ac, char **av, t_cub *cub)
{
	if (ac != 2)
	{
		ft_putstr_fd("Error\nInvalid arguments", 2, 1, RED);
		exit(FAILED);
	}
	ft_data_init(cub);
	ft_valid_name(av[1]);
	ft_scan_file(cub, av[1]);
	ft_create_map(cub);
	ft_scan_map(cub);
	if (!cub->map || cub->player.pr == -1 || cub->player.pc == -1)
	{
		ft_putstr_fd("Error\nInvalid map", 2, 1, RED);
		ft_free_data(cub);
		exit(FAILED);
	}
	ft_player_init(cub);
}
