/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_positions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 19:01:30 by vnguyen           #+#    #+#             */
/*   Updated: 2016/01/10 17:26:02 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			insert_tetriminos(char **grid, t_tetriminos *pc, t_position *p)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (grid[p->y + pc->blocs[i].y] != 0
				&& (p->x + pc->blocs[i].x) >= 0
				&& (p->y + pc->blocs[i].y) >= 0
				&& (p->x + pc->blocs[i].x) >= 0
				&& grid[p->y + pc->blocs[i].y][p->x + pc->blocs[i].x] != 0)
		{
			grid[p->y + pc->blocs[i].y]
				[p->x + pc->blocs[i].x] = (65 + pc->number);
		}
		i++;
	}
}

t_position		*poscpy(t_position src)
{
	t_position *new;

	new = malloc(sizeof(t_position));
	new->x = src.x;
	new->y = src.y;
	new->next = NULL;
	return (new);
}

t_position		*pospushback(t_position *list, t_position *src)
{
	t_position *ptr;

	ptr = list;
	if (list == NULL)
		return (src);
	else
	{
		while (ptr != NULL && ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = src;
	}
	return (list);
}

t_position		*pushback360(t_position *list, t_position p)
{
	p.y -= 1;
	list = pospushback(list, poscpy(p));
	p.y += 2;
	list = pospushback(list, poscpy(p));
	p.y -= 1;
	p.x += 1;
	list = pospushback(list, poscpy(p));
	p.x -= 2;
	list = pospushback(list, poscpy(p));
	return (list);
}

t_position		*reasonable_positions(char **grid, int *best_len)
{
	t_position p;
	t_position *list;

	p.y = 0;
	list = NULL;
	while (grid[p.y] != 0)
	{
		p.x = 0;
		while (grid[p.y][p.x] != '\0')
		{
			list = pospushback(list, poscpy(p));
			p.x++;
		}
		p.y++;
	}
	(void)(best_len);
	return (list);
}
