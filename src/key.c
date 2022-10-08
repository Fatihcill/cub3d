/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:11:46 by fcil              #+#    #+#             */
/*   Updated: 2022/10/08 15:22:53 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_rotate(t_all *data, double c)
{
	double	dist;

	data->dir.x = data->dir.x * cos(c * TURN) - data->dir.y * sin(c * TURN);
	data->dir.y = data->dir.y * cos(c * TURN) + data->dir.x * sin(c * TURN);
	dist = hypot(data->dir.x, data->dir.y);
	data->dir.x /= dist;
	data->dir.y /= dist;
}

void	ft_move(t_all *data, double c)
{
	data->pos_x += c * (data->dir.x * SPEED / 100);
	if (data->map.tab[(int)floor(data->pos_y)][(int)floor(data->pos_x)] == '1')
		data->pos_x -= c * (data->dir.x * SPEED / 100);
	data->pos_y += c * (data->dir.y * SPEED / 100);
	if (data->map.tab[(int)floor(data->pos_y)][(int)floor(data->pos_x)] == '1')
		data->pos_y -= c * (data->dir.y * SPEED / 100);
}

void	ft_rightleft(t_all *data, double c)
{
	data->pos_x -= c * (data->dir.y * SPEED / 100);
	if (data->map.tab[(int)floor(data->pos_y)][(int)floor(data->pos_x)] == '1')
		data->pos_x += c * (data->dir.y * SPEED / 100);
	data->pos_y += c * (data->dir.x * SPEED / 100);
	if (data->map.tab[(int)floor(data->pos_y)][(int)floor(data->pos_x)] == '1')
		data->pos_y -= c * (data->dir.x * SPEED / 100);
}

int		ft_close(t_all *data, int win)
{
	int	i;

	i = 0;
	while (i < data->map.y)
		free(data->map.tab[i++]);
	free(data->map.tab);
	free(data->tex.n);
	free(data->tex.s);
	free(data->tex.e);
	free(data->tex.w);
	free(data->tex.i);
	if (win == 1)
		mlx_destroy_window(data->mlx, data->win.ptr);
	free(data->mlx);
	exit(0);
	return (1);
}

int		ft_key(int key, void *arg)
{
	if (key == ESC)
		ft_close(arg, 1);
	else if (key == W)
		ft_move(arg, 1);
	else if (key == A)
		ft_rightleft(arg, -1);
	else if (key == S)
		ft_move(arg, -1);
	else if (key == D)
		ft_rightleft(arg, 1);
	else if (key == LEFT)
		ft_rotate(arg, -1);
	else if (key == RIGHT)
		ft_rotate(arg, 1);
	ft_draw(arg);
	return (1);
}
