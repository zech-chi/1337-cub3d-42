/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:01:31 by zech-chi          #+#    #+#             */
/*   Updated: 2024/06/01 21:08:03 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"
void leak(){system("leaks cub3D");}
int	main(int ac, char **av)
{
	atexit(leak);
	t_cub	cub;

	ft_parsing(ac, av, &cub);
	ft_display(&cub);
	ft_display_list(cub.head);
	printf("\n--------------------------------\n");
	printf("rows:%d, colos:%d", cub.rows, cub.cols);
	ft_free_data(&cub);
	return (0);
}