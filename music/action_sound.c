/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_sound.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:57:25 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/08 21:04:09 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// void	*ft_routine2(void *args)
// {
// 	int	pid;
// 	t_cub	*cub;

// 	cub = (t_cub *)args;
// 	// while (!ft_mtx_get_stop(cub))
// 	// {
// 		printf("I was here\n");
// 		pid = fork();
// 		if (pid < 0)
// 		{
// 			printf("fork failed\n");
// 			exit(1);
// 		}
// 		else if (pid == 0)
// 		{
// 			printf("check reload\n");
// 			// if (cub->mlx.reload) // data race
// 			// {
// 				printf("playing sound\n");
// 				execlp("afplay", "afplay", RELOAD_SOUND_PATH, (char *)NULL);
// 			// }
// 			printf("oops\n");
// 			// exit(1);
// 		}
// 		while (!waitpid(pid, 0, WNOHANG) && !ft_mtx_get_stop(cub));
// 	// }
// 	kill(pid, SIGTERM);
// 	return (NULL);
// }

void *ft_routine2(void *args)
{
	pid_t	pid;
	t_cub	*cub;

	cub = (t_cub *)args;
	printf("I was here\n");
	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		exit(1);
	}
	else if (pid == 0)
	{
		printf("check reload\n");
		// if (cub->reload)
		// {
			printf("playing sound\n");
			if (execlp("afplay", "afplay", RELOAD_SOUND_PATH, (char *)NULL) == -1)
			{
				perror("execlp failed");
				exit(1);
			}
		// }
		printf("oops\n");
		exit(0);
	}
	printf("parent job\n");
	while (!waitpid(pid, NULL, WNOHANG) && !ft_mtx_get_stop(cub));
	if (ft_mtx_get_stop(cub))
		kill(pid, SIGTERM);
	return (NULL);
}

void	ft_play_action_sound(t_cub *cub)
{
	// pthread_create(&cub->thread.id_sound, NULL, ft_routine2, &cub);
	// pthread_detach(cub->thread.id_sound);
		pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		exit(1);
	}
	else if (pid == 0)
	{
		printf("playing sound\n");
		if (execlp("afplay", "afplay", RELOAD_SOUND_PATH, (char *)NULL) == -1)
		{
			perror("execlp failed");
			exit(1);
		}
		printf("oops\n");
		exit(0);
	}
	printf("parent job\n");
	(void)cub;
	// while (!waitpid(pid, NULL, WNOHANG) && !ft_mtx_get_stop(cub));
	// if (ft_mtx_get_stop(cub))
	// 	kill(pid, SIGTERM);
}

