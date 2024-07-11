/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:01:31 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/11 21:11:55 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

void	f(void)
{
	system("leaks cub3D");
}

void	ft_create_threads(t_cub *cub)
{
	int	i;
	int	j;

	i = pthread_create(&cub->thread.id_background_music, NULL, ft_routine, cub);
	j = pthread_create(&cub->thread.id_sound, NULL, ft_routine2, cub);
	if (i != 0 || j != 0)
	{
		ft_putstr_fd("Failed to create thread", 2, 1, RED);
		ft_free_data(cub);
		exit(FAILED);
	}
	if (pthread_detach(cub->thread.id_sound))
	{
		ft_putstr_fd("Failed to detach thread", 2, 1, RED);
		ft_free_data(cub);
		exit(FAILED);
	}
	if (pthread_detach(cub->thread.id_background_music))
	{
		ft_putstr_fd("Failed to detach thread", 2, 1, RED);
		ft_free_data(cub);
		exit(FAILED);
	}
}

int	main(int ac, char **av)
{
	t_cub		cub;
	int			i;

	i = 0;
	atexit(f);
	ft_mtx_init(&cub);
	ft_parsing(ac, av, &cub);
	ft_create_threads(&cub);
	ft_build_maze(&cub); 
	// if (pthread_join(cub.thread.id_background_music, NULL))
	// {
	// 	ft_putstr_fd("Failed to join thread", 2, 1, RED);
	// 	ft_free_data(&cub);
	// 	exit(FAILED);
	// }
	ft_free_data(&cub);
	return (0);
}
