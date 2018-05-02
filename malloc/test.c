/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 13:49:15 by fhenri            #+#    #+#             */
/*   Updated: 2017/05/17 13:49:31 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/malloc.h"

int		main(void)
{
	int		i;
	char	*addr;

	i = 0;
	while (i < 1024)
	{
		addr = (char*)malloc(1024);
		addr[0] = 42;
		i++;
	}
	free(addr);
	return (0);
}
