/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:32:41 by arusso            #+#    #+#             */
/*   Updated: 2018/09/17 17:49:01 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

# define WIDTH 900
# define HEIGHT 900
# define JULIA_R 0.0
# define JULIA_IM 0.0
# define WHITE 0x00FFFFFF
# define RED 0x00FF0000
# define BLUE 0x000000FF
# define GREEN 0x0000FF00
# define START_COLOR 0xa31113;
# define K_RED 1
# define K_BLUE 3
# define K_GREEN 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define MINUS 78
# define PLUS 69
# define MULTIPLY 67
# define DIVIDE 75
# define P 35
# define SPACE 49
# define ESCAPE 53
# define RESET 15

typedef struct		s_local
{
	long double	x;
	long double	y;
	long double	x1;
	long double	y1;
	long double val;
}					t_local;

typedef struct		s_global
{
	void			*mlx;
	void			*win;
	void			*img;
	unsigned int	*data;
	char			*name;
	long double		max_x;
	long double		max_y;
	long int		color;
	long double		zoom;
	long double		v2;
	long double		v1;
	long double		it_max;
	long double		rv1;
	long double		rv2;
	int				x;
	int				y;
	int				nb_zoom;
	int				move;
	int				bpp;
	int				endian;
	int				line;
}					t_global;

int					key_move(int x, int y, t_global *lst);
int					zoom(int keycode, int x, int y, t_global *lst);
int					key_handle(int keycode, t_global *g);
void				draw(t_global *lst);
void				get_start_values(t_global *g);

#endif
