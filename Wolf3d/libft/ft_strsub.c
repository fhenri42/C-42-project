/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:17:52 by fhenri            #+#    #+#             */
/*   Updated: 2015/12/11 17:16:23 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*tab;
	size_t		a;

	a = 0;
	tab = malloc(sizeof(char) * len + 1);
	if (tab != NULL && s != NULL)
	{
		while (a < len)
		{
			tab[a] = s[start];
			a++;
			start++;
		}
	}
	else
		return (NULL);
	tab[a] = '\0';
	return (char*)(tab);
}
