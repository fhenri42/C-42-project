/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 10:07:22 by fhenri            #+#    #+#             */
/*   Updated: 2016/02/11 14:28:19 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <ft_color.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <get_next_line/get_next_line.h>
# include <libft/libft.h>
# define BUF_SIZE 10

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	int				info;
	int				stop;
	int				zoom;
	int				iteration;
	int				colo;
	double			movex;
	int				fond;
	double			movey;
	double			cre;
	double			cim;
	double			new_re;
	double			new_im;
	double			olde_re;
	double			olde_im;
	double			pr;
	double			pi;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned long	color;
}					t_data;
typedef struct		s_complex
{
	double		x;
	double		y;
}					t_complex;
void				ft_ship (t_data *val);
void				ft_my_fractal(t_data *val);
void				ft_julia(t_data *val);
void				ft_mandelbrot(t_data *val);
int					touch_rotate(int keycode, t_data *val);
int					mouse_hook(int keycode, int x, int y, t_data *val);
void				pixel_to_image(unsigned long color,
		t_data *val, int x, int y);
int					expose_hook(int x, int y, t_data *val);
#endif
