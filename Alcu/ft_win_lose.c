/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win_lose.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptao <ptao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 20:40:59 by ptao              #+#    #+#             */
/*   Updated: 2015/12/21 22:47:48 by ptao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int	fin(char *str)
{
	if (str[0] == '|' && str[1] == '\0')
		return (winner(str));
	if (str[0] == '\0')
		return (winner_ia(str));
	return (0);
}

int	ft_multiple(char *str, int a)
{
	int b;

	b = 0;
	a++;
	while (str[a] != '\n')
	{
		a++;
		b++;
	}
	if ((b % 4) == 1)
		return (ia_loss(str));
	return (ia_turn(str));
}

int	ft_win_lose(char *str)
{
	int a;
	int b;

	b = 0;
	a = ft_strlen(str);
	ft_display(str);
	while (a > 0)
	{
		if (str[a] == '\n')
			b++;
		if (b == 2)
			return (ft_multiple(str, a));
		a--;
	}
	return (ia_turn(str));
}
