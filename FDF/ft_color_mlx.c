/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 16:52:47 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/29 10:57:23 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_color(t_point a, t_point b)
{
	int val;

	if (a.z != 0)
	{
		val = a.z * 0x00CC9999;
		if (val <= 0)
			return (0x00CC9999);
		return (val);
	}
	if (b.z != 0)
	{
		val = b.z * 0x00CC9999;
		if (val <= 0)
			return (0x00CC9999);
		return (val);
	}
	return (0x00FF3333);
}
