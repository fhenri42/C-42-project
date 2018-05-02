/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_fichier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:04:55 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/16 17:46:28 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	verife_piece(char **grid, int a, int b)
{
	int forbid;
	int conteur;

	conteur = 0;
	forbid = 0;
	while (grid[a])
	{
		b = 0;
		while (grid[a][b] != '\0')
		{
			if (grid[a][b] == '#')
			{
				forbid = second_test(grid, a, b, forbid);
				conteur++;
			}
			b++;
			if (conteur == 4 || forbid == 7)
				return (1);
			if (forbid == 30)
				return (0);
		}
		a++;
	}
	return (0);
}

int	dernier_par(char **grid, int a, int b, int m)
{
	if (b != 4 && b != 1)
		return (100);
	if (grid[a + 1] == 0)
		if (m != 16)
			return (100);
	if (grid[a][b - 1] == '\n')
	{
		if (m != 17)
			return (100);
		m = 0;
	}
	return (m);
}

int	verife(char **grid, int a, int m, int conteur)
{
	int b;

	while (grid[a] != '\0')
	{
		b = 0;
		while (grid[a][b] != '\0' && m++ > -1)
		{
			if (grid[a][b] != '.' && grid[a][b] != '#' && grid[a][b] != '\n')
				return (0);
			if (grid[a][b] == '#')
			{
				conteur = (conteur == 4) ? 0 : conteur;
				if (conteur == 0)
					if (verife_piece(grid, a, b) == 0)
						return (0);
				conteur++;
			}
			b++;
		}
		m = dernier_par(grid, a, b, m);
		if (m == 100)
			return (0);
		a++;
	}
	return (1);
}

int	contag_de_la_mort(char **grid, int a, int b, int conteur)
{
	int forme;
	int multi;

	multi = 0;
	forme = 0;
	while (grid[a] != '\0')
	{
		b = 0;
		while (grid[a][b] != '\0')
		{
			if (grid[a][b] == '.' || grid[a][b] == '#')
				conteur++;
			if (grid[a][b] == '#')
				forme++;
			b++;
		}
		if (conteur == 16 && multi++ > -1)
			conteur = 0;
		a++;
	}
	if ((multi * 4) != forme)
		return (0);
	return (1);
}

int	verif_fichier(char **grid)
{
	int m;
	int a;
	int b;
	int conteur;

	conteur = 0;
	a = 0;
	b = 0;
	m = 0;
	if (grid[0] == 0)
		return (0);
	if (verife(grid, a, m, conteur) == 0)
		return (0);
	if (contag_de_la_mort(grid, a, b, conteur) == 0)
		return (0);
	return (1);
}
