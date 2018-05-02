/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_touch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 12:48:54 by fhenri            #+#    #+#             */
/*   Updated: 2016/02/11 14:56:05 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		expose_hook(int x, int y, t_data *val)
{
	if (val->stop != 1 && val->info == 1)
	{
		mlx_destroy_image(val->mlx, val->img);
		mlx_clear_window(val->mlx, val->win);
		val->img = mlx_new_image(val->mlx, 1000, 650);
		if (x < 1000 && x > 1)
			val->cre = (double)x / 1000;
		if (y < 1000 && y > 1)
			val->cim = (double)y / 1000;
		if (val->info == 1)
			ft_julia(val);
		mlx_put_image_to_window(val->mlx, val->win, val->img, 0, 0);
	}
	return (0);
}

void	zoom_in(t_data *val, double xspan, double yspan, t_complex new)
{
	double tmp;

	if (val->iteration < 300)
		val->iteration += 4;
	tmp = val->x1;
	val->x1 = (new.x + (val->x2 + val->x1) / 2) / 2 - (xspan * 0.4);
	val->x2 = (new.x + (val->x2 + tmp) / 2) / 2 + (xspan * 0.4);
	tmp = val->y1;
	val->y1 = (new.y + (val->y2 + val->y1) / 2) / 2 - (yspan * 0.4);
	val->y2 = (new.y + (val->y2 + tmp) / 2) / 2 + (yspan * 0.4);
}

void	zoom_out(t_data *val, double xspan, double yspan)
{
	val->x1 = val->x1 - (xspan * 0.52);
	val->x2 = val->x2 + (xspan * 0.52);
	val->y1 = val->y1 - (yspan * 0.52);
	val->y2 = val->y2 + (yspan * 0.52);
}

int		mouse_hook(int button, int x, int y, t_data *val)
{
	t_complex	new;
	double		xspan;
	double		yspan;

	xspan = val->x2 - val->x1;
	yspan = val->y2 - val->y1;
	new.x = x / (1000 / (val->x2 - val->x1)) + val->x1;
	new.y = y / (650 / (val->y2 - val->y1)) + val->y1;
	if (button == 5)
		zoom_in(val, xspan, yspan, new);
	else if (button == 4)
		zoom_out(val, xspan, yspan);
	mlx_destroy_image(val->mlx, val->img);
	mlx_clear_window(val->mlx, val->win);
	val->img = mlx_new_image(val->mlx, 1000, 650);
	if (val->info == 1)
		ft_julia(val);
	if (val->info == 2)
		ft_mandelbrot(val);
	if (val->info == 3)
		ft_ship(val);
	mlx_put_image_to_window(val->mlx, val->win, val->img, 0, 0);
	return (0);
}
