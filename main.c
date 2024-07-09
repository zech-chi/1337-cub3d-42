/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:01:31 by zech-chi          #+#    #+#             */
/*   Updated: 2024/07/09 16:52:45 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"


int	main(int ac, char **av)
{
	t_cub		cub;

	ft_parsing(ac, av, &cub);
	ft_mtx_init(&cub);
	// pthread_create(&cub.thread.id_background_music, NULL, ft_routine, &cub);
	ft_build_maze(&cub);
	ft_mtx_set_stop(&cub);
	// pthread_join(cub.thread.id_background_music, NULL);
	return (0);
}


// #define WIDTH 1300
// #define HEIGHT 1300
// #define IMG_WIDTH 1024
// #define IMG_HEIGHT 1024

// uint32_t ft_clr(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

// int main() {
//     mlx_t *ptrmlx = mlx_init(WIDTH, HEIGHT, "rotate", false);
//     mlx_texture_t *texture = mlx_load_png("door.png");
//     mlx_image_t *img = mlx_texture_to_image(ptrmlx, texture);
//     mlx_image_t *rot_img = mlx_new_image(ptrmlx, IMG_WIDTH, IMG_HEIGHT);
//     int i, r, g, b, a;
//     int sx, sy;
//     float rad_angle = M_PI / 4.0;
//     float cos_angle = cos(rad_angle);
//     float sin_angle = sin(rad_angle);

//     for (int y = 0; y < IMG_HEIGHT; y++) {
//         for (int x = 0; x < IMG_WIDTH; x++) {
//             // Calculate the source coordinates using inverse mapping
//             sx = (int)(cos_angle * (x - IMG_WIDTH / 2) + sin_angle * (y - IMG_HEIGHT / 2) + IMG_WIDTH / 2);
//             sy = (int)(-sin_angle * (x - IMG_WIDTH / 2) + cos_angle * (y - IMG_HEIGHT / 2) + IMG_HEIGHT / 2);

//             // Check if the source coordinates are within bounds
//             if (sx >= 0 && sy >= 0 && sx < IMG_WIDTH && sy < IMG_HEIGHT) {
//                 i = (sy * IMG_WIDTH + sx) * 4;
//                 r = img->pixels[i];
//                 g = img->pixels[i + 1];
//                 b = img->pixels[i + 2];
//                 a = img->pixels[i + 3];
//                 mlx_put_pixel(rot_img, x, y, ft_clr(r, g, b, a));
//             } else {
//                 // Set the pixel to a default value (e.g., black) if out of bounds
//                 mlx_put_pixel(rot_img, x, y, ft_clr(0, 0, 0, 255));
//             }
//         }
//     }

//     mlx_image_to_window(ptrmlx, rot_img, 100, 100);
//     mlx_loop(ptrmlx);
// }

// void	ft_copy_img1(mlx_image_t	*from, mlx_image_t *to)
// {
// 	int	x;
// 	int	y;
// 	int	i;

// 	y = -1;
// 	while (++y < (int)from->height)
// 	{
// 		x = -1;
// 		while (++x < (int)from->width)
// 		{
// 			i = (y * from->height + x) * 4;
// 			to->pixels[i] = from->pixels[i];
// 			to->pixels[i + 1] = from->pixels[i + 1];
// 			to->pixels[i + 2] = from->pixels[i + 2];
// 			to->pixels[i + 3] = from->pixels[i + 3];
// 		}
// 	}
// }

// void	ft_rotate_img(mlx_image_t *from, mlx_image_t *to, float angle)
// {
// 	int	x;
// 	int	y;
// 	int	sx, sy;
// 	int i;
// 	int r, g, b, a;
// 	float cos_angle = cos(angle);
// 	float sin_angle = sin(angle);

// 	y = -1;
// 	while (++y < (int)to->height) {
// 		x = -1;
// 		while (++x < (int)to->width) {
// 			sx = (int)(cos_angle * (x - (int)to->width / 2) + sin_angle * (y - (int)to->height / 2) + (int)to->width / 2);
// 			sy = (int)(-sin_angle * (x - (int)to->width / 2) + cos_angle * (y - (int)to->height / 2) + (int)to->height / 2);
// 			if (sx >= 0 && sy >= 0 && sx < (int)to->width && sy < (int)to->height) {
// 				i = (sy * (int)to->width + sx) * 4;
// 				r = from->pixels[i];
// 				g = from->pixels[i + 1];
// 				b = from->pixels[i + 2];
// 				a = from->pixels[i + 3];
// 				mlx_put_pixel(to, x, y, ft_clr(r, g, b, a));
// 			} else {
// 				mlx_put_pixel(to, x, y, ft_clr(0, 0, 0, 255));
// 			}
// 		}
// 	}
// }


// int main() {
//     mlx_t *ptrmlx = mlx_init(WIDTH, HEIGHT, "rotate", false);
//     mlx_texture_t *texture = mlx_load_png("door.png");
//     mlx_image_t *img = mlx_texture_to_image(ptrmlx, texture);
//     mlx_image_t *rot_img = mlx_new_image(ptrmlx, IMG_WIDTH, IMG_HEIGHT);
//     // int i, r, g, b, a;
//     // int sx, sy;
//     // float rad_angle = M_PI / 4.0;
//     // float cos_angle = cos(rad_angle);
//     // float sin_angle = sin(rad_angle);


// 	ft_copy_img1(img, rot_img);
// 	ft_copy_img1(rot_img, img);
//     // for (int y = 0; y < IMG_HEIGHT; y++) {
//     //     for (int x = 0; x < IMG_WIDTH; x++) {
//     //         // Calculate the source coordinates using inverse mapping
//     //         sx = (int)(cos_angle * (x - IMG_WIDTH / 2) + sin_angle * (y - IMG_HEIGHT / 2) + IMG_WIDTH / 2);
//     //         sy = (int)(-sin_angle * (x - IMG_WIDTH / 2) + cos_angle * (y - IMG_HEIGHT / 2) + IMG_HEIGHT / 2);

//     //         // Check if the source coordinates are within bounds
//     //         if (sx >= 0 && sy >= 0 && sx < IMG_WIDTH && sy < IMG_HEIGHT) {
//     //             i = (sy * IMG_WIDTH + sx) * 4;
//     //             r = img->pixels[i];
//     //             g = img->pixels[i + 1];
//     //             b = img->pixels[i + 2];
//     //             a = img->pixels[i + 3];
//     //             mlx_put_pixel(rot_img, x, y, ft_clr(r, g, b, a));
//     //         } else {
//     //             // Set the pixel to a default value (e.g., black) if out of bounds
//     //             mlx_put_pixel(rot_img, x, y, ft_clr(0, 0, 0, 255));
//     //         }
//     //     }
//     // }

//     mlx_image_to_window(ptrmlx, img, 100, 100);
//     mlx_loop(ptrmlx);
// }
