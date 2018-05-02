/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_victoire.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 13:03:21 by fhenri            #+#    #+#             */
/*   Updated: 2015/12/21 19:26:32 by ptao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"
#include "ft_color.h"

int	winner(char *str)
{
	ft_putstr(CYAN);
	ft_putstr("GG you have won !!!");
	ft_putstr(ENDOF);
	free(str);
	return (0);
}

int	winner_ia(char *str)
{
	ft_putstr(CYAN);
	ft_putstr("I am soory you lost Ia has won");
	ft_putstr(ENDOF);
	free(str);
	return (0);
}
