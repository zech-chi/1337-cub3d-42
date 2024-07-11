/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:01:31 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/11 17:49:50 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

void	f(void)
{
	system("leaks cub3D");
}

int	main(int ac, char **av)
{
	t_cub	cub;

	atexit(f);
	ft_parsing(ac, av, &cub);
	ft_build_maze(&cub);
	ft_free_data(&cub);
	return (0);
}
