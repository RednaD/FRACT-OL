/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 15:41:42 by arusso            #+#    #+#             */
/*   Updated: 2018/09/17 17:49:32 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		get_val_bur(long double x1, long double y1, t_global *g)
{
	double		r;
	double		im;
	double		t;
	long int	it;

	r = 0;
	im = 0;
	it = 0;
	while ((r * r + im * im) < 4 && it < g->it_max)
	{
		t = r * r - im * im + x1;
		im = fabsl((double)(2 * r * im) + y1);
		r = fabsl((double)(t));
		it++;
	}
	return (it);
}

int		get_val_mandelia(long double x1, long double y1, t_global *g)
{
	long double	r;
	long double	ri;
	long double	t;
	long double	it;

	it = 0;
	r = 0;
	ri = 0;
	if (ft_strequ(g->name, "julia"))
	{
		r = x1;
		ri = y1;
		x1 = g->v1;
		y1 = g->v2;
	}
	while ((r * r + ri * ri) < 4 && it < g->it_max)
	{
		t = r;
		r = (r * r) - (ri * ri) + x1;
		ri = ((2 * ri) * t) + y1;
		it++;
	}
	return (it);
}

void	draw(t_global *g)
{
	t_local	l;

	l.x = 0.0;
	while (l.x < g->max_x)
	{
		l.y = 0.0;
		while (l.y < g->max_y)
		{
			l.x1 = (l.x - g->rv1) / g->zoom;
			l.y1 = (l.y - g->rv2) / g->zoom;
			if (ft_strequ(g->name, "julia") || ft_strequ(g->name, "mandelbrot"))
				l.val = get_val_mandelia(l.x1, l.y1, g);
			else
				l.val = get_val_bur(l.x1, l.y1, g);
			((int*)g->data)[(int)(l.x + l.y * WIDTH)] = g->color * l.val;
			l.y++;
		}
		l.x++;
	}
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
}
