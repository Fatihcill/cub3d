/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 05:51:55 by fcil              #+#    #+#             */
/*   Updated: 2022/10/09 16:47:47 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	mlx_put_image_to_window(data->mlx, data->win.ptr,
		data->minimap.img.ptr, 0, 0);
	return (1);
}
