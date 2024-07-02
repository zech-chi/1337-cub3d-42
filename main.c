/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:01:31 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/02 20:09:49 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

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
			execlp("afplay", "afplay", "audio/war.mp3", (char *)NULL);
			exit(1);
		}
		while (!waitpid(pid, 0, WNOHANG) && !ft_mtx_get_stop(cub));
	}
	kill(pid, SIGTERM);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_cub		cub;

	ft_parsing(ac, av, &cub);
	ft_display(&cub);
	ft_mtx_init(&cub);
	pthread_create(&cub.thread.id_background_music, NULL, ft_routine, &cub);
	ft_build_maze(&cub);
	ft_mtx_set_stop(&cub);
	pthread_join(cub.thread.id_background_music, NULL);
	return (0);
}
