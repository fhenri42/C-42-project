/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 18:30:11 by fhenri            #+#    #+#             */
/*   Updated: 2016/03/21 18:30:16 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

t_pos	*vectorsub(t_pos *v1, t_pos *v2)
{
	t_pos	*result;

	result = malloc(sizeof(t_pos));
	result->x = v1->x - v2->x;
	result->y = v1->y - v2->y;
	result->z = v1->z - v2->z;
	return (result);
}

double	vectordot(t_pos *v1, t_pos *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

t_pos	*vectorscale(double c, t_pos *v)
{
	t_pos	*result;

	result = malloc(sizeof(t_pos));
	result->x = v->x * c;
	result->y = v->y * c;
	result->z = v->z * c;
	return (result);
}

t_pos	*vectoradd(t_pos *v1, t_pos *v2)
{
	t_pos	*result;

	result = malloc(sizeof(t_pos));
	result->x = v1->x + v2->x;
	result->y = v1->y + v2->y;
	result->z = v1->z + v2->z;
	return (result);
}

t_pos	*vectornew(double x, double y, double z)
{
	t_pos	*result;

	result = malloc(sizeof(t_pos));
	result->x = x;
	result->y = y;
	result->z = z;
	return (result);
}
