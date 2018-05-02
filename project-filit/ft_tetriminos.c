/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetriminos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 19:23:01 by vnguyen           #+#    #+#             */
/*   Updated: 2016/01/10 17:46:11 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_position		*get_positions(char **grid, t_tetriminos *piece, int *best_len)
{
	t_position	*reasonable;
	t_position	*list;

	list = NULL;
	reasonable = NULL;
	if (is_empty_grid(grid))
		reasonable = get_positions_empty(grid, list);
	else
		reasonable = reasonable_positions(grid, best_len);
	while (reasonable != NULL)
	{
		if (is_valid_position(grid, piece, reasonable, best_len))
			list = pospushback(list, poscpy(*reasonable));
		reasonable = reasonable->next;
	}
	return (list);
}

t_tetriminos	*tnew(t_tetriminos *src)
{
	t_tetriminos	*new;
	int				i;

	i = 0;
	new = malloc(sizeof(t_tetriminos));
	if (src == NULL)
	{
		new->next = NULL;
		new->number = 0;
		new->pos.x = 0;
		new->pos.y = 0;
		return (new);
	}
	while (i < 4)
	{
		new->blocs[i] = src->blocs[i];
		i++;
	}
	new->number = src->number;
	new->pos = src->pos;
	new->next = NULL;
	return (new);
}

t_tetriminos	*tlist_pushback(t_tetriminos *list, t_tetriminos *src)
{
	t_tetriminos *ptr;

	ptr = list;
	if (ptr == NULL)
		return (src);
	else
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = src;
	}
	return (list);
}

t_tetriminos	*tlist_copy(t_tetriminos *list)
{
	t_tetriminos *newlist;
	t_tetriminos *ptr;
	t_tetriminos *begin_save;

	ptr = list;
	newlist = NULL;
	tlist_pushback(newlist, tnew(ptr));
	begin_save = newlist;
	ptr = ptr->next;
	while (ptr->next != NULL)
	{
		tlist_pushback(newlist, tnew(ptr));
		ptr = ptr->next;
	}
	return (begin_save);
}

void			remove_tetriminos(char **grid, t_tetriminos *piece,
				t_position *pos)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (grid[pos->y + piece->blocs[i].y] != 0
				&& pos->x + piece->blocs[i].x >= 0)
		{
			grid[pos->y + piece->blocs[i].y][pos->x + piece->blocs[i].x] = '.';
		}
		i++;
	}
}
