/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_sound.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 03:40:13 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/11 03:40:13 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static void	ft_check_reaload_sound(t_cub *cub)
{
	int		pid;
	int		check;

	check = 1;
	pthread_mutex_lock(&(cub->thread.mtx_protect));
	if (cub->mlx.reload && cub->mlx.index_weapon == 20)
	{
		pthread_mutex_unlock(&(cub->thread.mtx_protect));
		check = 0;
		pid = fork();
		if (pid < 0)
			exit(1);
		if (pid == 0)
		{
			execlp("afplay", "afplay", RELOAD_SOUND_PATH, (char *) NULL);
			exit(1);
		}
		while (!waitpid(pid, NULL, WNOHANG) && !ft_mtx_get_stop(cub))
			;
		if (ft_mtx_get_stop(cub))
			kill(pid, SIGTERM);
	}
	if (check)
		pthread_mutex_unlock(&(cub->thread.mtx_protect));
}

static void	ft_check_shoot_sound(t_cub *cub)
{
	int		pid;
	int		check;

	check = 1;
	pthread_mutex_lock(&(cub->thread.mtx_protect));
	if ((cub->mlx.zome_shoot1 || cub->mlx.normal_shoot1) \
	&& cub->mlx.weapon_magazin_index < 9)
	{
		pthread_mutex_unlock(&(cub->thread.mtx_protect));
		check = 0;
		pid = fork();
		if (pid < 0)
			exit(1);
		if (pid == 0)
		{
			execlp("afplay", "afplay", SHOOT_SOUND_PATH, (char *) NULL);
			exit(1);
		}
		while (!waitpid(pid, NULL, WNOHANG) && !ft_mtx_get_stop(cub))
			;
		if (ft_mtx_get_stop(cub))
			kill(pid, SIGTERM);
	}
	if (check)
		pthread_mutex_unlock(&(cub->thread.mtx_protect));
}

void	*ft_routine2(void *args)
{
	t_cub	*cub;

	cub = (t_cub *)args;
	while (!ft_mtx_get_stop(cub))
	{
		ft_check_reaload_sound(cub);
		ft_check_shoot_sound(cub);
		usleep(1000);
	}
	return (NULL);
}
