/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 19:14:08 by vnguyen           #+#    #+#             */
/*   Updated: 2016/01/10 17:47:42 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

short		is_valid_position(char **grid, t_tetriminos *pc, t_position *p,
			int *m)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if ((pc->blocs[i].y + p->y) >= 0
				&& (pc->blocs[i].x + p->x) >= 0
				&& (pc->blocs[i].y + p->y) <= *m
				&& (pc->blocs[i].x + p->x) <= *m
				&& grid[pc->blocs[i].y + p->y] != 0
				&& grid[pc->blocs[i].y + p->y][pc->blocs[i].x + p->x] != 0)
		{
			if (grid[pc->blocs[i].y + p->y][pc->blocs[i].x + p->x] != '.')
				return (0);
		}
		else
			return (0);
		i++;
	}
	return (1);
}

t_position	sizeof_line(char **grid)
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
	return (max);
}

void		cut_grid(char **grid)
{
	int cut;
	int i;

	i = 0;
	cut = sizeof_grid(grid);
	while (i <= cut)
	{
		grid[i][cut + 1] = '\0';
		if (grid[cut + 1] != 0)
			grid[cut + 1][i] = '\0';
		i++;
	}
	while (grid[i] != 0)
	{
		grid[i] = 0;
		i++;
	}
}

void		fill_grid(char **grid, t_tetriminos *piece, char **best,
			int *best_l)
{
	t_position *poslist;

	poslist = NULL;
	if (piece != NULL)
	{
		if (sizeof_grid(grid) > *best_l)
			return ;
		poslist = get_positions(grid, piece, best_l);
		while (poslist != NULL)
		{
			if (sizeof_grid(grid) > *best_l)
				return ;
			insert_tetriminos(grid, piece, poslist);
			fill_grid(grid, piece->next, best, best_l);
			remove_tetriminos(grid, piece, poslist);
			poslist = poslist->next;
		}
	}
	else
	{
		if (sizeof_grid(grid) < *best_l)
			copy_grid(best, grid);
		*best_l = (sizeof_grid(grid) < *best_l) ? sizeof_grid(best) : *best_l;
	}
}

char		**ft_fillit(t_tetriminos *list, int numero_piece)
{
	char	**best;
	char	**grid;
	int		*best_len;

	if (numero_piece < 6)
		numero_piece = (numero_piece * 3) + 1;
	if (numero_piece == 6 || numero_piece == 7)
		numero_piece = (numero_piece * 2) - 3;
	if (numero_piece == 8)
		numero_piece = (numero_piece * 2) - 8;
	if (numero_piece >= 9)
		numero_piece = (numero_piece * 2) - 11;
	best = create_grid(numero_piece);
	grid = create_grid(numero_piece);
	best[numero_piece - 1][numero_piece - 1] = 'A';
	best_len = malloc(sizeof(int));
	if (best_len == NULL)
		return (NULL);
	*best_len = 10;
	fill_grid(grid, list, best, best_len);
	cut_grid(best);
	print_grid(best);
	return (NULL);
}
