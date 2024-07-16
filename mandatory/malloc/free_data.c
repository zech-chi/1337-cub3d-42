/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:57:57 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/11 17:35:29 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_free_matirx(char **matrix)
{
	int	i;

	if (!matrix)
		return ;
	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}

void	ft_free_list(t_list **head)
{
	t_list	*ptr;

	if (!head)
		return ;
	while (*head)
	{
		ptr = (*head);
		(*head) = (*head)->next;
		free(ptr->content);
		free(ptr);
	}
}

void	ft_free_mlx(t_cub *cub)
{
	if (!cub->mlx.mlx_ptr)
		return ;
	mlx_delete_image(cub->mlx.mlx_ptr, cub->mlx.maze_img);
	mlx_delete_image(cub->mlx.mlx_ptr, cub->mlx.no_img);
	mlx_delete_image(cub->mlx.mlx_ptr, cub->mlx.so_img);
	mlx_delete_image(cub->mlx.mlx_ptr, cub->mlx.we_img);
	mlx_delete_image(cub->mlx.mlx_ptr, cub->mlx.ea_img);
	mlx_terminate(cub->mlx.mlx_ptr);
}

void	ft_free_data(t_cub *cub)
{
	free(cub->no);
	free(cub->so);
	free(cub->we);
	free(cub->ea);
	free(cub->cf);
	free(cub->cc);
	free(cub->line);
	ft_free_matirx(cub->map);
	ft_free_list(&(cub->head));
	ft_free_mlx(cub);
	if (cub->fd != -1)
		close(cub->fd);
}
