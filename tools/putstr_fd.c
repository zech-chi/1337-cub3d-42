/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:26:02 by zech-chi          #+#    #+#             */
/*   Updated: 2024/06/02 15:03:18 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_putstr_fd(char *str, int fd, int endl, char *color)
{
	if (!str)
		return ;
	write(fd, color, ft_strlen(color));
	write(fd, str, ft_strlen(str));
	if (endl)
		write(fd, "\n", 1);
	write(fd, RESET, ft_strlen(RESET));
}
