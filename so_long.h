/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 21:09:20 by osyalcin          #+#    #+#             */
/*   Updated: 2022/08/13 16:43:34 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "minilibx/mlx.h"
#include "gnl/get_next_line.h"
#include "printf/ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#define front "img/front.xpm"
#define left "img/left.xpm"
#define right "img/right.xpm"
#define back "img/back.xpm"
#define floor "img/floor.xpm"
#define wall "img/wall.xpm"
#define leadder "img/leadder.xpm"
#define collect "img/collect.xpm"


typedef struct s_data
{
    void    *mlx;
    void    *mlx_window;
    void    **img;
    int     imgx;
    int     imgy;
    int     position_x;
    int   	position_y;
	int		index_x;
	int		index_y;
	int		size_x;
	int		size_y;
	int		ccount;
	int		exit_x;
	int		exit_y;
	int		freeposition_x;
	int		freeposition_y;
	long int	walk;
	int		walkcheck;
	char 		*map;
	char 		*name;
}    t_data;

void openwin(t_data *data, char *argv);
void readmap(t_data *data);
void mapnamecheck(char *argv);
void mapcheck(t_data *data);
void	checkvar(t_data *data);
void	control_mlx(t_data *data);
void putcollect(t_data *data);
void putplayer(t_data *data);
void putwall(t_data *data);
void putexit(t_data *data);
void	put_background(t_data *data);
void makemap(t_data *data);
void move_right(t_data *data);
void move_left(t_data *data);
void move_up(t_data *data);
void move_down(t_data *data);
void	esc_finish(t_data *data);
void finish(t_data *data);
int   key_event(int keycode, t_data *data);
void fill(t_data *data, char *argv);
void	error_finish(t_data *data);
void	walkwrite(t_data *data);
int	itoacount(int n);
char	*ft_itoa(int n);

#endif
