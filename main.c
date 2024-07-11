/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:01:31 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/11 00:50:09 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"


int	main(int ac, char **av)
{
	t_cub		cub;

	ft_parsing(ac, av, &cub);
	ft_mtx_init(&cub);
	// pthread_create(&cub.thread.id_background_music, NULL, ft_routine, &cub);
	pthread_create(&cub.thread.id_sound, NULL, ft_routine2, &cub);
	pthread_detach(cub.thread.id_sound);
	ft_build_maze(&cub);
	ft_mtx_set_stop(&cub);
	ft_free_data(&cub);
	// pthread_join(cub.thread.id_background_music, NULL);
	return (0);
}
