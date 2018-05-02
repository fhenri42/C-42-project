/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renvoi_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 15:22:58 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/05 11:22:51 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ligne_vide(char **str, int a_from)
{
	int a;
	int b;
	int compteur;
	int x;

	a = a_from;
	compteur = 0;
	x = 0;
	while (str[a] != 0 && compteur < 4)
	{
		b = 0;
		while (str[a][b] == '.' && str[a][b] != '\0' && b < 4)
			b++;
		if (str[a][b] == '#')
			return (x);
		if (b == 4)
			x++;
		a++;
		compteur++;
	}
	return (x);
}

int			collone_vide(char **str, int a_from)
{
	int a;
	int b;
	int compteur;
	int y;

	a = a_from;
	b = 0;
	compteur = 0;
	y = 0;
	while (str[a] != 0 && compteur < 4)
	{
		while (str[a] != 0 && a - a_from < 4 && str[a][b] == '.')
			a++;
		if (str[a] != 0 && str[a][b] == '#')
		{
			return (y);
		}
		if (a == a_from + 4)
			y++;
		b++;
		compteur++;
		a = a_from;
	}
	return (y);
}

t_position	renvoi_piece(char **grid, t_position x, int a_from)
{
	int			a;
	int			b;
	t_position	pos;

	pos.x = x.x;
	pos.y = x.y;
	a = a_from;
	while (grid[a])
	{
		b = 0;
		while (grid[a][b])
		{
			if (grid[a][b] == '#')
			{
				grid[a][b] = '.';
				pos.x = b - x.x;
				pos.y = a - a_from - x.y;
				return (pos);
			}
			b++;
		}
		a++;
	}
	return (pos);
}
