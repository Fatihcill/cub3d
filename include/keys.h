/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcil <fcil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 05:13:04 by fcil              #+#    #+#             */
/*   Updated: 2022/10/09 06:12:44 by fcil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# ifdef __linux__
#  define ESC 65307
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define LEFT 65361
#  define RIGHT 65363
#  define SPACE 32
#  define SHIFT 65505

# else
#  define ESC 53
#  define W 13
#  define A 0
#  define S 1
#  define D 2
#  define LEFT 123
#  define RIGHT 124
#  define SPACE 49
#  define SHIFT 257
# endif

# define TURN 0.05
# define SPEED 15

# define GO_RIGHT 1
# define GO_LEFT 2
# define GO_FORWARD 4
# define GO_BACKWARD 8
# define LOOK_RIGHT 16
# define LOOK_LEFT 32

#endif
