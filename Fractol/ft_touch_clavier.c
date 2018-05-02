/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_touch_clavier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 17:42:30 by fhenri            #+#    #+#             */
/*   Updated: 2016/02/11 15:11:41 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	suite23(int keycode, t_data *val)
{
	mlx_destroy_image(val->mlx, val->img);
	mlx_clear_window(val->mlx, val->win);
	val->img = mlx_new_image(val->mlx, 1000, 650);
	if (keycode == 19 && val->colo < 3)
		val->colo += 1;
	if (keycode == 18 && val->colo > 0)
		val->colo -= 1;
	if (val->info == 1)
		ft_julia(val);
	if (val->info == 2)
		ft_mandelbrot(val);
	if (val->info == 3)
		ft_ship(val);
	mlx_put_image_to_window(val->mlx, val->win, val->img, 0, 0);
	if (keycode == 53)
		exit(0);
	return (0);
}

int	suite1(int keycode, t_data *val)
{
	if (keycode == 69)
		val->iteration += 4;
	return (suite23(keycode, val));
}

int	touch_rotate(int keycode, t_data *val)
{
	if (keycode == 49)
		val->stop = 1;
	if (keycode == 258)
		val->stop = 0;
	if (keycode == 78)
		val->iteration -= 4;
	return (suite1(keycode, val));
}
