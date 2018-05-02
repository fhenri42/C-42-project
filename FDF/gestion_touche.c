/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_touche.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 10:37:27 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/29 12:12:48 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	suite1(int keycode, t_data *val)
{
	if (keycode == 123)
	{
		mlx_clear_window(val->mlx, val->win);
		val->droite -= 50;
		tab_pos(val);
		mlx_display(val);
	}
	if (keycode == 126)
	{
		mlx_clear_window(val->mlx, val->win);
		val->haut -= 50;
		tab_pos(val);
		mlx_display(val);
	}
	if (keycode == 125)
	{
		mlx_clear_window(val->mlx, val->win);
		val->haut += 50;
		tab_pos(val);
		mlx_display(val);
	}
	return (suite2(keycode, val));
}

int	suite2(int keycode, t_data *val)
{
	if (keycode == 12)
	{
		mlx_clear_window(val->mlx, val->win);
		val->cte += 1;
		tab_pos(val);
		mlx_display(val);
	}
	if (keycode == 13)
	{
		mlx_clear_window(val->mlx, val->win);
		val->cte -= 1;
		tab_pos(val);
		mlx_display(val);
	}
	if (keycode == 18)
	{
		mlx_clear_window(val->mlx, val->win);
		val->largeur -= 10;
		val->longeur -= 10;
		tab_pos(val);
		mlx_display(val);
	}
	return (suite3(keycode, val));
}

int	suite3(int keycode, t_data *val)
{
	if (keycode == 19)
	{
		mlx_clear_window(val->mlx, val->win);
		val->largeur += 10;
		val->longeur += 10;
		tab_pos(val);
		mlx_display(val);
	}
	if (keycode == 20)
	{
		mlx_clear_window(val->mlx, val->win);
		val->rota_droite += 100;
		val->cte_bis += 1;
		tab_pos(val);
		mlx_display(val);
	}
	if (keycode == 21)
	{
		mlx_clear_window(val->mlx, val->win);
		val->rota_droite -= 100;
		val->cte_bis -= 1;
		tab_pos(val);
		mlx_display(val);
	}
	return (suite4(keycode, val));
}

int	suite4(int keycode, t_data *val)
{
	if (keycode == 22)
	{
		mlx_clear_window(val->mlx, val->win);
		val->rota_gauche += 100;
		tab_pos(val);
		mlx_display(val);
	}
	if (keycode == 23)
	{
		mlx_clear_window(val->mlx, val->win);
		val->rota_gauche -= 100;
		tab_pos(val);
		mlx_display(val);
	}
	if (keycode == 53)
		exit(0);
	return (0);
}

int	touch_rotate(int keycode, t_data *val)
{
	if (keycode == 0)
	{
		mlx_clear_window(val->mlx, val->win);
		val->angle += 1;
		mlx_display(val);
		return (0);
	}
	if (keycode == 1)
	{
		mlx_clear_window(val->mlx, val->win);
		val->angle -= 1;
		mlx_display(val);
	}
	if (keycode == 124)
	{
		mlx_clear_window(val->mlx, val->win);
		val->droite += 50;
		tab_pos(val);
		mlx_display(val);
	}
	return (suite1(keycode, val));
}
