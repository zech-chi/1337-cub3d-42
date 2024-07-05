/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:01:31 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/04 21:13:31 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"


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
