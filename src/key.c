/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:11:46 by fcil              #+#    #+#             */
/*   Updated: 2022/10/09 07:07:00 by fcil             ###   ########.fr       */
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

int		ft_key_hold(int key, void *arg)
{
	printf("\nrel:%d %d\n",key, ((t_all *)arg)->key_control);
	if (key == ESC)
		ft_close(arg, 1);
	else if (key == W)
		((t_all *)arg)->key_control |= GO_FORWARD;
	else if (key == A)
		((t_all *)arg)->key_control |= GO_LEFT;
	else if (key == S)
		((t_all *)arg)->key_control |= GO_BACKWARD;
	else if (key == D)
		((t_all *)arg)->key_control |= GO_RIGHT;
	else if (key == LEFT)
		((t_all *)arg)->key_control |= LOOK_LEFT;
	else if (key == RIGHT)
		((t_all *)arg)->key_control |= LOOK_RIGHT;
	printf("%d %d\n",key, ((t_all *)arg)->key_control);
	return (1);
}

int		ft_key_release(int key, void *arg)
{
	printf("\nrel:%d %d\n",key, ((t_all *)arg)->key_control);
	if (key == W)
		((t_all *)arg)->key_control &= ~GO_FORWARD;
	else if (key == A)
		((t_all *)arg)->key_control &= ~GO_LEFT;
	else if (key == S)
		((t_all *)arg)->key_control &= ~GO_BACKWARD;
	else if (key == D)
		((t_all *)arg)->key_control &= ~GO_RIGHT;
	else if (key == LEFT)
		((t_all *)arg)->key_control &= ~LOOK_LEFT;
	else if (key == RIGHT)
		((t_all *)arg)->key_control &= ~LOOK_RIGHT;

	printf("%d %d\n",key, ((t_all *)arg)->key_control);
	return (1);
}