/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 04:39:04 by fcil              #+#    #+#             */
/*   Updated: 2022/10/08 14:14:32 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_line(t_all *data, char *line)
{
	int		i;
	int		tmp;

	i = 0;
	tmp = i;
	ft_spaceskip(line, &tmp);
	if ((line[tmp] == '1') && line[tmp] != '\0')
		ft_map(data, line, &i);
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
