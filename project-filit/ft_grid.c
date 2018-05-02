/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 19:16:04 by vnguyen           #+#    #+#             */
/*   Updated: 2016/01/04 21:22:02 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_empty_grid(char **grid)
{
	t_position pos;

	pos.x = 0;
	pos.y = 0;
	while (grid[pos.y] != 0)
	{
		pos.x = 0;
		while (grid[pos.y][pos.x] != '\0')
		{
			if (grid[pos.y][pos.x] != '.')
				return (0);
			pos.x++;
		}
		pos.y++;
	}
	return (1);
}

void	copy_grid(char **dst, char **src)
{
	int x;
	int y;

	y = 0;
	while (src[y] != 0)
	{
		x = 0;
		while (src[y][x] != 0 || src[y][x] != '\0')
		{
			dst[y][x] = src[y][x];
			x++;
		}
		y++;
	}
}

void	print_grid(char **grid)
{
	int x;
	int y;

	y = 0;
	while (grid[y] != 0)
	{
		x = 0;
		while (grid[y][x] != 0 || grid[y][x] != '\0')
		{
			ft_putchar(grid[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

char	**create_grid(int size)
{
	char	**grid;
	int		x;
	int		y;

	grid = (char**)malloc(sizeof(char*) * size + 1);
	y = 0;
	while (y < size)
	{
		x = 0;
		grid[y] = (char*)malloc(sizeof(char) * size + 1);
		while (x < size)
		{
			grid[y][x] = '.';
			x++;
		}
		grid[y][x] = '\0';
		y++;
	}
	grid[y] = 0;
	return (grid);
}

int		sizeof_grid(char **grid)
{
	t_position p;
	t_position max;

	p.y = 0;
	max.x = 0;
	max.y = 0;
	while (grid[p.y] != 0)
	{
		p.x = 0;
		while (grid[p.y][p.x] != '\0')
		{
			if (grid[p.y][p.x] != '.')
			{
				if (p.y > max.y)
					max.y = p.y;
				if (p.x > max.x)
					max.x = p.x;
			}
			p.x++;
		}
		p.y++;
	}
	p.y = (max.x >= max.y) ? max.x : max.y;
	return (p.y);
}
