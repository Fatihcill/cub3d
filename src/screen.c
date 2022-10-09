/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 04:29:12 by fcil              #+#    #+#             */
/*   Updated: 2022/10/09 05:55:02 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_screen(t_all *s)
{
	int		bpp;
	int		sl;
	int		end;

	s->img.ptr = mlx_new_image(s->mlx, s->win.x, s->win.y);
	s->img.adr = (unsigned int *)mlx_get_data_addr(s->img.ptr, &bpp, &sl, &end);
	s->stk = malloc(sizeof(t_stk) * s->win.x);
	printf("---------------");
	while (s->ray.i < s->win.x)
	{
		// ft_ray(s);
		// ft_dir(s);
		// ft_ver(s);
		// ft_hor(s);
		// ft_stock(s);
		// ft_column(s, ft_size(s));
		s->ray.i++;
	}
}
