/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:44:27 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/04 18:35:20 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		contage(char *str)
{
	int b;
	int a;

	a = 0;
	b = 0;
	while (str[a])
	{
		if (str[a] == '\n')
			b++;
		if (a % 4 == 0)
			b++;
		a++;
	}
	return (b);
}

char	**remp(char *str, int a, int b, char **grid)
{
	int c;

	c = 0;
	while (str[a])
	{
		if (str[a] == '\n')
		{
			if (b != 0)
				grid[b][c] = '\0';
			if (str[a] == '\n' && str[a + 1] == '\n' && a++ > -1 && b++ > -1)
			{
				grid[b] = (char*)malloc(sizeof(char) * 2);
				grid[b][0] = '\n';
			}
			b++;
			grid[b] = (char*)malloc(sizeof(char) * 4);
			c = 0;
			a++;
		}
		grid[b][c] = str[a];
		a++;
		c++;
	}
	grid[b] = 0;
	return (grid);
}

char	**full(char *str)
{
	int		a;
	int		b;
	char	**grid;

	a = 0;
	b = contage(str) + 1;
	grid = (char**)malloc(sizeof(char*) * (b + 1));
	b = 0;
	grid[0] = (char*)malloc(sizeof(char*) * 4);
	return (remp(str, a, b, grid));
}
