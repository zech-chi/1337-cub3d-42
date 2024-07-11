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

#include "../include/cub3d.h"

void	*ft_routine2(void *args)
{
	int		pid;
	t_cub	*cub;

	cub = (t_cub *)args;
	while (!ft_mtx_get_stop(cub))
	{
		if (cub->mlx.reload && cub->mlx.index_weapon == 20)
		{
			if (cub->player.is_walking)
				sleep(2);
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
		usleep(500);
	}
	return (NULL);
}