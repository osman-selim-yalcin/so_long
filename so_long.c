#include "so_long.h"

void fill(t_data *data, char *argv)
{
	data->img = (void **)malloc(sizeof(void *) * 10);
	data->img[0] = mlx_xpm_file_to_image(data->mlx, front,
		&data->imgx, &data->imgy);
	data->img[1] = mlx_xpm_file_to_image(data->mlx, left,
		&data->imgx, &data->imgy);
	data->img[2] = mlx_xpm_file_to_image(data->mlx, right,
		&data->imgx, &data->imgy);
	data->img[3] = mlx_xpm_file_to_image(data->mlx, back,
		&data->imgx, &data->imgy);
	data->img[4] = mlx_xpm_file_to_image(data->mlx, floor,
		&data->imgx, &data->imgy);
	data->img[5] = mlx_xpm_file_to_image(data->mlx, wall,
		&data->imgx, &data->imgy);
	data->img[6] = mlx_xpm_file_to_image(data->mlx, leadder,
		&data->imgx, &data->imgy);
	data->img[7] = mlx_xpm_file_to_image(data->mlx, collect,
		&data->imgx, &data->imgy);
	data->size_x = -1;
	data->size_y = -1;
	data->walk = 0;
	data->ccount = 0;
	data->name = argv;
	makemap(data);
}

int    main(int argc, char **argv)
{
    t_data    *data;
	(void)argc;
	if (argc != 2)
	{
		ft_printf("wrong arguman\n");
		exit(1);
	}
	mapnamecheck(argv[1]);
  	data = (t_data *)malloc(sizeof(t_data) * 1);
	control_mlx(data);
    fill(data, argv[1]);
	mapcheck(data);
	checkvar(data);
	openwin(data, argv[1]);
	put_background(data);
	readmap(data);
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[0],
		data->position_x * 64, data->position_y * 64);
	walkwrite(data);
    mlx_hook(data->mlx_window, 2, 1L << 0, key_event, data);
    mlx_loop(data->mlx);
}
