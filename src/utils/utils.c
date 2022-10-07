/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 04:44:35 by fcil              #+#    #+#             */
/*   Updated: 2022/10/07 05:36:34 by fcil             ###   ########.fr       */
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
		if (!ft_strncmp(strext, ext, ft_strlen(ext)))
			return (1);
	}
	return (0);
}

int		ft_spaceskip(char *line, int *i)
{
	while (line[*i] <= ' ')
		(*i)++;
	return (1);
}

void	error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

int		ft_atoiskip(char *line, int *i)
{
	int	num;

	num = 0;
	ft_spaceskip(line, i);
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		num = num * 10 + (line[*i] - 48);
		(*i)++;
	}
	return(num);
}
