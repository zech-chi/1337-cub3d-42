/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:21:03 by zech-chi          #+#    #+#             */
/*   Updated: 2024/06/28 16:28:06 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
	cub->pixel = 32;
	cub->render = true;
}

void	ft_parsing(int ac, char **av, t_cub *cub)
{
	if (ac != 2)
	{
		ft_putstr_fd("Error: Invalid arguments", 2, 1, RED);
		exit(FAILED);
	}
	ft_data_init(cub);
	ft_valid_name(av[1]);
	ft_scan_file(cub, av[1]);
	ft_create_map(cub);
	ft_scan_map(cub);
	ft_player_init(cub);
	ft_putstr_fd("Good args", 1, 1, GREEN);
}
