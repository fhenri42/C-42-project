/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:43:31 by fhenri            #+#    #+#             */
/*   Updated: 2016/02/22 10:13:01 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <time.h>

int		ft_random(int nb_2)
{
	int y;

	y = rand() % nb_2;
	return (y);
}

void	suite_generateur(t_data *val, int x, unsigned int conteur)
{
	int b;

	b = 0;
	while (conteur < val->diff)
	{
		b = ft_random(val->y);
		if (val->fin == 0 && x == val->alea)
		{
			val->grid[x][b] = 9;
			val->fin = 10;
		}
		else
			val->grid[x][b] = 3;
		conteur++;
	}
	if (val->y != 11 && val->y != 51 && val->y != 31)
		val->grid[val->x - (val->x / 2)][val->y - (val->y / 2) + 1] = 5;
	else
		val->grid[val->x - (val->x / 2)][val->y - (val->y / 2)] = 5;
}

void	generateur(t_data *val, int x, int y, unsigned int conteur)
{
	while (x < val->x - 1)
	{
		conteur = 0;
		y = 0;
		while (y < val->y - 1)
		{
			if (x == 0 || x == val->x - 2)
				val->grid[x][y] = 1;
			else
			{
				if (y == val->y - 2)
					val->grid[x][y] = 1;
				else
					val->grid[x][y] = 0;
			}
			val->grid[x][0] = 1;
			y++;
		}
		suite_generateur(val, x, conteur);
		x++;
	}
}

void	map_generator(t_data *val)
{
	int				x;
	int				y;
	unsigned int	conteur;
	time_t			t;

	x = 0;
	y = 0;
	conteur = 0;
	val->fin = 0;
	val->alea = rand() % val->x - 2;
	srand((unsigned)time(&t));
	generateur(val, x, y, conteur);
}
