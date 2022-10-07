/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:50:50 by fcil              #+#    #+#             */
/*   Updated: 2022/10/07 05:14:18 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_cubed(t_all data, char *strmap)
{
	data.mlx = mlx_init();
	ft_parse(&data, strmap);
	// ft_rotate(&s, 1);
	// ft_move(&s, 1);
	// ft_rotate(&s, -1);
	// ft_move(&s, -1);
	// s.win.ptr = mlx_new_window(s.mlx.ptr, s.win.x, s.win.y, "cub3D");
	// ft_draw(&s);
	// mlx_hook(s.win.ptr, 2, 1, ft_key, &s);
	// mlx_hook(s.win.ptr, 17, 0, ft_close, &s);
	// mlx_loop(s.mlx.ptr);
	return (1);
}

void	ft_init2(t_all data, char *strmap)
{
	t_map	map;
	t_tex	tex;
	t_stk	*stk;

	map.tab = NULL;
	tex.n = NULL;
	tex.s = NULL;
	tex.e = NULL;
	tex.w = NULL;
	tex.i = NULL;
	stk = NULL;
	map.x = 0;
	map.y = 0;
	tex.c = NONE;
	tex.f = NONE;
	data.map = map;
	data.tex = tex;
	data.stk = stk;
	ft_cubed(data, strmap);
}

void	ft_init(char *strmap)
{
	t_all	data;
	t_win	win;
	t_img	img;
	t_dir	dir;

	win.ptr = NULL;
	img.ptr = NULL;
	img.adr = NULL;
	win.x = 0;
	win.y = 0;
	img.fsh = 0;
	dir.x = 0;
	dir.y = 0;
	data.mlx = NULL;
	data.pos_x = 0;
	data.pos_y = 0;
	data.win = win;
	data.img = img;
	data.dir = dir;
	ft_init2(data, strmap);
}

int	main(int ac, char **av)
{
	void	*mlx;
	void	*mlx_win;

	if (ac == 2 && ft_extcheck(av[1], ".cub"))
		ft_init(av[1]);
	else
		error("Error : Invalid arguments\n");
	return (0);
}
