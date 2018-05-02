/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_fichier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 09:34:49 by fhenri            #+#    #+#             */
/*   Updated: 2015/12/21 19:32:04 by ptao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int	valeur_max(char *str, int c, int x)
{
	int		a;
	char	temp[12];

	a = 0;
	while (str[c] && str[c] != '\n')
		c++;
	if (c >= 11)
		return (0);
	while (str[a])
	{
		x = 0;
		while (str[a] >= 48 && str[a] <= 57)
		{
			temp[x] = str[a];
			x++;
			a++;
		}
		temp[x] = '\0';
		if (ft_atoi(temp) > 10000 || ft_atoi(temp) == 0)
			return (0);
		a++;
	}
	return (1);
}

int	verif_fichier(char *str)
{
	int a;
	int c;
	int x;

	x = 0;
	c = 0;
	a = 0;
	if (str[a] == '\0')
		return (0);
	while (str[a])
	{
		if (str[a] == 'n')
			str[a] = '\n';
		if (str[a] != '0' && str[a] != '1' && str[a] != '2'
				&& str[a] != '3' && str[a] != '4'
				&& str[a] != '5' && str[a] != '6'
				&& str[a] != '7' && str[a] != '8'
				&& str[a] != '9' && str[a] != '\n')
			return (0);
		a++;
	}
	return (valeur_max(str, c, x));
}
