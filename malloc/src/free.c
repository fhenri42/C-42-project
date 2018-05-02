/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 13:02:25 by fhenri            #+#    #+#             */
/*   Updated: 2017/05/17 13:04:56 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		init_free_tools(void *ptr, t_free *t)
{
	t->length = *((long*)(ptr - 16));
	t->flag = t->length <= SMALL ? 1 << 1 : 0;
	t->tmp_prev = NULL;
}

void		flag_finder(void *ptr, t_free *t)
{
	while (t->tmp && !(t->flag & 1))
	{
		t->addr = t->tmp->addr_start;
		while (t->addr && !(t->flag & 1))
		{
			if (t->addr == ptr)
			{
				t->addr_tmp[1] = (void*)(*((long*)(t->addr - 8)));
				t->flag = t->flag | 1;
			}
			else
			{
				t->addr_tmp[0] = t->addr;
				t->addr = (void*)(*((long*)(t->addr - 8)));
			}
		}
		t->tmp_prev = t->tmp;
		t->tmp = t->tmp->next;
	}
}

void		wich_maillon1(void *ptr, t_free *t)
{
	if (!t->tmp_prev || !t->addr)
		return ;
	if (t->addr_tmp[0] != NULL || t->addr_tmp[1] != NULL)
	{
		t->data = t->addr_tmp[0] - 16;
		if (t->addr_tmp[1] == NULL)
			t->tmp_prev->addr_dispo = t->data + 16 + *(t->data);
		t->data[1] = (long)t->addr_tmp[1];
		return ;
	}
	else
	{
		if (t->addr_tmp[0])
			ft_bzero(t->addr_tmp[0] - 16, 16);
		t->tmp_prev->addr_dispo = ptr - 16;
	}
}

void		wich_maillon(void *ptr, t_free *t)
{
	if (t->tmp->addr_start == ptr)
	{
		g_meta->large = g_meta->large->next;
		munmap(t->tmp_prev, sizeof(t_memory));
		munmap(ptr - 16, *((size_t*)(ptr - 16)) + 16);
		return ;
	}
	else
		while (t->tmp->next && t->tmp->next->addr_start != ptr)
			t->tmp = t->tmp->next;
	munmap(ptr - 16, *((size_t*)(ptr - 16)) + 16);
	t->tmp_prev = t->tmp->next;
	t->tmp->next = t->tmp->next->next;
	munmap(t->tmp_prev, sizeof(t_memory));
	return (wich_maillon1(ptr, t));
}

void		free(void *ptr)
{
	t_free t;

	init_free_tools(ptr, &t);
	ft_bzero(t.addr_tmp, 16);
	if (t.length <= TINY)
		t.tmp = g_meta->tiny;
	else if (t.length > TINY && t.length <= SMALL)
		t.tmp = g_meta->small;
	else
		t.tmp = g_meta->large;
	if (t.flag & (1 << 1))
		flag_finder(ptr, &t);
	else
		return (wich_maillon(ptr, &t));
	return ;
}
