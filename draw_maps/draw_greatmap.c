#include "../include/cub3d.h"

void ft_putpixel_greatmap(t_cub *cub, int r, int c, uint32_t color)
{
	for (int i = r; i < r + cub->pixel * 2; i++)
	{
		for (int j = c; j < c + cub->pixel * 2; j++)
		{
			mlx_put_pixel(cub->mlx.great_mini_map, j, i, color);
		}
	}
}

int	ft_isgreatwall(t_cub *cub, int x, int y, double alpha)
{
	int	r;
	int	c;
	int	pr;
	int	pc;

	r = y / cub->pixel;
	c = x / cub->pixel;
	pr = cub->player.r / cub->pixel;
	pc = cub->player.c / cub->pixel;
	if (r < 0 || c < 0 || r > cub->rows || c > cub->cols || cub->map[r][c] == '1' || cub->map[r][c] == ' ')
		return (1);
	if ((ft_between(alpha, 0, M_PI / 2) || ft_between(alpha, 2 * M_PI, 2 * M_PI + M_PI / 2))  && cub->map[r + 1][c] == '1' && cub->map[r][c - 1] == '1' && r != pr && c != pc)
		return (1);
	if ((ft_between(alpha, 3 * M_PI / 2, 2 * M_PI) || ft_between(alpha, -M_PI / 2, 0))  && cub->map[r - 1][c] == '1' && cub->map[r][c - 1] == '1' && r != pr && c != pc)
		return (1);
	if (ft_between(alpha, M_PI, 3 * M_PI / 2)  && cub->map[r - 1][c] == '1' && cub->map[r][c + 1] == '1' && r != pr && c != pc)
		return (1);
	if (ft_between(alpha, M_PI / 2, M_PI) && cub->map[r + 1][c] == '1' && cub->map[r][c + 1] == '1' && r != pr && c != pc)
		return (1);
	return (0);
}


void	ft_draw_great_ray(t_cub *cub, double alpha)
{
	int		distance;
	double	a;
	double	b;
	int		y;
	int		x;

	distance = 0;
	while (1)
	{
		a = distance * cos(alpha);
		b = distance * sin(-alpha);
		x = cub->player.c * 2  + a;
		y = cub->player.r * 2 + b;
		if (ft_isgreatwall(cub, x / 2 , y / 2, alpha))
			break;
		else
		{

			mlx_put_pixel(cub->mlx.great_mini_map, x, y, ft_pixel(255, 255, 0, 255));
			// mlx_put_pixel(cub->mlx.great_mini_map, x, y, ft_pixel(255, 0, 0, 255 * exp(-0.008 * distance)));
		}
		distance++;
	}
}

void	ft_draw_great_rays(t_cub *cub,double start_angle,double end_angle)
{
	while (start_angle <= end_angle)
	{
		ft_draw_great_ray(cub, start_angle);
		start_angle +=  0.001;
	}
}

void	ft_draw_great_player(t_cub *cub)
{
	int	x;
	int	y;
	double	start_angle;
	double	end_angle;

	start_angle = cub->player.rot_angle - M_PI / 6;
	end_angle = cub->player.rot_angle + M_PI / 6;
	ft_draw_great_rays(cub, start_angle, end_angle);
	y = cub->player.r * 2 - cub->player.radius;
	while (y < cub->player.r * 2 + cub->player.radius * 2)
	{
		x = cub->player.c * 2 - cub->player.radius * 2;
		while (x < cub->player.c * 2 + cub->player.radius * 2)
		{
			if (pow(x - cub->player.c * 2, 2) + pow(y - cub->player.r * 2, 2) < pow(cub->player.radius, 2))
				mlx_put_pixel(cub->mlx.great_mini_map, x, y, cub->player.player_color);
			x++;
		}
		y++;
	}
}

void	ft_rendre_great_map(t_cub *cub)
{
	for (int r = 0; r < cub->rows; r++)
	{
		for (int c = 0; c < cub->cols; c++)
		{
			if (cub->map[r][c] == ' ')
				ft_putpixel_greatmap(cub, cub->pixel * r * 2, cub->pixel * c * 2, ft_pixel(0, 0, 0, 255));
			else if (cub->map[r][c] == '1')
				ft_putpixel_greatmap(cub, cub->pixel * r * 2, cub->pixel * c * 2, ft_pixel(254,163,3,255));
			else if (cub->map[r][c] == '0')
				ft_putpixel_greatmap(cub, cub->pixel * r * 2, cub->pixel * c * 2, ft_pixel(52, 25, 72,255));
		}
	}
	ft_draw_great_player(cub);
}