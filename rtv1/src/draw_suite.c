/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_suite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 18:28:29 by fhenri            #+#    #+#             */
/*   Updated: 2016/03/21 19:24:42 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	ft_impact2(t_draw_suite *val)
{
	val->invlight = vectorscale(-1, val->lightray->d);
	val->kdiff = vectordot(val->invlight, val->impact->d)
		* MAX((val->curlight->dist -
		val->curobject->dist) / val->curlight->dist, 0);
	if (val->kdiff >= 0)
	{
		update_color(val->kdiff * 1,
		val->curlight->color, val->final_color, val->curobject->color);
		val->reflectray = rotation(val->impact->d, val->invlight);
		vectornorm(val->reflectray);
		val->kspec = vectordot(val->invlight, val->reflectray);
		if (val->kspec >= 0)
			update_color(pow(val->kspec, 20)
			* MAX((val->curlight->dist -
			val->curobject->dist) / val->curlight->dist, 0)
			* val->curobject->shiny, val->curlight->color,
			val->final_color, val->curobject->color);
	}
}

void	ft_impact(t_draw_suite *val, t_ray *ray, t_tool *t)
{
	val->impact->o = vectoradd(ray->o,
	vectorscale(val->curobject->dist, ray->d));
	find_normal(val->impact, val->curobject);
	vectornorm(val->impact->d);
	init_color(t, val->curobject->color, val->final_color);
	val->curlight = t->l_lights;
	while (val->curlight)
	{
		val->lightray->o = vectorcopy(val->curlight->o);
		val->lightray->d = vectorsub(val->impact->o, val->lightray->o);
		vectornorm(val->lightray->d);
		if ((val->curobject2 = intersection(t->l_objects,
						val->lightray)) && val->curobject2 == val->curobject)
			ft_impact2(val);
		val->curlight = val->curlight->next;
	}
}
