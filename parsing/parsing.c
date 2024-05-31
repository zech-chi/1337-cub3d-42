/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:21:03 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/31 16:51:23 by zelabbas         ###   ########.fr       */
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
	int fd;
	if (ac != 2)
		return (ft_putstr_fd("Error: Invalid arguments", 2, 1, RED), FAILED);
	ft_data_init(cub);
	if (ft_isvalidname(av[1]))
		return (FAILED);
	fd = ft_openfile(av[1]);
	// cub->map = ft_getmap(fd);
	ft_putstr_fd("Good args", 1, 1, GREEN);
	return (SUCCESS);
}
