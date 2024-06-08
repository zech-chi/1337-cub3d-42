/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:01:31 by zech-chi          #+#    #+#             */
/*   Updated: 2024/06/08 12:38:36 by zelabbas         ###   ########.fr       */
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


void	ft_render_mini_map(t_cub *cub)
{
	for (int r = 0; r < cub->rows; r++)
	{
		for (int c = 0; c < cub->cols; c++)
		{
			if (cub->map[r][c] == ' ')
				ft_putpixel(cub, cub->pixel * r, cub->pixel * c, ft_pixel(0, 0, 0,255));
			else if (cub->map[r][c] == '1')
				ft_putpixel(cub, cub->pixel * r, cub->pixel * c, ft_pixel(255, 255, 255,255));
				//ft_putpixel(cub, cub->pixel * r, cub->pixel * c, ft_pixel(52, 25, 72,255));
			else if (cub->map[r][c] == '0')
				ft_putpixel(cub, cub->pixel * r, cub->pixel * c, ft_pixel(0,0,0,255));
				// ft_putpixel(cub, cub->pixel * r, cub->pixel * c, ft_pixel(254,163,3,255));
		}
	}
	ft_draw_player(cub);
}

int	ft_iswall2(t_cub *cub, int x, int y, double alpha)
{
	int	r;
	int	c;
	int	pr;
	int	pc;

	r = y / cub->pixel;
	c = x / cub->pixel;
	pr = cub->player.r / cub->pixel;
	pc = cub->player.c / cub->pixel;
	if (r == pr && c == pc)
		return (0);
	if (r < 0 || c < 0 || r > cub->rows || c > cub->cols || cub->map[r][c] == '1' || cub->map[r][c] == ' ')
		return (1);
	if (ft_between(alpha, 0, M_PI / 2) && cub->map[r + 1][c] == '1' && cub->map[r][c - 1] == '1')
		return (1);
	if (ft_between(alpha, 3 * M_PI / 2, 2 * M_PI) && cub->map[r - 1][c] == '1' && cub->map[r][c - 1] == '1')
		return (1);
	if (ft_between(alpha, M_PI, 3 * M_PI / 2) && cub->map[r - 1][c] == '1' && cub->map[r][c + 1] == '1')
		return (1);
	if (ft_between(alpha, M_PI / 2, M_PI) && cub->map[r + 1][c] == '1' && cub->map[r][c + 1] == '1')
		return (1);
	(void)alpha;
	return (0);
}

void ft_hook(void* param)
{
	t_cub *cub;
	int		a;
	int		b;
	int y = 0;
	int x = 0;

	cub = param;
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_ESCAPE))
		mlx_close_window(cub->mlx.mlx_ptr);
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_UP) || mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_W)) 
	{
		a = cub->player.move_speed * cos(cub->player.rot_angle);
		b = -1 * cub->player.move_speed * sin(cub->player.rot_angle);
		if (!ft_iswall2(cub, cub->player.c + 2 * a, cub->player.r + 2 * b, cub->player.rot_angle))
		{
			cub->player.r += b;
			cub->player.c += a;
		}
	}
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_DOWN) || mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_S))
	{
		a = -1 * cub->player.move_speed * cos(cub->player.rot_angle);
		b = cub->player.move_speed * sin(cub->player.rot_angle);
		if (
			(
				ft_between(cub->player.rot_angle, 0, M_PI / 2) && \
				!ft_iswall2(cub, cub->player.c + 2 * a, cub->player.r + 2 * b, cub->player.rot_angle + M_PI)
			) || (
				ft_between(cub->player.rot_angle, M_PI, 3 * M_PI / 2) && \
				!ft_iswall2(cub, cub->player.c + 2 * a, cub->player.r + 2 * b, cub->player.rot_angle - M_PI)
			) || (
				ft_between(cub->player.rot_angle, M_PI / 2, M_PI) && \
				!ft_iswall2(cub, cub->player.c + 2 * a, cub->player.r + 2 * b, cub->player.rot_angle + M_PI)
			) || (
				ft_between(cub->player.rot_angle, 3 * M_PI / 2, 2 * M_PI) && \
				!ft_iswall2(cub, cub->player.c + 2 * a, cub->player.r + 2 * b, cub->player.rot_angle - M_PI)
			)
		)
		{
			cub->player.r += b;
			cub->player.c += a;
		}
	}
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_LEFT) || mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_A))
	{
		cub->player.rot_angle += cub->player.rot_speed;
		if (cub->player.rot_angle >= 2 * M_PI)
			cub->player.rot_angle -= 2 * M_PI;
	}
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_RIGHT) || mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_D))
	{
		cub->player.rot_angle -= cub->player.rot_speed;
		if (cub->player.rot_angle < 0)
			cub->player.rot_angle += 2 * M_PI;
	}
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_I))
	{
    	y = cub->mlx.image->instances[0].y - 5;
    	if (y >= 0)
        	cub->mlx.image->instances[0].y = y;
	}
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_K))
	{
		y = cub->mlx.image->instances[0].y + 5;
		if (y + cub->rows * cub->pixel <= cub->rows * cub->pixel * 5) {
			cub->mlx.image->instances[0].y = y;
    	}
	}
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_J))
	{
		x = cub->mlx.image->instances[0].x - 5;
		if (x >= 0)
        	cub->mlx.image->instances[0].x = x;
	}
	if (mlx_is_key_down(cub->mlx.mlx_ptr, MLX_KEY_L))
	{
		x = cub->mlx.image->instances[0].x + 5;
		if (x + cub->cols * cub->pixel <= cub->cols * cub->pixel * 5)
			cub->mlx.image->instances[0].x = x;
	}
	ft_render_mini_map(cub);
}

void	ft_build_map(t_cub *cub)
{
	if (!(cub->mlx.mlx_ptr = mlx_init(cub->pixel * cub->cols * 5, cub->pixel * cub->rows * 5, "ziko^2", false)))
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
	ft_putpixel(cub, cub->player.r - cub->pixel * 0.5, cub->player.c - cub->pixel * 0.5, ft_pixel(0,0,0,255));
	// ft_draw_ray(cub, 3 * M_PI / 2)
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
