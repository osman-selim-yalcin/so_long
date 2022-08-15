/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 11:31:00 by osyalcin          #+#    #+#             */
/*   Updated: 2022/08/13 11:48:19 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	mapnamecheck(char *argv)
{
	int c;

	c = 0;
	while (argv[c])
		c++;
	if (argv[c - 1] != 'r' && argv[c - 2] != 'e' && argv[c - 3] != 'b' && argv[c - 4] != '.')
	{
		ft_printf(".ber file not found\n");
		exit(1);
	}
}

void	control_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		ft_printf("mlx return NULL");
		free(data);
		exit(1);
	}
}

void	finish(t_data *data)
{
	printf("You Win\n");
	mlx_destroy_image(data->mlx, data->img);
	mlx_clear_window(data->mlx, data->mlx_window);
	exit(1);
}

void	esc_finish(t_data *data)
{
	print("exit\n");
	mlx_destroy_image(data->mlx, data->img);
	mlx_clear_window(data->mlx, data->mlx_window);
	exit(1);
}

void	error_finish(t_data *data)
{
	printf("wrong map\n");
	exit(1);
}

void	mapcheck(t_data *data)
{
	int c;
	int b;
	int f;
	int a;

	b = 0;
	f = -1;
	while (data->map[b] != '\0')
	{
		c = b;
		while (data->map[c++] != '\n' &&  data->map[c] != '\0')
			if (f == -1)
				a = c + 1;
		f += 2;
		b = c + 1;
		while (data->map[b] != '\n' && data->map[b] != '\0')
			b++;
		if (b == c + 1)
		{	
			if (c + 1 != (a * f))
				error_finish(data);
		}
		else if ((b - c + 1 != a) || (c != (a * f)))
			error_finish(data);
		b++;
	}
}

void	checkvar(t_data *data)
{
	int i;
	int p;
	int e;
	int c;

	i = 0;
	p = 0;
	c = 0;
	e = 0;
	while (data->map[i] != '\0')
	{
		if (data->map[i] == 'P')
			p++;
		if (data->map[i] == 'C')
			c++;
		if (data->map[i] == 'E')
			e++;
		i++;		
	}
	if (p != 1 | c <= 0 | e != 1)
		error_finish(data);	
}