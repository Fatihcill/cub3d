/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:51:11 by fcil              #+#    #+#             */
/*   Updated: 2022/09/28 13:12:23 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include "stdio.h"

# define SIZE_X 1000.0
# define SIZE_Y 1000.0

typedef struct s_mlx
{
	void			*ptr;
}				t_mlx;

typedef struct s_win
{
	void			*ptr;
	int				x;
	int				y;
}				t_win;

#endif
