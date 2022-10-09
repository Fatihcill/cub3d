/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 04:39:04 by fcil              #+#    #+#             */
/*   Updated: 2022/10/09 18:00:02 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_line(t_all *data, char *line)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = i;
	ft_spaceskip(line, &tmp);
	if ((line[tmp] == '1' || line[tmp] == '0') && line[tmp] != '\0')
	{
		if (line[tmp] == '0')
			error("Error: Map isn't surrounded by walls");
		ft_map(data, line, &i);
	}
	else if (line[tmp] == 'N' && line[tmp + 1] == 'O' && line[tmp + 2] == ' ')
		ft_texture(data, &data->tex.n, line, &i);
	else if (line[tmp] == 'S' && line[tmp + 1] == 'O' && line[tmp + 2] == ' ')
		ft_texture(data, &data->tex.s, line, &i);
	else if (line[tmp] == 'W' && line[tmp + 1] == 'E' && line[tmp + 2] == ' ')
		ft_texture(data, &data->tex.w, line, &i);
	else if (line[tmp] == 'E' && line[tmp + 1] == 'A' && line[tmp + 2] == ' ')
		ft_texture(data, &data->tex.e, line, &i);
	else if (line[tmp] == 'F' && line[tmp + 1] == ' ')
		ft_colors(&data->tex.f, line, &i);
	else if (line[tmp] == 'C' && line[tmp + 1] == ' ')
		ft_colors(&data->tex.c, line, &i);
	free(line);
}

static void	check_map(t_all *data, int len_y)
{
	int		i;
	int		j;
	char	**map;

	map = data->map.tab;
	i = -1;
	while (map[++i])
	{
		puts(map[i]);
		j = -1;
		while (map[i][++j])
		{
			if ((map[i][j] != '1' && map[i][j] != ' '))
				if ((i == 0 || i == len_y) || j == (int)ft_strlen(map[i]) - 1)
					error("Error: Map isn't surrounded by walls");
		}
	}
	if (data->pos_x == 0)
		error("Error: Map does not have start pos");
	if (data->tex.c == NONE || data->tex.f == NONE)
		error("Error: Missing color");
	if (data->tex.s == NULL || data->tex.n == NULL
		|| data->tex.e == NULL || data->tex.w == NULL)
		error("Error: Missing texture");
}

void	ft_parse(t_all *data, char *strmap)
{
	char	*line;
	int		fd;

	fd = open(strmap, O_RDONLY);
	if (fd < 0)
		error("Error : corrupted file (open)\n");
	line = get_next_line(fd);
	if (!line)
		error("Error : reading map");
	while (line)
	{
		ft_line(data, line);
		line = get_next_line(fd);
	}
	close(fd);
	ft_pos(data);
	check_map(data, data->map.y - 1);
}
