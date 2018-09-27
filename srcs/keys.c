/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_keycode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 12:38:15 by arusso            #+#    #+#             */
/*   Updated: 2018/09/27 18:05:48 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		key_move(int x, int y, t_global *g)
{
	if (g->move == 0)
	{
		g->v1 = ((float)(x - g->rv1) / 200) * 0.1;
		g->v2 = ((float)(y - g->rv2) / 200) * 0.1;
		key_handle(0, g);
	}
	return (0);
}

int		zoom(int key, int x, int y, t_global *g)
{
	if (key == 2 || key == 5)
	{
		g->nb_zoom--;
		g->zoom /= 1.5;
		g->rv1 -= ((x - g->rv1) / 1.5) - (x - g->rv1);
		g->rv2 += ((g->rv2 - y) / 1.5) - (g->rv2 - y);
	}
	else if (key == 1 || key == 4)
	{
		g->nb_zoom++;
		g->zoom *= 1.5;
		g->rv1 -= ((x - g->rv1) * 1.5) - (x - g->rv1);
		g->rv2 += ((g->rv2 - y) * 1.5) - (g->rv2 - y);
	}
	key_handle(0, g);
	return (0);
}

void	update_color(int key, t_global *g)
{
	if (key != 90 && key >= 82 && key <= 92)
	{
		if (key == 82)
			g->color = START_COLOR;
		if (key == 83)
			g->color = 0X522376;
		if (key == 84)
			g->color = 0X513140;
		if (key == 85)
			g->color = 0X003210;
		if (key == 86)
			g->color = 0X292121;
		if (key == 87)
			g->color = 0X740134;
		if (key == 88)
			g->color = 0X773347;
		if (key == 89)
			g->color = 0X012345;
		if (key == 91)
			g->color = 0XAAC33C;
		if (key == 92)
			g->color = 0X173131;
	}
}

void	update_display(int key, t_global *g)
{
	if (key == UP || key == DOWN)
		g->rv2 = (key == UP ? g->rv2 - 5 : g->rv2 + 5);
	if (key == LEFT || key == RIGHT)
		g->rv1 = (key == LEFT ? g->rv1 - 5 : g->rv1 + 5);
	if (key == MULTIPLY || (key == DIVIDE && g->it_max > 0))
		g->it_max = (key == MULTIPLY ? g->it_max + 50 : g->it_max - 50);
	if (key == PLUS || key == MINUS)
		g->v2 = (key == PLUS ? g->v2 + 0.01 : g->v2 - 0.01);
	if (key == 15)
		get_start_values(g);
	if (key == SPACE && g->move == 0)
		g->move = 1;
	else if (key == SPACE && g->move == 1)
		g->move = 0;
	update_color(key, g);
}

int		key_handle(int key, t_global *g)
{
	char *tmp;

	if (key == ESCAPE)
		exit(0);
	update_display(key, g);
	mlx_clear_window(g->mlx, g->win);
	ft_memset(g->data, 0, sizeof(int) * WIDTH * HEIGHT);
	draw(g);
	if (ft_strequ(g->name, "julia"))
	{
		tmp = ft_flotoa(g->v1);
		mlx_string_put(g->mlx, g->win, WIDTH - 70, 10, g->color, tmp);
		free (tmp);
		tmp = ft_flotoa(g->v2);
		mlx_string_put(g->mlx, g->win, WIDTH - 70, 30, g->color, tmp);
		free (tmp);
	}
	return (0);
}
