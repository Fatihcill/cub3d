/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 04:33:15 by fcil              #+#    #+#             */
/*   Updated: 2022/10/07 05:38:44 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_xpm(t_all *data, unsigned int **adr, char *file)
{
	int		fd;
	void	*img;
	int		tab[5];

	if (ft_extcheck(file, ".xpm") == 0)
		error("Error : extension error");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error("Error : couldnt open file");
	close(fd);
	img = mlx_xpm_file_to_image(data->mlx, file, &tab[0], &tab[1]);
	if (img == NULL || tab[0] != 64 || tab[1] != 64)
		return (-1);
	*adr = (unsigned int *)mlx_get_data_addr(img, &tab[2], &tab[3], &tab[4]);
	free(img);
	return (0);
}

void		ft_texture(t_all *data, unsigned int **adr, char *line, int *i)
{
	char	*file;
	int		j;

	if (*adr != NULL)
		error("Error : Texture path specified twice");
	(*i) += 2;
	ft_spaceskip(line, i);
	j = *i;
	while (line[*i] != ' ' && line[*i] != '\0')
		(*i)++;
	file = malloc(sizeof(char) * (*i - j + 1));
	if (!file)
		error("Error : Malloc fail (texture path)");
	*i = j;
	j = 0;
	while (line[*i] != ' ' && line[*i] != '\0')
		file[j++] = line[(*i)++];
	file[j] = '\0';
	j = ft_xpm(data, adr, file);
	free(file);
}

void		ft_colors(unsigned int *color, char *line, int *i)
{
	int	r;
	int	g;
	int	b;

	if (*color != NONE)
		error("Error : Floor/ceiling specified twice");
	(*i)++;
	r = ft_atoiskip(line, i);
	(*i)++;
	g = ft_atoiskip(line, i);
	(*i)++;
	b = ft_atoiskip(line, i);
	ft_spaceskip(line, i);

	if (r > 255 || g > 255 || b > 255)
		error("Error : Invalid floor/ceiling color");
	*color = r * 256 * 256 + g * 256 + b;
}
