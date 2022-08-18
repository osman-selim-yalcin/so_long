
#include "so_long.h"

void	finish(t_data *data)
{
	printf("You Win\n");;
	clear_img(data);
	mlx_clear_window(data->mlx, data->mlx_window);
	mlx_destroy_window(data->mlx, data->mlx_window);
	free(data->map);
	free(data->mlx);
	free(data);
	system("leaks so_long");
	exit(1);
}

void	clear_img(t_data *data)
{
	int i;

	i = 0;
	while (i < 8)
	{
		mlx_destroy_image(data->mlx, data->img[i]);
		i++;
	}

}

void	esc_finish(t_data *data)
{
	clear_img(data);
	mlx_clear_window(data->mlx, data->mlx_window);
	mlx_destroy_window(data->mlx, data->mlx_window);
	free(data->map);
	free(data);
	exit(1);
}

void	error_finishbf(t_data *data)
{
	clear_img(data);
	free(data->map);
	free(data->mlx);
	free(data);
	system("leaks so_long");
	exit(1);
}
