/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:01:31 by zech-chi          #+#    #+#             */
/*   Updated: 2024/06/30 22:19:42 by zelabbas         ###   ########.fr       */
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
//     // void    *win_ptr;
//     // void    *img_ptr;
//     // int     img_width;
//     // int     img_height;

//     // Initialize MLX
//     mlx_ptr = mlx_init(256 * 2, 256, "hello", true);
// 	maze_texture = mlx_load_png("./lightile17.png");
//     // Create a new window
//     // win_ptr = mlx_new_window(mlx_ptr, 800, 600, "My Window");
//     // if (win_ptr == NULL)
//     //     return (1);

//     // // Load the image
//     // img_ptr = mlx_xpm_file_to_image(mlx_ptr, "path/to/your/image.xpm", &img_width, &img_height);
//     // if (img_ptr == NULL)
//     //     return (1);

//     // // Display the image in the window
// 	copy = mlx_new_image(mlx_ptr, 256, 256);
// 	for (int y = 0; y < 256; y++)
// 	{
// 		for (int x = 0; x < 256; x++)
// 			mlx_put_pixel(copy, x, y, ft_color(255, 0, 0, 255));
// 	}
// 	maze_img =  mlx_texture_to_image(mlx_ptr, maze_texture);
// 	for(int y = 0; y < 256; y++)
// 	{
// 		for(int x = 0; x < 256; x++)
// 		{
// 			int i = (y * 256 + x) * 4;
// 			r = maze_img->pixels[i];
// 			g = maze_img->pixels[i + 1];
// 			b = maze_img->pixels[i + 2];
// 			a = maze_img->pixels[i + 3];
// 			mlx_put_pixel(copy, x, y, ft_color(r, g, b, a));
// 		}
// 	}
// 	mlx_image_to_window(mlx_ptr, maze_img, 0, 0);
// 	mlx_image_to_window(mlx_ptr, copy, 256, 0);
// 	mlx_loop(mlx_ptr);
// 	return (0);
// }
