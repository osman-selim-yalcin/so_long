#include "so_long.h"

void move_right(t_data *data)
{
    int local;

    local = data->position_x + (data->position_y * (data->size_x + 1));
    if (data->map[local + 1] == 'C')
    {
        data->map[local] = '0';
        data->map[local + 1] = 'P';
        data->walk++;
        data->position_x++;
        data->walkcheck = 0;
    }
	if (data->map[local + 1] == 'E' && data->ccount == 0)
    {
        finish(data);
    }
    if (data->map[local + 1] == '0')
    {
        data->map[local] = '0';
        data->map[local + 1] = 'P';
        data->walk++;
        data->position_x++;
        data->walkcheck = 0;
    }
    mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[2],
        data->position_x * 64, data->position_y * 64);
    data->lastimg = 2;
}

void move_left(t_data *data)
{
    int local;

    local = data->position_x + (data->position_y * (data->size_x + 1));
    if (data->map[local - 1] == 'C')
    {
        data->map[local] = '0';
        data->map[local - 1] = 'P';
        data->walk++;
        data->position_x--;
        data->walkcheck = 0;
    }
	if (data->map[local - 1] == 'E' && data->ccount == 0)
        finish(data);
    if (data->map[local - 1] == '0')
    {
        data->map[local] = '0';
        data->map[local - 1] = 'P';
        data->walk++;
        data->position_x--;
        data->walkcheck = 0;
    }
    mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[1],
        data->position_x * 64, data->position_y * 64);
    data->lastimg = 1;
}

void move_up(t_data *data)
{
    int local;

    local = data->position_x + (data->position_y * (data->size_x + 1));
    if (data->map[local - (data->size_x + 1)] == 'C')
    {
        data->map[local] = '0';
        data->map[local - (data->size_x + 1)] = 'P';
        data->walk++;
        data->position_y--;
        data->walkcheck = 0;
    }
	if (data->map[local - (data->size_x + 1)] == 'E' && data->ccount == 0)
        finish(data);
    if (data->map[local - (data->size_x + 1)] == '0')
    {
        data->map[local] = '0';
        data->map[local - (data->size_x + 1)] = 'P';
        data->walk++;
        data->position_y--;
        data->walkcheck = 0;
    }
    mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[3],
        data->position_x * 64, data->position_y * 64);
    data->lastimg = 3;
}

void move_down(t_data *data)
{
    int local;

    local = data->position_x + (data->position_y * (data->size_x + 1));
    if (data->map[local + (data->size_x + 1)] == 'C')
    {
        data->map[local] = '0';
        data->map[local + (data->size_x + 1)] = 'P';
        data->walk++;
        data->position_y++;
        data->walkcheck = 0;
    }
	if (data->map[local + (data->size_x + 1)] == 'E' && data->ccount == 0)
        finish(data);
    if (data->map[local + (data->size_x + 1)] == '0')
    {
        data->map[local] = '0';
        data->map[local + (data->size_x + 1)] = 'P';
        data->walk++;
        data->position_y++;
        data->walkcheck = 0;
    }
    mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[0],
        data->position_x * 64, data->position_y * 64);
    data->lastimg = 0;
}

int   key_event(int keycode, t_data *data)
{
    mlx_clear_window(data->mlx, data->mlx_window);
    put_background(data);
    if (keycode == 0)
        move_left(data);
    if (keycode == 1)
        move_down(data);
    if (keycode == 2)
        move_right(data);
    if (keycode == 13)
        move_up(data);
    if (keycode == 53)
        esc_finish(data);
    else
        mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[data->lastimg],
    data->position_x * 64, data->position_y * 64);
    readmap(data);
	walkwrite(data);
    data->walkcheck = 1;
    return (0);
}
