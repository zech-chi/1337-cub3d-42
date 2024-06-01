/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:02:04 by zech-chi          #+#    #+#             */
/*   Updated: 2024/05/31 18:45:59 by zelabbas         ###   ########.fr       */
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
