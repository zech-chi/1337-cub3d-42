/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:01:31 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/31 12:18:42 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

//void	ft_init_data(t_cub *data)
//{
//	(void) data;
//	return ;
//}


int	main(int ac, char **av)
{
	//t_cub	data;

	if (ac != 2)
	{
		printf("Error Usage: ./cub3d path_to_map");
		return(1);
	}
	//ft_init_data(&data);
	(void)av;
	return (0);
}