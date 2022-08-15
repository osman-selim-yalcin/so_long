#include "so_long.h"

void putcollect(t_data *data)
{
		mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[7],
			data->index_x * 64, data->index_y * 64);
		data->ccount++;
}

void putplayer(t_data *data)
{
	data->position_x = data->index_x;
	data->position_y = data->index_y;
}

void putwall(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[5],
				data->index_x * 64, data->index_y * 64);
}

void putexit(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[6],
				data->index_x * 64, data->index_y * 64);
	data->exit_x = data->index_x;
	data->exit_y = data->index_y;
}

void	put_background(t_data *data)
{
	while (data->index_x != data->size_x)
	{
		while (data->index_y != data->size_y)
		{
			mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[4],
				data->index_x * 64, data->index_y * 64);
			data->index_y += 1;
		}
		data->index_y = 0;
		data->index_x += 1;
	}
	data->index_x = 0;
}