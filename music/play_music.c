/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_music.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:12:02 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/03 21:13:04 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_mtx_init(t_cub *cub)
{
	pthread_mutex_init(&(cub->thread.mtx_stop), NULL);
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
	int	pid;
	t_cub	*cub;

	cub = (t_cub *)args;
	while (!ft_mtx_get_stop(cub))
	{
		pid = fork();
		if (pid < 0)
			exit(1);
		if (pid == 0)
		{
			execlp("afplay", "afplay", "music/war.mp3", (char *)NULL);
			exit(1);
		}
		while (!waitpid(pid, 0, WNOHANG) && !ft_mtx_get_stop(cub));
	}
	kill(pid, SIGTERM);
	return (NULL);
}