/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 02:53:34 by fcil              #+#    #+#             */
/*   Updated: 2022/10/13 18:57:02 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_slablen(t_all *data, char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ' || line[i] == '0' || line[i] == '1')
			count++;
		else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W')
			count++;
		else if (line[i] == 'E')
			count++;
		i++;
	}
	if (count > data->map.x)
		data->map.x = count;
	return (count);
}

static char	*ft_slab(t_all *data, char *line, int *i)
{
	char	*slab;
	int		j;

	slab = malloc(sizeof(char) * (ft_slablen(data, line) + 1));
	if (!slab)
		error("Error : Malloc fail (map table)");
	j = 0;
	while (line[*i] != '\0')
	{		
		if ((line[*i] == '0' || line[*i] == '1' || line[*i] == 'N')
			|| (line[*i] == 'E' || line[*i] == 'S'
				|| line[*i] == 'W' || line[*i] == ' '))
			slab[j++] = line[*i];
		else
			error("Error : Map parse Error");
		(*i)++;
	}
	slab[j] = '\0';
	return (slab);
}

void	ft_map(t_all *data, char *line, int *i)
{
	char	**tmp;
	int		j;
	#ifndef __linux__
		if (data->map.tab != NULL)
			free(data->map.tab);
	#endif
	tmp = malloc((data->map.y + 2) * sizeof(char *));
	if (!tmp)
		error("Error : Malloc fail (map table)");
	j = -1;
	while (++j < data->map.y)
		tmp[j] = data->map.tab[j];
	tmp[data->map.y] = ft_slab(data, line, i);
	if (tmp[data->map.y] == NULL)
	{
		free(tmp);
		error("Error : Invalid map");
	}
	tmp[data->map.y + 1] = NULL;
	data->map.tab = tmp;
	data->map.y++;
}

static void	ft_set_pos(t_all *data, int i, int j, char c)
{
	if (data->pos_y == 0 && data->pos_x == 0)
	{	
		data->pos_y = (double)i + 0.5;
		data->pos_x = (double)j + 0.5;
		if (c == 'E')
			data->dir.x = 1;
		else if (c == 'W')
			data->dir.x = -1;
		else if (c == 'S')
			data->dir.y = 1;
		else if (c == 'N')
			data->dir.y = -1;
		return ;
	}
	error("Multiple starting positions");
}

void	ft_pos(t_all *data)
{
	char	c;
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < data->map.y)
	{
		while (++j < data->map.x)
		{
			c = data->map.tab[i][j];
			if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
				ft_set_pos(data, i, j, c);
		}
		j = -1;
	}
}
