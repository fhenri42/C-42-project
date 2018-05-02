/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 10:36:30 by fhenri            #+#    #+#             */
/*   Updated: 2015/12/21 22:39:14 by ptao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"
#include "ft_color.h"

int	verif(int nb, char *str)
{
	int b;

	b = ft_strlen(str);
	b--;
	if (nb > b)
		return (0);
	if (str[b] == '\n')
	{
		str[b] = '\0';
		b--;
	}
	while (nb--)
	{
		if (str[b] == '\n')
			return (0);
		b--;
	}
	return (1);
}

int	player_choose(void)
{
	char *buf;

	buf = malloc(sizeof(char) * BUF_SIZE);
	if (buf == NULL)
		return (0);
	while ((read(0, buf, BUF_SIZE)) > 0)
	{
		if (buf[0] == '1' && buf[1] == '\n')
			return (1);
		else if (buf[0] == '2' && buf[1] == '\n')
			return (2);
		else if (buf[0] == '3' && buf[1] == '\n')
			return (3);
		else if ((buf[0] != 1 && buf[0] != 2 && buf[0] != 3) || buf[1] != '\n')
		{
			ft_putstr(RED);
			ft_putstr("Plz choose a valid input.\n");
			ft_putstr(ENDOF);
			return (0);
		}
	}
	free(buf);
	return (0);
}

int	player(char *str)
{
	int a;
	int nb;

	nb = 0;
	a = ft_strlen(str);
	if (str[0] == '\0')
		return (winner(str));
	if (str[0] == '|' && str[1] == '\0')
		return (winner_ia(str));
	ft_putstr("\033[39;33mHow many match do you like to take ? 1, 2, 3 ?\n");
	ft_display(str);
	while (nb != 1 && nb != 2 && nb != 3)
		nb = player_choose();
	if (verif(nb, str) == 0)
	{
		ft_putstr("\033[39;31mThis is not a valid move in this situation.\n\n");
		return (player(str));
	}
	while (str[a] != '|')
		a--;
	a++;
	if (nb >= 1 && nb <= 3)
		str[a - nb] = '\0';
	return (ft_win_lose(str));
}
