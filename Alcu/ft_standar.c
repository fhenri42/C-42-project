/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_standar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 11:45:01 by fhenri            #+#    #+#             */
/*   Updated: 2015/12/21 19:25:49 by ptao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int		ft_lenline(char *str)
{
	int a;

	a = 0;
	while (str[a] != '\n')
		a++;
	return (a);
}

int		stan(int x, int y, int file)
{
	char	*buf;
	char	*str;

	buf = malloc(sizeof(*buf) * BUF_SIZE);
	if (buf == NULL)
		return (0);
	str = buf;
	while (((read(0, buf, BUF_SIZE)) > 0))
	{
		if (buf[0] == '\n')
		{
			buf[0] = '\0';
			if (verif_fichier(str) == 0)
				return (error(file));
			return (creation(str, x, y));
		}
		buf += ft_lenline(buf) + 1;
	}
	return (creation(buf, x, y));
	free(buf);
}
