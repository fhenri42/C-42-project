/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verife.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 16:38:14 by fhenri            #+#    #+#             */
/*   Updated: 2016/02/21 12:46:43 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_erreur(void)
{
	ft_putstr(GREEN);
	ft_putendl("Not a valid map");
	ft_putstr(ENDOF);
	exit(0);
}

void	ft_verife(char *buf)
{
	int a;

	a = 0;
	while (buf[a])
	{
		if (buf[a] != '3' && buf[a] != '4' && buf[a] != '2'
				&& buf[a] != '0' && buf[a] != '1' && buf[a] != '5'
				&& buf[a] != '9' && buf[a] != ' ' && buf[a] != '\n')
			ft_erreur();
		a++;
	}
}

void	ft_verife_valid(t_data *val)
{
	int x;
	int y;

	x = 0;
	while (x < val->x)
	{
		y = 0;
		while (y < val->y)
		{
			if (val->grid[0][y] == 0 || val->grid[val->x - 1][y] == 0)
				ft_erreur();
			if (val->grid[x][0] == 0 || val->grid[x][val->y - 1] == 0)
				ft_erreur();
			y++;
		}
		x++;
	}
	if (val->x <= 3 || val->y <= 3)
		ft_erreur();
}
