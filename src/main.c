/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:50:50 by fcil              #+#    #+#             */
/*   Updated: 2022/10/09 15:59:52 by fcil             ###   ########.fr       */
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
	ray.w = 0;
	hit.x = 0;
	hit.y = 0;
	hit.d = 0;
	data->ray = ray;
	data->hit = hit;
	data->img.ptr = mlx_new_image(data->mlx, data->win.x, data->win.y);
	data->img.adr = (unsigned int *)mlx_get_data_addr(data->img.ptr, &bpp, &sl, &end);
	data->stk = malloc(sizeof(t_stk) * data->win.x);

	//mlx_put_image_to_window(data->mlx, data->win.ptr, data->img.ptr, 0, 0);
	//free(s->img.ptr);
	//free(s->img.adr);
}

int		ft_cubed(t_all data, char *strmap)
{
	data.mlx = mlx_init();
	ft_parse(&data, strmap);
	

	for (size_t i = 0; data.map.tab[i]; i++)
	{
		printf("%s\n",data.map.tab[i]);
	}

	data.win.ptr = mlx_new_window(data.mlx, data.win.x, data.win.y, "cub3D");
	ft_init_ray(&data);
	init_minimap(&data);

	mlx_hook(data.win.ptr, 2, 1L<<0, &ft_key_hold, &data);
	mlx_hook(data.win.ptr, 3, 1L<<1, ft_key_release, &data);
	mlx_hook(data.win.ptr, 17, 0, &ft_close, &data);
	ft_logic(&data);
	mlx_loop_hook(data.mlx, ft_logic, &data);
	mlx_loop(data.mlx);
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
	t_all		data;
	t_win		win;
	t_img		img;
	t_dir		dir;
	t_minimap	minimap;

	win.ptr = NULL;
	img.ptr = NULL;
	img.adr = NULL;
	win.x = SIZE_X;
	win.y = SIZE_Y;
	img.fsh = 0;
	dir.x = 0;
	dir.y = 0;
	minimap.img = img;
	minimap.map_size = 16;
	data.mlx = NULL;
	data.pos_x = 0;
	data.pos_y = 0;
	data.win = win;
	data.img = img;
	data.dir = dir;
	data.minimap = minimap;
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
