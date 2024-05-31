#include "../include/cub3d.h"

void	ft_free_matirx(char **matrix)
{
	int i;

	if (!matrix)
		return ;
	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}

void	ft_free_data(t_cub *cub)
{
	free(cub->no);
	free(cub->so);
	free(cub->we);
	free(cub->ea);
	free(cub->cf);
	free(cub->cc);
	ft_free_matirx(cub->map);
}