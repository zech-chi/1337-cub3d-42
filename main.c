/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:01:31 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/03 14:21:13 by zech-chi         ###   ########.fr       */
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
	// ft_mtx_init(&cub);
	// pthread_create(&cub.thread.id_background_music, NULL, ft_routine, &cub);
	ft_build_maze(&cub);
	// ft_mtx_set_stop(&cub);
	// pthread_join(cub.thread.id_background_music, NULL);
	return (0);
}

// // Mouse hook function
// void mouse_hook(mouse_key_t button, action_t action, modifier_key_t mods, void *param)
// {
//     (void)param;
// 	t_cub *cub = param;
//     (void)mods;
// 	int x;
// 	int	y;
//     if (action == MLX_PRESS)
//     {
//         if (button == MLX_MOUSE_BUTTON_LEFT)
//         {
//             printf("Left mouse button pressed\n");
// 			mlx_get_mouse_pos(cub->mlx.mlx_ptr, &x, &y);
// 			printf("%d, %d\n", x, y);
//         }
//         else if (button == MLX_MOUSE_BUTTON_RIGHT)
//         {
//             printf("Right mouse button pressed\n");
// 			mlx_get_mouse_pos(cub->mlx.mlx_ptr, &x, &y);
// 			printf("%d, %d\n", x, y);
//         }
//         else if (button == MLX_MOUSE_BUTTON_MIDDLE)
//         {
//             printf("Middle mouse button pressed\n");
// 			mlx_get_mouse_pos(cub->mlx.mlx_ptr, &x, &y);
// 			printf("%d, %d\n", x, y);
//         }
//         // else if (button == MLX_MOUSE_BUTTON_SCROLL_UP)
//         // {
//         //     printf("Scroll up\n");
//         // }
//         // else if (button == MLX_MOUSE_BUTTON_SCROLL_DOWN)
//         // {
//         //     printf("Scroll down\n");
//         // }
//     }
// }

// int main()
// {
//     t_cub cub;

//     cub.mlx.mlx_ptr = mlx_init(800, 600, "test_Mouse", false);
//     if (!cub.mlx.mlx_ptr)
//     {
//         fprintf(stderr, "Error initializing mlx\n");
//         return (1);
//     }

//     mlx_mouse_hook(cub.mlx.mlx_ptr, mouse_hook, &cub);

// 	mlx_set_cursor_mode(cub.mlx.mlx_ptr, MLX_MOUSE_NORMAL);
//     mlx_loop(cub.mlx.mlx_ptr);

//     return (0);
// }

