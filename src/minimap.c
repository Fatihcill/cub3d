/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:21:23 by fcil              #+#    #+#             */
/*   Updated: 2022/10/09 14:11:57 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line(t_all *data, double x1, double y1, double x2, double y2, long color)
{
	double	deltaX;
	double	deltaY;
	double	step;
	int		coord;

	deltaX = x2 - x1;
	deltaY = y2 - y1;
	step = fabs(deltaY);
	if (fabs(deltaX) > fabs(deltaY))
		step = fabs(deltaX);
	deltaX /= step;
	deltaY /= step;
	while (fabs(x2 - x1) > fabs(deltaX) || fabs(y2 - y1) > fabs(deltaY))
	{
		coord = floor(y1) * floor(data->minimap.width) + floor(x1);
		data->minimap.img.adr[coord] = color;
		x1 += deltaX;
		y1 += deltaY;
	}
}

void 	draw_lines(t_all *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->map.x)
	{
		draw_line(data, i * data->minimap.map_size, 0, i * data->minimap.map_size, data->minimap.height, GRAY);
		i++;
	}
	draw_line(data, data->map.x * data->minimap.map_size - 1, 0, data->map.x * data->minimap.map_size - 1, data->minimap.height, GRAY);
	j = 0;
	while (j < data->map.y)
	{
		draw_line(data, 0, j * data->minimap.map_size, data->minimap.width, j * data->minimap.map_size, GRAY);
		j++;
	}
	draw_line(data, 0, data->map.y * data->minimap.map_size - 1, data->minimap.width, data->map.y * data->minimap.map_size - 1, GRAY);
}

void	draw_rectangle(t_all *data, int x, int y, long color)
{
	int i;
	int j;

	x *= data->minimap.map_size;
	y *= data->minimap.map_size;
	i = 0;
	while (i < data->minimap.map_size)
	{
		j = 0;
		while (j < data->minimap.map_size)
		{
			data->minimap.img.adr[(y  + i) * data->map.x * data->minimap.map_size + x + j] = color;
			j++;
		}
		i++;
	}
}

void	draw_rectangles(t_all *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->map.y)
	{
		j = 0;
		while (data->map.tab[i][j])
		{
			if (data->map.tab[i][j] == '1')
				draw_rectangle(data, j, i, WHITE);
			else
				draw_rectangle(data, j, i, BLACK);
			j++;
		}
		i++;
	}
}

void		draw_player(t_all *data)
{
	int	i;
	double	xp;
	double	yp;
	double	ray_x;
	double	ray_y;

	i = 0;
	xp = (ceil(data->pos_x) * data->minimap.map_size) - (data->minimap.map_size / 2);
	yp = (ceil(data->pos_y) * data->minimap.map_size) - (data->minimap.map_size / 2);
	while (i < data->ray.i)
	{
		ray_x = ceil(data->stk[i].x * data->minimap.map_size);
		ray_y = ceil(data->stk[i].y * data->minimap.map_size);
		//printf("%d %d %d\n", (int)data->stk[i].x, (int)data->stk[i].y, (int)data->stk[i].d);
		draw_line(data, xp, yp, ray_x, ray_y, GREEN);
		i++;
	}
	draw_rectangle(data, (int)data->pos_x, (int)data->pos_y, RED);
}

void		init_minimap(t_all *data)
{
	int bpp;
	int sl;
	int end;

	data->minimap.width = data->map.x * data->minimap.map_size;
	data->minimap.height = data->map.y * data->minimap.map_size;
	data->minimap.img.ptr = mlx_new_image(data->mlx, data->minimap.width, data->minimap.height);
	data->minimap.img.adr = (unsigned int *)mlx_get_data_addr(data->minimap.img.ptr, &bpp, &sl, &end);
}
