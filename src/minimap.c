/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:21:23 by fcil              #+#    #+#             */
/*   Updated: 2022/10/08 16:45:21 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line(t_all *data, double x1, double y1, double x2, double y2)
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
	while (fabs(x2 - x1) > 0.01 || fabs(y2 - y1) > 0.01)
	{
		coord = y1 * data->minimap.width + x1;
		data->minimap.img.adr[coord] = GRAY;
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
		draw_line(data, i * data->minimap.map_size, 0, i * data->minimap.map_size, data->minimap.height);
		i++;
	}
	draw_line(data, data->map.x * data->minimap.map_size - 1, 0, data->map.x * data->minimap.map_size - 1, data->minimap.height);
	j = 0;
	while (j < data->map.y)
	{
		draw_line(data, 0, j * data->minimap.map_size, data->minimap.width, j * data->minimap.map_size);
		j++;
	}
	draw_line(data, 0, data->map.y * data->minimap.map_size - 1, data->minimap.width, data->map.y * data->minimap.map_size - 1);
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
		while (j < data->map.x)
		{
			if (data->map.tab[i][j] == '1')
				draw_rectangle(data, j, i, WHITE);
			if (i == (int)data->pos_y && j == (int)data->pos_x)
				draw_rectangle(data, j, i, RED);		
			j++;
		}
		i++;
	}
}

void		draw_minimap(t_all *data)
{
	int bpp;
	int sl;
	int end;

	data->minimap.width = data->map.x * data->minimap.map_size;
	data->minimap.height = data->map.y * data->minimap.map_size;
	data->minimap.img.ptr = mlx_new_image(data->mlx, data->minimap.width, data->minimap.height);
	data->minimap.img.adr = (unsigned int *)mlx_get_data_addr(data->minimap.img.ptr, &bpp, &sl, &end);
	draw_rectangles(data);
	draw_lines(data);
}
