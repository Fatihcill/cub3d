/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 04:39:04 by fcil              #+#    #+#             */
/*   Updated: 2022/10/07 05:35:31 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_line(t_all *data, char *line)
{
	int		i;

	i = 0;
	if ((line[i] == '1') && line[i] != '\0')
		ft_map(data, line, &i);
	else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		ft_texture(data, &data->tex.n, line, &i);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		ft_texture(data, &data->tex.s, line, &i);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		ft_texture(data, &data->tex.w, line, &i);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		ft_texture(data, &data->tex.e, line, &i);
	else if (line[i] == 'F' && line[i + 1] == ' ')
		ft_colors(&data->tex.f, line, &i);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		ft_colors(&data->tex.c, line, &i);
	free(line);
}

void		ft_parse(t_all *data, char *strmap)
{
	char	*line;
	int		fd;
	int		ret;

	ret = 1;
	fd = open(strmap, O_RDONLY);
	if(fd < 0)
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
	//todo 0-Map isn't surrounded by walls
	//todo 1- starting pos check
	//todo 2-Multiple starting positions
	//todo 3-Missing texture / color
}
