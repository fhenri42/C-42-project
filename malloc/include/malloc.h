/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 09:46:11 by fhenri            #+#    #+#             */
/*   Updated: 2017/05/17 13:51:13 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H
# include <unistd.h>
# include <sys/mman.h>

# define TINY 1024
# define SMALL 16384
# define LARGE getpagesize() * 3

typedef struct			s_memory
{
	void				*addr_dispo;
	void				*addr_start;
	void				*addr_tmp_start;
	struct s_memory		*next;
}						t_memory;

typedef struct			s_alloc
{
	void				*a;
	long				*length;
	int					new;
	void				*tmp_start;
	void				*tmp_after;
	long				tmp_size;
}						t_alloc;

typedef struct			s_free
{
	long				length;
	char				flag;
	void				*addr_tmp[2];
	void				*addr;
	long				*data;
	t_memory			*tmp;
	t_memory			*tmp_prev;
}						t_free;

typedef struct			s_metadada
{
	struct s_memory		*tiny;
	struct s_memory		*small;
	struct s_memory		*large;
}						t_metadata;

extern t_metadata		*g_meta;

t_metadata				*malloc_init();
t_memory				*alloc_tiny(int sort);
void					free(void *ptr);
void					*malloc(size_t size);
void					*realloc(void *ptr, size_t size);
void					init_tools(t_alloc *tools);
void					*chose_alloc(size_t size, t_alloc *tools);
void					ft_bzero(void *s, size_t n);

#endif
