/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 16:02:45 by bgantelm          #+#    #+#             */
/*   Updated: 2016/03/21 16:03:16 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isblank(char c)
{
	return ((c == ' ' || c == '\n' || c == '\v' ||
	c == '\t' || c == '\r' || c == '\f'));
}
