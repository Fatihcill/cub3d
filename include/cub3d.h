/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:51:11 by fcil              #+#    #+#             */
/*   Updated: 2022/10/07 05:34:50 by fcil             ###   ########.fr       */
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

# define NONE 0xFF000000
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define MAGENTA 0x00FF00FF
# define YELLOW 0x00FFFF00
# define CYAN 0x0000FFFF

typedef struct	s_win
{
	void			*ptr;
	int				x;
	int				y;
}				t_win;

typedef struct	s_img
{
	void			*ptr;
	unsigned int	*adr;
	int				fsh;
}				t_img;

typedef struct	s_map
{
	char			**tab;
	int				x;
	int				y;
}				t_map;

typedef struct	s_tex
{
	unsigned int	*n;
	unsigned int	*s;
	unsigned int	*e;
	unsigned int	*w;
	unsigned int	*i;
	unsigned int	c;
	unsigned int	f;
}				t_tex;

typedef struct	s_dir
{
	double			x;
	double			y;
	double			a;
}				t_dir;

typedef struct	s_ray
{
	double			x;
	double			y;
	int				i;
	double			v;
	double			w;
}				t_ray;

typedef struct	s_hit
{
	double			x;
	double			y;
	double			d;
}				t_hit;

typedef struct	s_stk
{
	double			x;
	double			y;
	double			d;
}				t_stk;

typedef struct	s_all
{
	double			pos_x;
	double			pos_y;
	void			*mlx;
	t_win			win;
	t_img			img;
	t_map			map;
	t_tex			tex;
	t_dir			dir;
	t_ray			ray;
	t_hit			hit;
	t_stk			*stk;
}				t_all;

//read_files.c
void		ft_parse(t_all *data, char *strmap);

//utils.c
void	error(char *str);
int		ft_spaceskip(char *line, int *i);
int		ft_extcheck(char *str, char *ext);
int		ft_atoiskip(char *line, int *i);

//get_next_line.c
char		*get_next_line(int fd);
char		*str_append_chr(char *str, char append);
char		*str_append_str(char *str, char *append);
char		str_last_chr(char *str);

//parse_map.c
void		ft_map(t_all *data, char *line, int *i);
void		ft_pos(t_all *data);

//parse_texture.c
void		ft_texture(t_all *data, unsigned int **adr, char *line, int *i);
void		ft_colors(unsigned int *color, char *line, int *i);

#endif
