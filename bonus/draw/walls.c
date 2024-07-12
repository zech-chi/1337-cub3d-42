/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:07:51 by zelabbas          #+#    #+#             */
/*   Updated: 2024/07/12 09:13:44 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	ft_play_starting(t_cub *cub)
{
	static int		time;

	if (time == 75 || time == 125 || time == 175 || time == 225)
		mlx_delete_image(cub->mlx.mlx_ptr, cub->mlx.background_start);
	if (time > 225)
		return (false);
	else if (time == 75)
		cub->mlx.background_start = ft_get_image(cub, PATH_GAME_START_1);
	else if (time == 125)
		cub->mlx.background_start = ft_get_image(cub, PATH_GAME_START_2);
	else if (time == 175)
		cub->mlx.background_start = ft_get_image(cub, PATH_GAME_START_3);
	else if (time == 225)
		ft_mlx_image_to_window(cub, cub->mlx.weapon_magazin, \
		WEAPON_MAGAZIN_X, WEAPON_MAGAZIN_Y);
	if (time == 75 || time == 125 || time == 175)
		ft_mlx_image_to_window(cub, cub->mlx.background_start, 0, 0);
	time++;
	return (true);
}

void	ft_close_win_event(t_cub *cub)
{
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_ESCAPE))
		mlx_close_window(cub->mlx.mlx_ptr);
}

void	ft_render(void *param)
{
	t_cub		*cub;

	cub = param;
	if (ft_play_starting(cub))
		return ;
	ft_play_weapon_frame(cub);
	pthread_mutex_lock(&(cub->thread.mtx_protect));
	if (cub->mlx.reload || cub->mlx.zome_shoot1 || cub->mlx.normal_shoot1)
	{
		pthread_mutex_unlock(&(cub->thread.mtx_protect));
		return ;
	}
	pthread_mutex_unlock(&(cub->thread.mtx_protect));
	ft_weapon_event(cub);
	ft_close_win_event(cub);
	ft_player_event(cub);
	ft_light_event(cub);
	if (cub->render)
	{
		ft_rays(cub);
		ft_render_walls(cub);
		ft_render_minimap(cub);
	}
	cub->render = false;
	cub->player.is_walking = false;
}

void	ft_build_maze(t_cub *cub)
{
	ft_mlx_init(cub);
	ft_load_img(cub);
	ft_mlx_image_to_window(cub, cub->mlx.black, 0, 0);
	ft_mlx_image_to_window(cub, cub->mlx.sky, 0, 0);
	ft_mlx_image_to_window(cub, cub->mlx.canva, 0, 0);
	ft_mlx_image_to_window(cub, cub->mlx.maze_img, 0, 0);
	ft_mlx_image_to_window(cub, cub->mlx.minimap, POS_MINIMAP, POS_MINIMAP);
	ft_mlx_image_to_window(cub, cub->mlx.player_rays, POS_MINIMAP, POS_MINIMAP);
	ft_mlx_image_to_window(cub, cub->mlx.circle, POS_MINIMAP - 16,
		POS_MINIMAP - 16);
	ft_mlx_image_to_window(cub, cub->mlx.target, WINDOW_WIDTH / 2 - 20,
		WINDOW_HEIGHT / 2 - 8);
	ft_mlx_image_to_window(cub, cub->mlx.background_start, 0, 0);
	mlx_loop_hook(cub->mlx.mlx_ptr, ft_render, cub);
	mlx_mouse_hook(cub->mlx.mlx_ptr, mouse_hook, cub);
	mlx_cursor_hook(cub->mlx.mlx_ptr, mouse_func, cub);
	mlx_loop(cub->mlx.mlx_ptr);
}
