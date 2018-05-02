/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:24:05 by fhenri            #+#    #+#             */
/*   Updated: 2017/05/16 14:52:08 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

t_metadata		*g_meta;

void			*suite_alloc(size_t size, int sort, t_alloc *tools)
{
	if (tools->new == 1)
	{
		g_meta->tiny = alloc_tiny(sort);
	}
	if (tools->a == NULL)
	{
		tools->a = mmap(NULL, getpagesize() * sort,
				PROT_WRITE | PROT_READ, MAP_ANON | MAP_PRIVATE, -1, 0);
		tools->length = (long*)tools->a;
		tools->length[0] = (long)size;
		tools->length[1] = 0;
		g_meta->tiny->addr_start = tools->a;
		g_meta->tiny->addr_tmp_start = tools->a;
		g_meta->tiny->addr_dispo = tools->a + size;
		tools->a += 16;
	}
	return (tools->a);
}

void			*chose_alloc(size_t size, t_alloc *tools)
{
	if (tools->tmp_after == 0)
	{
		tools->a = tools->tmp_start + tools->tmp_size;
		tools->length = (long*)tools->a;
		tools->length[0] = (long)size;
		tools->length[1] = 0;
		g_meta->tiny->addr_tmp_start = tools->a + size;
		g_meta->tiny->addr_dispo = tools->a + size;
		tools->a += 16;
		return (tools->a);
	}
	else if (tools->tmp_start + size + tools->tmp_size < tools->tmp_after)
	{
		tools->a = tools->tmp_start + tools->tmp_size;
		tools->length = (long*)tools->a;
		tools->length[0] = (long)size;
		tools->length[1] = 1;
		return (tools->a + 16);
	}
	return (tools->a);
}

void			*alloc(size_t size, int sort, t_alloc *t)
{
	size += 16;
	g_meta->tiny = sort == 1024 ? g_meta->tiny : g_meta->small;
	while (g_meta->tiny && g_meta->tiny->addr_tmp_start)
	{
		if (getpagesize() * sort -
				(g_meta->tiny->addr_dispo - g_meta->tiny->addr_tmp_start)
				> (long)size)
		{
			t->tmp_start = g_meta->tiny->addr_tmp_start;
			t->tmp_after = *((void**)(g_meta->tiny->addr_tmp_start - 8));
			t->tmp_size = *((long*)(g_meta->tiny->addr_tmp_start - 16));
			while (t->tmp_start != 0)
			{
				if (t->tmp_after == 0 ||
					(t->tmp_start + size + t->tmp_size < t->tmp_after))
					return (chose_alloc(size, t));
				t->tmp_start = t->tmp_after;
				t->tmp_after = t->tmp_start - 8;
				t->tmp_size = (long)t->tmp_start - 16;
			}
		}
		t->new = 1;
		g_meta->tiny = g_meta->tiny->next;
	}
	return (suite_alloc(size, sort, t));
}

void			*malloc(size_t size)
{
	void	*a;
	long	*length;
	t_alloc	tools;

	init_tools(&tools);
	a = NULL;
	if (g_meta == NULL)
		g_meta = malloc_init();
	if (size <= 0)
		return (NULL);
	else if (size <= TINY)
		return (alloc(size, 1024, &tools));
	else if (size > TINY && size <= SMALL)
		return (alloc(size, 16384, &tools));
	size += 16;
	a = mmap(NULL, size, PROT_WRITE | PROT_READ, MAP_ANON | MAP_PRIVATE, -1, 0);
	length = (long*)a;
	length[0] = (long)size;
	length[1] = 0;
	a += 16;
	return (a);
}
