/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:01:31 by zech-chi          #+#    #+#             */
/*   Updated: 2024/06/06 17:20:52 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_putpixel(t_cub *cub, int r, int c, uint32_t color)
{
    // mlx_image_t* image = mlx_new_image(cub->mlx.mlx_ptr, cub->cols * 50, cub->rows * 50);
    // if (!image)
    // {
    //     puts(mlx_strerror(mlx_errno));
    //     return;
    // }

    for (int i = r; i < r + cub->pixel; i++)
    {
        for (int j = c; j < c + cub->pixel; j++)
        {
            mlx_put_pixel(cub->mlx.image, j, i, color);
        }
    }
    // Free the image if you don't need it anymore, to avoid memory leaks
    // mlx_delete_image(cub->mlx.mlx_ptr, image);  // Uncomment if necessary
}

void ft_hook(void* param)
{
	t_cub *cub = param;

	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_ESCAPE))
		mlx_close_window(cub->mlx.mlx_ptr);
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_UP))
		cub->mlx.image->instances[0].y -= 5;
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_DOWN))
		cub->mlx.image->instances[0].y += 5;
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_LEFT))
		cub->mlx.image->instances[0].x -= 5;
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_RIGHT))
		cub->mlx.image->instances[0].x += 5;
}

void	ft_build_map(t_cub *cub)
{
	if (!(cub->mlx.mlx_ptr = mlx_init(cub->pixel * cub->cols, cub->pixel * cub->rows, "ziko^2", false)))
	{
		puts(mlx_strerror(mlx_errno));
		return ;
	}
	cub->mlx.image = mlx_new_image(cub->mlx.mlx_ptr, cub->cols * cub->pixel, cub->rows * cub->pixel);
    if (!cub->mlx.image)
    {
        puts(mlx_strerror(mlx_errno));
        return;
    }
	cub->mlx.no = mlx_load_png("chinese-wall.png");

    if (!cub->mlx.no)
    {
        puts(mlx_strerror(mlx_errno));
        return;
    }
	for (int r = 0; r < cub->rows; r++)
	{
		for (int c = 0; c < cub->cols; c++)
		{
			if (cub->map[r][c] == ' ')
				ft_putpixel(cub, cub->pixel * r, cub->pixel * c, ft_pixel(233, 89,10,255));
			else if (cub->map[r][c] == '1')
				ft_putpixel(cub, cub->pixel * r, cub->pixel * c, ft_pixel(0,255,0,255));
			else if (cub->map[r][c] == '0')
				ft_putpixel(cub, cub->pixel * r, cub->pixel * c, ft_pixel(0,0,0,255));
		}
	}
	ft_putpixel(cub, cub->player.r - cub->pixel * 0.5, cub->player.c - cub->pixel * 0.5, ft_pixel(0,0,0,255));
	ft_draw_ray(cub, M_PI / 6);
	ft_draw_player(cub);
	mlx_image_to_window(cub->mlx.mlx_ptr, cub->mlx.image, 0, 0);
	mlx_loop_hook(cub->mlx.mlx_ptr, ft_hook, cub);
	mlx_loop(cub->mlx.mlx_ptr);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	ft_parsing(ac, av, &cub);
	ft_display(&cub);
	ft_build_map(&cub);

    // ft_loadimg(cub);
	// ft_display_list(cub.head);
	// printf("\n--------------------------------\n");
	// printf("rows:%d, colos:%d", cub.rows, cub.cols);
	return (0);
}
