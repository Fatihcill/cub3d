/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 05:51:55 by fcil              #+#    #+#             */
/*   Updated: 2022/10/09 15:55:12 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	ft_ray(t_all *data)
{
	double	angle;
	double	dist;

	angle = ((double)data->ray.i - (data->win.x / 2)) * 30 / (data->win.x / 2);
	angle = angle * M_PI / 180;
	data->ray.x = data->dir.x * cos(angle) - data->dir.y * sin(angle);
	data->ray.y = data->dir.y * cos(angle) + data->dir.x * sin(angle);
	dist = hypot(data->ray.x, data->ray.y);
	data->ray.x /= dist;
	data->ray.y /= dist;
	//printf("angle :%f | dist :%d \n", angle, data->ray.i);
}

void	ft_dir(t_all *data)
{
	if (data->ray.x >= 0)
		data->ray.v = 1;
	else
		data->ray.v = 0;
	if (data->ray.y >= 0)
		data->ray.w = 1;
	else
		data->ray.w = 0;
}

void	ft_ver(t_all *data)
{
	double	x;
	double	y;

	x = floor(data->pos_x) + data->ray.v;
	y = data->pos_y + (x - data->pos_x) * (data->ray.y / data->ray.x);
	while ((int)floor(y) > 0 && (int)floor(y) < data->map.y)
	{
		if (data->map.tab[(int)floor(y)][(int)(x - 1 + data->ray.v)] == '1')
		{
			data->hit.x = x;
			data->hit.y = y;
			data->hit.d = hypot(x - data->pos_x, y - data->pos_y);
			return ;
		}
		x += (2 * data->ray.v - 1);
		y += (2 * data->ray.v - 1) * data->ray.y / data->ray.x;
	}
	data->hit.x = data->pos_x;
	data->hit.y = data->pos_y;
	data->hit.d = INT_MAX;
}

void	ft_hor(t_all *data)
{
	double	y;
	double	x;

	y = floor(data->pos_y) + data->ray.w;
	x = data->pos_x + (y - data->pos_y) * (data->ray.x / data->ray.y);

	while ((int)floor(x) > 0 && y > 0 &&
		data->map.tab[(int)(y - 1 + data->ray.w)] &&
	 (int)floor(x) < ft_strlen(data->map.tab[(int)(y - 1 + data->ray.w)]))
	{
		if (data->map.tab[(int)(y - 1 + data->ray.w)][(int)floor(x)] == '1')
		{
			if (data->hit.d > hypot(x - data->pos_x, y - data->pos_y))
			{
				data->hit.x = x;
				data->hit.y = y;
				data->hit.d = hypot(x - data->pos_x, y - data->pos_y);
			}
			return ;
		}
		y += (2 * data->ray.w - 1);
		x += (2 * data->ray.w - 1) * data->ray.x / data->ray.y;
	}
}

void	ft_reset_ray(t_all *data)
{
	t_ray	ray;
	t_hit	hit;

	ray.x = 0;
	ray.y = 0;
	ray.i = 0;
	ray.v = 0;
	ray.w = 0;
	hit.x = 0;
	hit.y = 0;
	hit.d = 0;
	data->ray = ray;
	data->hit = hit;
}

int	ft_logic(t_all *data)
{	
	if (data->key_control & GO_FORWARD)
		ft_move(data, 1);
	if (data->key_control & GO_RIGHT)
		ft_rightleft(data, 1);
	if (data->key_control & GO_BACKWARD)
		ft_move(data, -1);
	if (data->key_control & GO_LEFT)
		ft_rightleft(data, -1);
	if (data->key_control & LOOK_LEFT)
	 	ft_rotate(data, -1);
	if (data->key_control & LOOK_RIGHT)
	 	ft_rotate(data, 1);

	ft_reset_ray(data);
	ft_screen(data);
	draw_rectangles(data);
	draw_lines(data);
	draw_player(data);

	mlx_put_image_to_window(data->mlx, data->win.ptr, data->img.ptr, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win.ptr, data->minimap.img.ptr, 0, 0);
	return (1);	
}