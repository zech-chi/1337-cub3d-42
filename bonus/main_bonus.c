/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:01:31 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/12 09:32:10 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d_bonus.h"

void	f(void)
{
	system("leaks cub3Dbonus");
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

void	ft_check_path_music(void)
{
	if (access(RELOAD_SOUND_PATH, F_OK) == -1 \
	|| access(RELOAD_SOUND_PATH, R_OK) == -1 \
	|| access(WAR_SOUND_PATH, F_OK) == -1 \
	|| access(WAR_SOUND_PATH, R_OK) == -1 \
	|| access(SHOOT_SOUND_PATH, F_OK) == -1 \
	|| access(SHOOT_SOUND_PATH, R_OK) == -1)
	{
		ft_putstr_fd("can't load all sound files", 2, 1, RED);
		exit(FAILED);
	}
}

int	main(int ac, char **av)
{
	t_cub		cub;
	int			i;

	i = 0;
	atexit(f);
	ft_check_path_music();
	ft_parsing(ac, av, &cub);
	ft_mtx_init(&cub);
	ft_create_threads(&cub);
	ft_build_maze(&cub);
	ft_free_data(&cub);
	return (0);
}
