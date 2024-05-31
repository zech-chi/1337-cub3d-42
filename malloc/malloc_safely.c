#include "../include/cub3d.h"

void	*allocate_memory_safely(size_t bytes)
{
	void	*ptr;

	ptr = malloc(bytes);
	if (!ptr)
	{
		ft_putstr_fd("Error: failed to allocate memory", 2, 1,RED);
		return (NULL);
	}
	return (ptr);
}
