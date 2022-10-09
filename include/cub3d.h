/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:51:11 by fcil              #+#    #+#             */
/*   Updated: 2022/10/09 15:30:18 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include "stdio.h"
# include "fcntl.h"
# include "keys.h"
# include <math.h>
# include <limits.h>

# define SIZE_X 1080
# define SIZE_Y 720

# define NONE 0xFF000000
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define GRAY 0x3B3B3B
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

typedef struct	s_minimap
{
	t_img			img;
	int				width;
	int				height;
	int				map_size;
}				t_minimap;

typedef struct	s_all
{
	double			pos_x;
	double			pos_y;
	void			*mlx;
	int				key_control;
	t_win			win;
	t_img			img;
	t_map			map;
	t_tex			tex;
	t_dir			dir;
	t_ray			ray;
	t_hit			hit;
	t_minimap		minimap;
	t_stk			*stk;
}				t_all;

//read_files.c
void		ft_parse(t_all *data, char *strmap);

//utils.c
void		error(char *str);
int			ft_spaceskip(char *line, int *i);
int			ft_extcheck(char *str, char *ext);
int			ft_atoiskip(char *line, int *i);
int			ft_close(t_all *data, int win);

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

//key.c
void		ft_rotate(t_all *s, double c);
void		ft_move(t_all *data, double c);
int			ft_key_hold(int key, void *arg);
int			ft_key_release(int key, void *arg);
void		ft_rightleft(t_all *data, double c);

//minimap.c
void		init_minimap(t_all *data);
void		draw_rectangles(t_all *data);
void 		draw_lines(t_all *data);
void		draw_player(t_all *data);

//ft_logic.c
int			ft_logic(t_all *data);

//ft_screen.c
void			ft_ray(t_all *data);
void			ft_dir(t_all *data);
void			ft_ver(t_all *data);
void			ft_hor(t_all *data);
void			ft_screen(t_all *s);

#endif
