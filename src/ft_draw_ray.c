/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:15:49 by fcil              #+#    #+#             */
/*   Updated: 2022/10/13 20:46:19 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_ray(t_all *data)
{
	t_ray	ray;
	t_hit	hit;
	int		bpp;
	int		sl;
	int		end;

	ray.x = 0;
	ray.y = 0;
	ray.i = 0;
	ray.v = 0;
	ray.h = 0;
	hit.x = 0;
	hit.y = 0;
	hit.d = 0;
	data->ray = ray;
	data->hit = hit;
	data->img.ptr = mlx_new_image(data->mlx, data->win.x, data->win.y);
	data->img.adr = (unsigned int *)
		mlx_get_data_addr(data->img.ptr, &bpp, &sl, &end);
	data->stk = malloc(sizeof(t_stk) * data->win.x);
}

void	ft_ray(t_all *data)
{
	double	angle;

	angle = ((double)data->ray.i - (data->win.x / 2)) * 30 / (data->win.x / 2);
	angle = angle * M_PI / 180;
	data->ray.x = data->dir.x * cos(angle) - data->dir.y * sin(angle);
	data->ray.y = data->dir.y * cos(angle) + data->dir.x * sin(angle);
}

void	ft_dir(t_all *data)
{
	if (data->ray.x >= 0)
		data->ray.v = 1;
	else
		data->ray.v = 0;
	if (data->ray.y >= 0)
		data->ray.h = 1;
	else
		data->ray.h = 0;
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

	y = floor(data->pos_y) + data->ray.h;
	x = data->pos_x + (y - data->pos_y) * (data->ray.x / data->ray.y);
	while ((int)floor(x) > 0 && y > 0
		&& data->map.tab[(int)(y - 1 + data->ray.h)]
		&& (int)floor(x)
		< (int)ft_strlen(data->map.tab[(int)(y - 1 + data->ray.h)]))
	{
		if (data->map.tab[(int)(y - 1 + data->ray.h)][(int)floor(x)] == '1')
		{
			if (data->hit.d > hypot(x - data->pos_x, y - data->pos_y))
			{
				data->hit.x = x;
				data->hit.y = y;
				data->hit.d = hypot(x - data->pos_x, y - data->pos_y);
			}
			return ;
		}
		y += (2 * data->ray.h - 1);
		x += (2 * data->ray.h - 1) * data->ray.x / data->ray.y;
	}
}
