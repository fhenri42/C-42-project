/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 13:13:16 by fhenri            #+#    #+#             */
/*   Updated: 2017/05/17 13:32:28 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

void		*suite_realloc(size_t size, int sort, t_alloc *t)
{
	if (t->new == 1)
	{
		g_meta->tiny = alloc_tiny(sort);
	}
	if (t->a == NULL)
	{
		t->a = mmap(NULL, getpagesize() * sort,
		PROT_WRITE | PROT_READ, MAP_ANON | MAP_PRIVATE, -1, 0);
		t->length = (long*)t->a;
		t->length[0] = (long)size;
		t->length[1] = 0;
		g_meta->tiny->addr_start = t->a;
		g_meta->tiny->addr_tmp_start = t->a;
		g_meta->tiny->addr_dispo = t->a + size;
		t->a += 16;
	}
	return (t->a);
}

void		*re_alloc(size_t size, int sort, t_alloc *t)
{
	size += 16;
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
	return (suite_realloc(size, sort, t));
}

void		*realloc(void *ptr, size_t size)
{
	long	*length;
	long	ptr_size;
	t_alloc tools;

	init_tools(&tools);
	tools.a = ptr;
	ptr_size = *((long*)(ptr - 16));
	if (g_meta == NULL)
		g_meta = malloc_init();
	if (size <= 0)
		return (NULL);
	else if (size <= TINY)
		return (re_alloc(size, 1024, &tools));
	else if (size > TINY && size <= SMALL)
		return (re_alloc(size, 16384, &tools));
	tools.a += ptr_size;
	size += 16;
	tools.a = mmap(NULL, size + ptr_size,
			PROT_WRITE | PROT_READ, MAP_ANON | MAP_PRIVATE, -1, 0);
	length = (long*)tools.a;
	length[0] = (long)size;
	length[1] = 0;
	tools.a += 16;
	tools.a = ptr;
	return (tools.a);
}
