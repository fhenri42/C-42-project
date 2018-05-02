/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:11:25 by fhenri            #+#    #+#             */
/*   Updated: 2015/12/16 09:39:35 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int a;

	a = ft_strlen((char *)s);
	while (a != 0 && s[a] != (char)c)
		a--;
	if (s[a] == (char)c)
		return ((char *)&s[a]);
	return (NULL);
}
