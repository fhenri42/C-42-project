/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_fichier.bis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 14:27:40 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/10 17:36:49 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			second_test(char **grid, int a, int b, int forbid)
{
	if (grid[a][b - 1] && grid[a + 1])
	{
		if (grid[a][b + 1] == '#' && grid[a + 1][b] == '#' &&
				grid[a + 1][b - 1] == '#')
			return (7);
		if (grid[a][b] == '#'
				&& grid[a][b + 1] == '#'
				&& grid[a][b + 2] == '#' && grid[a + 1][b] == '#')
			return (7);
	}
	if ((a + 1) >= 0 && grid[a + 1] != 0
			&& grid[a + 1][b] == '#' && forbid != 1)
		return (2);
	if ((a - 1) >= 0 && grid[a - 1] != 0 &&
			grid[a - 1][b] == '#' && forbid != 2)
		return (1);
	if (grid[a][b + 1] != 0 && grid[a][b + 1] == '#' && forbid != 3)
		return (4);
	if (grid[a][b - 1] != 0 && grid[a][b - 1] == '#' && forbid != 4)
		return (3);
	return (30);
}

t_position	*get_positions_empty(char **grid, t_position *list)
{
	t_position cursor;

	cursor.x = 0;
	cursor.y = 0;
	while (grid[cursor.y] != 0)
	{
		cursor.x = 0;
		while (grid[cursor.y][cursor.x] != '\0')
		{
			list = pospushback(list, poscpy(cursor));
			cursor.x++;
		}
		cursor.y++;
	}
	return (list);
}
