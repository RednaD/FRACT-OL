/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 15:28:03 by arusso            #+#    #+#             */
/*   Updated: 2018/09/17 17:47:45 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	get_start_values(t_global *g)
{
	g->color = START_COLOR;
	g->move = 0;
	g->max_x = WIDTH;
	g->max_y = HEIGHT;
	g->rv1 = WIDTH / 2;
	g->rv2 = HEIGHT / 2;
	g->nb_zoom = 1;
	g->v1 = JULIA_R;
	g->v2 = JULIA_IM;
	g->it_max = 50;
	g->zoom = 250;
}

void	init_global(t_global *g)
{
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, WIDTH, HEIGHT, "Fract'ol");
	g->img = mlx_new_image(g->mlx, WIDTH, HEIGHT);
	g->data = (unsigned int*)mlx_get_data_addr(g->img,
			&g->bpp, &g->line, &g->endian);
	get_start_values(g);
}

int		main(int ac, char **av)
{
	t_global	*g;

	if (ac != 2 || (ft_strequ(av[1], "mandelbrot") + ft_strequ(av[1], "julia")
			+ ft_strequ(av[1], "burningship")) == 0)
		ft_error("Avalaible fractals : mandelbrot, julia, burningship.");
	if (!(g = (t_global*)malloc(sizeof(t_global))))
		ft_error("Malloc failed.");
	g->name = av[1];
	init_global(g);
	draw(g);
	mlx_hook(g->win, 2, (1L << 0), key_handle, g);
	mlx_mouse_hook(g->win, zoom, g);
	if (ft_strequ(g->name, "julia") && g->move == 0)
		mlx_hook(g->win, 6, 3, key_move, g);
	mlx_loop(g->mlx);
	return (0);
}
