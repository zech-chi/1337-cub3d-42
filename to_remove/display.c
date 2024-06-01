/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 12:08:24 by zech-chi          #+#    #+#             */
/*   Updated: 2024/06/01 12:31:00 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    ft_display(t_cub *cub)
{
	printf("NO = \"%s\"\n", cub->no);
	printf("SO = \"%s\"\n", cub->so);
	printf("WE = \"%s\"\n", cub->we);
	printf("EA = \"%s\"\n", cub->ea);
	if (cub->cf)
		printf("F [%d, %d, %d]\n", cub->cf[0], cub->cf[1], cub->cf[2]);
	else
		printf("F is empty\n");
	if (cub->cc)
		printf("C [%d, %d, %d]\n", cub->cc[0], cub->cc[1], cub->cc[2]);
	else
		printf("C is empty\n");
}