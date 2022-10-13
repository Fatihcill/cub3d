/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:33:28 by fcil              #+#    #+#             */
/*   Updated: 2022/10/13 20:52:06 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*str_append_chr(char *str, char append)
{
	char	*new_str;
	int		i;

	if (str == NULL)
		return (NULL);
	new_str = ft_calloc(ft_strlen(str) + 2, sizeof(char));
	if (new_str != NULL)
	{
		i = 0;
		while (str[i])
		{
			new_str[i] = str[i];
			i++;
		}
		new_str[i] = append;
		new_str[i + 1] = '\0';
	}
	free(str);
	return (new_str);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	buffer;
	int		check;

	line = (char *)ft_calloc(1, sizeof(char));
	if (line == NULL)
		return (NULL);
	check = read(fd, &buffer, 1);
	if (check == -1 || check == 0)
	{
		free(line);
		return (NULL);
	}
	while (check > 0)
	{
		if (buffer == '\n')
			return (line);
		line = str_append_chr(line, buffer);
		if (line == NULL)
			return (NULL);
		check = read(fd, &buffer, 1);
	}
	return (line);
}
