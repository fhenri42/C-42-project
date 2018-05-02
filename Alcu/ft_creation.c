/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 13:43:33 by fhenri            #+#    #+#             */
/*   Updated: 2015/12/21 19:25:36 by ptao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

char	*destru(char *str)
{
	int a;

	a = ft_strlen(str);
	while (str[a] != '|')
		a--;
	str[a + 1] = '\0';
	return (str);
}

char	*rempli(int nb, char *buf, char *str)
{
	int		a;
	char	temp[5];
	int		b;
	int		c;
	int		x;

	b = 0;
	a = -1;
	while (a++ < nb)
	{
		c = 0;
		x = 0;
		while (buf[b] >= 48 && buf[b] <= 57)
		{
			temp[x] = buf[b];
			x++;
			b++;
		}
		temp[x] = '\0';
		while (c++ < ft_atoi(temp))
			str[a++] = '|';
		str[a] = '\n';
		b++;
	}
	return (destru(str));
}

int		creation(char *buf, int a, int y)
{
	int		nb;
	int		c;
	char	*str;
	char	temp[5];

	nb = 0;
	while (buf[a])
	{
		c = 0;
		while (buf[a] >= 48 && buf[a] <= 57)
		{
			temp[c] = buf[a];
			a++;
			c++;
		}
		if (buf[a] == '\n')
			y++;
		temp[c] = '\0';
		nb = nb + ft_atoi(temp);
		a++;
	}
	str = malloc(sizeof(char) * nb + y + 1);
	nb = nb + y + 1;
	str = rempli(nb, buf, str);
	return (lets_go_my_friend(str));
}
