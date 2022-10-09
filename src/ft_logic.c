/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 05:51:55 by fcil              #+#    #+#             */
/*   Updated: 2022/10/09 07:07:50 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



int	ft_logic(t_all *data)
{
	if (data->key_control & GO_FORWARD)
	{
		ft_move(data, 1);
		printf("%d\n", data->key_control);
	}
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
	draw_rectangles(data);
	draw_lines(data);
	draw_player(data);
	mlx_put_image_to_window(data->mlx, data->win.ptr, data->minimap.img.ptr, 0, 0);
	//
	//printf(" %f\n", data->pos_y);
	//ft_draw(data);
	return (1);	
}