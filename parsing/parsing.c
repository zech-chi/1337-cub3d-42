/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:21:03 by zech-chi          #+#    #+#             */
/*   Updated: 2024/06/01 21:47:18 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_display_linked_list(t_cub *cub)
{
	t_list	*node;

	node = cub->head;
	printf("#####################################\n");
	while (node)
	{
		printf("%s\n", node->content);
		node = node->next;
	}
	printf("#####################################\n");
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
	cub->pr = -1;
	cub->pc = -1;
	cub->fd = -1;
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
	if (ft_scan_map(cub))
		exit(1);
	ft_putstr_fd("Good args", 1, 1, GREEN);
}
