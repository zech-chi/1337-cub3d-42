/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:57:57 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/12 09:28:38 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

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
	mlx_delete_image(cub->mlx.mlx_ptr, cub->mlx.canva);
	mlx_delete_image(cub->mlx.mlx_ptr, cub->mlx.no_img);
	mlx_delete_image(cub->mlx.mlx_ptr, cub->mlx.so_img);
	mlx_delete_image(cub->mlx.mlx_ptr, cub->mlx.we_img);
	mlx_delete_image(cub->mlx.mlx_ptr, cub->mlx.ea_img);
	mlx_delete_image(cub->mlx.mlx_ptr, cub->mlx.minimap);
	mlx_delete_image(cub->mlx.mlx_ptr, cub->mlx.player_rays);
	mlx_delete_image(cub->mlx.mlx_ptr, cub->mlx.black);
	mlx_delete_image(cub->mlx.mlx_ptr, cub->mlx.background_start);
	mlx_delete_image(cub->mlx.mlx_ptr, cub->mlx.door);
	mlx_delete_image(cub->mlx.mlx_ptr, cub->mlx.weapon_magazin);
	mlx_delete_image(cub->mlx.mlx_ptr, cub->mlx.circle);
	mlx_delete_image(cub->mlx.mlx_ptr, cub->mlx.target);
	mlx_delete_image(cub->mlx.mlx_ptr, cub->mlx.sky);
	mlx_delete_image(cub->mlx.mlx_ptr, cub->mlx.shoot_target);
	mlx_terminate(cub->mlx.mlx_ptr);
}

void	ft_destroy_mtx(t_cub *cub)
{
	if (cub->thread.mtx_count == 1)
		pthread_mutex_destroy(&cub->thread.mtx_stop);
	else if (cub->thread.mtx_count == 2)
	{
		pthread_mutex_destroy(&cub->thread.mtx_stop);
		pthread_mutex_destroy(&cub->thread.mtx_protect);
	}
}

void	ft_free_data(t_cub *cub)
{
	ft_mtx_set_stop(cub);
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
	ft_destroy_mtx(cub);
}
