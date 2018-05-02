/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 13:50:38 by fhenri            #+#    #+#             */
/*   Updated: 2016/02/11 13:47:00 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	pixel_to_image(unsigned long color, t_data *val, int x, int y)
{
	char	*image;
	int		bpp;
	int		size_line;
	int		endian;

	image = mlx_get_data_addr(val->img, &bpp, &size_line, &endian);
	val->r = ((color & 0xFF0000) >> 16);
	val->g = ((color & 0xFF00) >> 8);
	val->b = ((color & 0xFF));
	image[x * bpp / 8 + y * size_line] = val->b;
	image[x * bpp / 8 + 1 + y * size_line] = val->g;
	image[x * bpp / 8 + 2 + y * size_line] = val->r;
}
