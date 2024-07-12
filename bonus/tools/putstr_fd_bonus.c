/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_fd_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:26:02 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/12 09:31:50 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

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
