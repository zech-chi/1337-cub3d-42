/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:21:03 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/31 15:45:27 by zech-chi         ###   ########.fr       */
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
	cub->rows = 0;
	cub->cols = 0;
	cub->pr = -1;
	cub->pc = -1;
}

int	ft_parsing(int ac, char **av, t_cub *cub)
{
	if (ac != 2)
		return (ft_putstr_fd("Error: Invalid arguments", 2, 1, RED), FAILED);
	ft_data_init(cub);
	ft_putstr_fd("Good args", 1, 1, GREEN);
	(void)av;
	(void)cub;
	return (SUCCESS);
}
