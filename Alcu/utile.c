/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 09:30:08 by fhenri            #+#    #+#             */
/*   Updated: 2015/12/21 22:47:29 by ptao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int		ft_atoi(char *str)
{
	int a;
	int n;
	int signe;

	a = 0;
	n = 0;
	signe = 1;
	while (str[a] == ' ' || str[a] == '\t' || str[a] == '\n'
			|| str[a] == '\v' || str[a] == '\f' || str[a] == '\r')
		a++;
	if (str[a] == '\0')
		return (0);
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			signe = -1;
		a++;
	}
	while (str[a] >= 48 && str[a] <= 57)
	{
		n = (n * 10) + (str[a] - 48);
		a++;
	}
	return (n * signe);
}

size_t	ft_strlen(char *mot)
{
	size_t a;

	a = 0;
	while (mot[a])
		a++;
	return (a);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int a;

	a = 0;
	while (str[a] != 0)
	{
		ft_putchar(str[a]);
		a++;
	}
}

int		ft_strlen_spe(char *str)
{
	int a;

	a = ft_strlen(str);
	while (str[a] != '|')
		a--;
	return (a);
}
