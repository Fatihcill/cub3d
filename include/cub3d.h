/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:51:11 by fcil              #+#    #+#             */
/*   Updated: 2022/10/03 05:17:22 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include "stdio.h"
# include "fcntl.h"
# include "keys.h"

# define SIZE_X 1000.0
# define SIZE_Y 1000.0

typedef struct s_win
{
	void			*ptr;
	int				x;
	int				y;
}				t_win;

typedef struct	s_img
{
	void			*ptr;
	unsigned int	*adr;
}				t_img;

typedef struct	s_map
{
	char			**tab;
	int				x;
	int				y;
	int				spr;
}				t_map;

typedef struct	s_pos
{
	double			x;
	double			y;
}				t_pos;


typedef struct	s_all
{
	void			*mlx;
	t_win			win;
	t_img			img;
	t_map			map;
	t_pos			pos;
}				t_all;

//read_files.c
int	ft_parse(t_all *main, char *map);

//utils.c
void	error(char *str);

//get_next_line.c
char		*get_next_line(int fd);
char		*str_append_chr(char *str, char append);
char		*str_append_str(char *str, char *append);
char		str_last_chr(char *str);

#endif
