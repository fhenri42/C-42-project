/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_postion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 19:34:13 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/29 12:08:37 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	tab_pos(t_data *val)
{
	int a;
	int b;
	int z;

	z = 0;
	a = 0;
	val->final = (t_point**)malloc(sizeof(t_point *) * val->x);
	while (a < val->x)
	{
		b = 0;
		val->final[a] = (t_point*)malloc(sizeof(t_point) * val->y);
		while (b < val->y)
		{
			val->final[a][b].z = val->grid[a][b];
			z = val->final[a][b].z;
			val->final[a][b].x = (b * (val->rota_droite - val->largeur)
			/ val->y) + val->cte_bis * (-1 * z) + val->droite;
			val->final[a][b].y = (a * (val->rota_gauche - val->longeur)
			/ val->x) + (val->cte / 2) * (-1 * z) + val->haut;
			b++;
		}
		a++;
	}
}
