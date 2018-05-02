/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 09:57:22 by fhenri            #+#    #+#             */
/*   Updated: 2015/12/16 09:15:29 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t				a;
	unsigned	char	*tab;

	a = 0;
	tab = (unsigned char *)b;
	while (a < len)
	{
		tab[a] = (unsigned char)c;
		a++;
	}
	return (tab);
}
