/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:02:04 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/31 18:23:35 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_scan_map(t_cub *cub, char *path)
{
	int fd;
	char	*line;

	fd = ft_open_file(path);

	
	close(fd);
	return (NULL);
}
