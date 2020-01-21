/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 15:28:03 by arusso            #+#    #+#             */
/*   Updated: 2018/10/06 16:23:18 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	put_controls(char *str)
{
	ft_putendl("Controls for Fract'ol :");
	ft_putendl("	- Move fractal with arrows ;");
	ft_putendl("	- Add or remove iterations with '*' and '/' ; ");
	ft_putendl("	- Zoom with left click and mouse wheel forward ; ");
	ft_putendl("	- Zoom out with right click and mouse wheel backward ; ");
	if (ft_strequ(str, "julia"))
	{
		ft_putendl("	- Change fractal shape moving your mouse ;");
		ft_putendl("	- Freeze and unfreeze fractal with space bar ;");
	}
	ft_putendl("	- Change color with the numeric keypad from 0 to 9 ;");
	ft_putendl("	- Reset fractal with 'r' ;");
	ft_putendl("	- Exit with 'ESC'.");
}

void	get_start_values(t_global *g)
{
	g->color = START_COLOR;
	g->move = 0;
	g->max_x = WIN_SIZE;
	g->max_y = WIN_SIZE;
	g->rv1 = WIN_SIZE / 2;
	g->rv2 = WIN_SIZE / 2;
	g->nb_zoom = 1;
	g->v1 = JULIA_R;
	g->v2 = JULIA_IM;
	g->it_max = 50;
	g->zoom = 250;
}

void	init_global(t_global *g)
{
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, WIN_SIZE, WIN_SIZE, "Fract'ol");
	g->img = mlx_new_image(g->mlx, WIN_SIZE, WIN_SIZE);
	g->data = (unsigned int*)mlx_get_data_addr(g->img,
			&g->bpp, &g->line, &g->endian);
	get_start_values(g);
	put_controls(g->name);
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
