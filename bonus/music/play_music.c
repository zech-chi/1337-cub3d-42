/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_music.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:12:02 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/12 08:17:59 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_mtx_init(t_cub *cub)
{
	if (pthread_mutex_init(&(cub->thread.mtx_stop), NULL))
	{
		ft_putstr_fd("Failed to init a mutex", 2, 1, RED);
		ft_free_data(cub);
		exit(FAILED);
	}
	cub->thread.mtx_count++;
	if (pthread_mutex_init(&(cub->thread.mtx_protect), NULL))
	{
		ft_putstr_fd("Failed to init a mutex", 2, 1, RED);
		ft_free_data(cub);
		exit(FAILED);
	}
	cub->thread.mtx_count++;
}

bool	ft_mtx_get_stop(t_cub *cub)
{
	bool	stop;

	pthread_mutex_lock(&(cub->thread.mtx_stop));
	stop = cub->stop;
	pthread_mutex_unlock(&(cub->thread.mtx_stop));
	return (stop);
}

void	ft_mtx_set_stop(t_cub *cub)
{
	pthread_mutex_lock(&(cub->thread.mtx_stop));
	cub->stop = true;
	pthread_mutex_unlock(&(cub->thread.mtx_stop));
}

void	*ft_routine(void *args)
{
	int		pid;
	t_cub	*cub;

	cub = (t_cub *)args;
	while (!ft_mtx_get_stop(cub))
	{
		pid = fork();
		if (pid < 0)
			exit(1);
		if (pid == 0)
		{
			execlp("afplay", "afplay", WAR_SOUND_PATH, (char *) NULL);
			exit(1);
		}
		while (!waitpid(pid, NULL, WNOHANG) && !ft_mtx_get_stop(cub))
			usleep(1000);
	}
	kill(pid, SIGTERM);
	return (NULL);
}
