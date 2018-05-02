/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 14:50:29 by fhenri            #+#    #+#             */
/*   Updated: 2017/05/17 13:46:34 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

t_memory		*alloc_tiny(int sort)
{
	t_memory	*tmp;
	size_t		s;

	s = sizeof(t_memory);
	if (sort == 1)
		tmp = g_meta->tiny;
	else
		tmp = g_meta->small;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = mmap(NULL, s, PROT_WRITE | PROT_READ,
			MAP_ANON | MAP_PRIVATE, -1, 0);
	return (tmp->next);
}

t_metadata		*malloc_init(void)
{
	t_metadata	*t;
	size_t		s;

	s = sizeof(t_metadata);
	t = mmap(NULL, s, PROT_WRITE | PROT_READ,
			MAP_ANON | MAP_PRIVATE, -1, 0);
	t->tiny = mmap(NULL, s, PROT_WRITE | PROT_READ,
			MAP_ANON | MAP_PRIVATE, -1, 0);
	t->tiny->addr_dispo = NULL;
	t->tiny->addr_start = NULL;
	t->tiny->addr_tmp_start = NULL;
	t->tiny->next = NULL;
	t->small = mmap(NULL, s, PROT_WRITE | PROT_READ,
			MAP_ANON | MAP_PRIVATE, -1, 0);
	t->small->addr_dispo = NULL;
	t->small->addr_start = NULL;
	t->small->addr_tmp_start = NULL;
	t->small->next = NULL;
	return (t);
}

void			init_tools(t_alloc *tools)
{
	tools->a = NULL;
	tools->new = 0;
	tools->tmp_start = NULL;
	tools->tmp_after = NULL;
	tools->tmp_size = 0;
}

void			ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}
