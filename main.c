/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:01:31 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/02 11:26:38 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

int	main(int ac, char **av)
{
	t_cub	cub;

	ft_parsing(ac, av, &cub);
	ft_display(&cub);
	ft_build_maze(&cub);
	// ft_display_list(cub.head);
	// printf("\n--------------------------------\n");
	// printf("rows:%d, colos:%d", cub.rows, cub.cols);
	return (0);
}

// int main()
// {
// 	mlx_t		*mlx_ptr;
// 	mlx_texture_t		*maze_texture;
// 	mlx_image_t		*maze_img;
// 	mlx_image_t		*copy;
// 	uint8_t	r;
// 	uint8_t	g;
// 	uint8_t	b;
// 	uint8_t	a;
// 	int	size;

// 	size = 1024;
//     mlx_ptr = mlx_init(size * 2, size, "hello", true);
// 	maze_texture = mlx_load_png("./textures/north.png");

// 	copy = mlx_new_image(mlx_ptr, size, size);
// 	for (int y = 0; y < size; y++)
// 	{
// 		for (int x = 0; x < size; x++)
// 			mlx_put_pixel(copy, x, y, ft_color(255, 0, 0, 255));
// 	}
// 	maze_img =  mlx_texture_to_image(mlx_ptr, maze_texture);
// 	for(int y = 0; y < size; y++)
// 	{
// 		for(int x = 0; x < size; x++)
// 		{
// 			int i = (y * size + x) * 4;
// 			r = maze_img->pixels[i];
// 			g = maze_img->pixels[i + 1];
// 			b = maze_img->pixels[i + 2];
// 			a = maze_img->pixels[i + 3];
// 			mlx_put_pixel(copy, x, y, ft_color(r, g, b, a));
// 		}
// 	}
// 	mlx_image_to_window(mlx_ptr, maze_img, 0, 0);
// 	mlx_image_to_window(mlx_ptr, copy, size, 0);
// 	mlx_loop(mlx_ptr);
// 	return (0);
// }
