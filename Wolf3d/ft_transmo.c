/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transmo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 10:58:47 by fhenri            #+#    #+#             */
/*   Updated: 2016/02/21 12:34:57 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_remplissage(char *str, t_data *val)
{
	char	*tmp;
	int		w;

	tmp = ft_strnew(12);
	w = 0;
	while (str[val->b] != ' ' && str[val->b] != '\0')
	{
		tmp[w] = str[val->b];
		val->b++;
		w++;
	}
	val->b--;
	tmp[w] = '\0';
	val->grid[val->x][val->y] = ft_atoi(tmp);
	free(tmp);
}

void		ft_suite_suite(char *str, t_data *val, int w, char *tmp)
{
	while (str[val->b] != '\0')
	{
		while (str[val->b] == ' ' && str[val->b + 1] == ' ')
			val->b++;
		if (str[val->b] == ' '
				&& str[val->b + 1] != '0'
				&& str[val->b + 2] != ' ' && str[val->b + 2] != '\0')
		{
			val->b++;
			ft_remplissage(str, val);
		}
		else
		{
			if (str[val->b] == ' ')
				val->b++;
			w = 0;
			tmp[w] = str[val->b];
			val->grid[val->x][val->y] = ft_atoi(tmp);
			free(tmp);
			tmp = ft_strnew(2);
		}
		ft_putnbr(val->grid[val->x][val->y]);
		val->y++;
		val->b++;
	}
}

void		ft_suite(char *str, t_data *val)
{
	char	*tmp;
	int		w;

	val->grid[val->x] = malloc(sizeof(int) * ft_strlen(str));
	tmp = ft_strnew(12);
	val->b = 0;
	val->y = 0;
	w = 0;
	ft_putchar('\n');
	ft_suite_suite(str, val, w, tmp);
}
