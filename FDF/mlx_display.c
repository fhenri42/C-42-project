/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:02:57 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/29 12:03:28 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_bis(t_point a, t_point b, t_data *val, t_display *disp)
{
	int		i;
	t_point	*p;

	i = 0;
	p = malloc(sizeof(t_point));
	disp->cumul = disp->dy / 2;
	while (i <= disp->dy)
	{
		a.y += disp->yinc;
		disp->cumul += disp->dx;
		if (disp->cumul >= disp->dy)
		{
			disp->cumul -= disp->dy;
			a.x += disp->xinc;
		}
		p->x = a.x;
		p->y = a.y;
		rotate_point(600, 500, p, val);
		mlx_pixel_put(val->mlx, val->win, p->x, p->y, ft_color(a, b));
		i++;
	}
}

void	ft_draw_man(t_point a, t_point b, t_data *val, t_display *disp)
{
	int		i;
	t_point *p;

	p = malloc(sizeof(t_point));
	i = 0;
	if (disp->dx > disp->dy)
	{
		disp->cumul = disp->dx / 2;
		while (i <= disp->dx && i++ > -1)
		{
			a.x += disp->xinc;
			disp->cumul += disp->dy;
			if (disp->cumul >= disp->dx)
			{
				disp->cumul -= disp->dx;
				a.y += disp->yinc;
			}
			p->x = a.x;
			p->y = a.y;
			rotate_point(600, 500, p, val);
			mlx_pixel_put(val->mlx, val->win, p->x, p->y, ft_color(a, b));
		}
	}
	else
		ft_draw_bis(a, b, val, disp);
}

void	ft_draw_line(t_point a, t_point b, t_data *val)
{
	t_display *disp;

	disp = malloc(sizeof(t_display));
	disp->dx = b.x - a.x;
	disp->dy = b.y - a.y;
	disp->xinc = (disp->dx > 0) ? 1 : -1;
	disp->yinc = (disp->dy > 0) ? 1 : -1;
	disp->dx = abs(disp->dx);
	disp->dy = abs(disp->dy);
	(void)(val);
	ft_draw_man(a, b, val, disp);
}

void	mlx_display(t_data *val)
{
	int a;
	int b;

	a = 0;
	while (a < val->x)
	{
		b = 0;
		while (b < val->y)
		{
			if (b != 0)
				ft_draw_line(val->final[a][b - 1], val->final[a][b], val);
			if (a != 0)
				ft_draw_line(val->final[a - 1][b], val->final[a][b], val);
			b++;
		}
		a++;
	}
}
