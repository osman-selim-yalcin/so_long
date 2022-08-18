/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 11:00:29 by osyalcin          #+#    #+#             */
/*   Updated: 2022/08/13 16:53:50 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	openwin(t_data *data, char *argv)
{
	int		fd;
	int		check;
	char	*buffer;
	int		line;

	check = 1;
	buffer = (char *)malloc(sizeof(char) * 2);
	line = -1;
	fd = open(argv, O_RDONLY);
	while (*buffer != '\n')
	{
		check = read(fd, buffer, 1);
		line++;
		data->size_x += 1;
	}
	while (check)
	{
		check = read(fd, buffer, line);
		data->size_y += 1;
	}
	data->mlx_window = mlx_new_window(data->mlx, data->size_x * 64,
			data->size_y * 64, "Pencere");
	close(fd);
	free(buffer);
}

void readmap(t_data *data)
{
	char *temp;

	data->ccount = 0;
	temp = data->map;
	while (*temp != '\0')
	{
		if (*temp == '1')
			putwall(data);
		else if (*temp == 'C')
			putcollect(data);
		else if (*temp == 'P')
			putplayer(data);
		else if (*temp== 'E')
			putexit(data);
		data->index_x += 1;
		if (*temp == '\n')
		{
			data->index_y += 1;
			data->index_x = 0;
		}
		temp++;
	}
	data->index_y = 0;
	data->index_x = 0;
}

void makemap(t_data *data, char *argv)
{
	int fd;
	char *temp;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error_finishbf(data);
	temp = malloc(2 * sizeof(char));
	temp[0] = 'a';
	temp[1] = '\0';
	while (temp != NULL)
	{
		temp = get_next_line(fd);
		if (temp != NULL)
			data->map = ft_strjoin(data->map, temp);
	}
	free(temp);
	close(fd);
}
