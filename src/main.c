/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:50:50 by fcil              #+#    #+#             */
/*   Updated: 2022/10/03 04:49:05 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_extcheck(char *str, char *ext)
{
	int		i;
	char	*strext;
	
	i = ft_strlen(str);
	if (i > 4)
	{
		strext = &str[i - 4];
		if (!ft_strncmp(strext, ext, 4))
			return (1);
	}
	return (0);
}

void	ft_init(char *strmap)
{
	t_all	main;
	t_win	win;
	t_img	img;
	t_map	map;
	t_pos	pos;

	pos.x = 0;
	pos.y = 0;
	map.spr = 0;
	map.tab = 0;
	map.x = 0;
	map.y = 0;
	win.ptr = NULL;
	win.x = 0;
	win.y = 0;
	img.ptr = NULL;
	img.adr = NULL;
	main.img = img;
	main.map = map;
	main.mlx = NULL;
	main.pos = pos;
	main.win = win;
	ft_cubed(main, strmap);
}

int		ft_cubed(t_all main, char *map)
{
	t_pos	pos;

	main.mlx = mlx_init();
	ft_parse(&main, map);
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
