/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:50:50 by fcil              #+#    #+#             */
/*   Updated: 2022/09/28 13:13:50 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_namecheck(char *arg, char *ext)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
		i++;
	if ((i > 4 && arg[i - 1] == ext[2] && arg[i - 2] == ext[1])
		&& (arg[i - 3] == ext[0] && arg[i - 4] == '.'))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	void	*mlx;
	void	*mlx_win;

	if (ac == 2 && ft_namecheck(av[1], "cub"))
		ft_init(av[1]);
	else
		write(2, "Error : Invalid arguments\n", 26);
	return (0);
}
