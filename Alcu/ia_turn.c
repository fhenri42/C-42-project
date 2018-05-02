/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia_turn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptao <ptao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 22:52:08 by ptao              #+#    #+#             */
/*   Updated: 2015/12/21 22:52:25 by ptao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"
#include "ft_color.h"

int	count_lastrow(char *str)
{
	int	lgmax;
	int	count;

	count = 0;
	lgmax = ft_strlen(str);
	while (str[lgmax] != '|')
		lgmax--;
	while (lgmax && &str[lgmax] != &str[0] && str[lgmax] != '\n')
	{
		if (str[lgmax] == '|')
			count++;
		lgmax--;
	}
	if (&str[lgmax] == &str[0])
		count++;
	return (count);
}

int	match_towin(int nbmatch)
{
	if (nbmatch == 0)
		return (0);
	if (nbmatch == 1)
		return (1);
	if (nbmatch % 4 == 1 && nbmatch > 4)
		return (1);
	if (nbmatch <= 5)
		return (1);
	return (0);
}

int	match_tolose(int nbmatch)
{
	if (nbmatch % 4 != 1 && nbmatch > 4)
		return (1);
	if (nbmatch <= 4)
		return (1);
	return (0);
}

int	ia_turn(char *str)
{
	int coup;
	int lgmax;
	int nbmatch;

	if (fin(str) == 0)
	{
		coup = 3;
		lgmax = ft_strlen_spe(str);
		nbmatch = count_lastrow(str);
		while (coup > 0 && nbmatch > 0)
		{
			if (coup == 3 && nbmatch <= 4 && nbmatch > 1)
			{
				str[lgmax - (nbmatch - 2)] = '\0';
				return (player(str));
			}
			str[lgmax--] = '\0';
			coup--;
			if (match_towin(--nbmatch) == 1)
				return (player(str));
		}
		if (lgmax - coup - 1 != 0 && str[lgmax - coup - 1] != '|')
			str[lgmax - coup - 1] = '\0';
	}
	return (player(str));
}

int	ia_loss(char *str)
{
	int coup;
	int lgmax;
	int nbmatch;

	if (str[0] == '|' && str[1] == '\0')
		return (winner(str));
	if (str[0] == '\0')
		return (winner_ia(str));
	coup = 3;
	lgmax = ft_strlen_spe(str);
	nbmatch = count_lastrow(str);
	while (coup > 0 && nbmatch > 0)
	{
		str[lgmax] = '\0';
		lgmax--;
		coup--;
		nbmatch--;
		if (match_tolose(nbmatch) == 1)
			return (player(str));
	}
	if (lgmax - coup - 1 != 0 && str[lgmax - coup - 1] != '|')
		str[lgmax - coup - 1] = '\0';
	return (player(str));
}
