/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 10:59:39 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/29 12:13:45 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "mlx.h"
# include "get_next_line/get_next_line.h"
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;

}				t_point;
typedef struct	s_display
{
	int dx;
	int dy;
	int xinc;
	int yinc;
	int cumul;
}				t_display;
typedef struct	s_data
{
	void	*mlx;
	void	*win;
	int		angle;
	int		droite;
	int		haut;
	int		largeur;
	int		longeur;
	int		rota_droite;
	int		rota_gauche;
	int		x;
	int		y;
	int		a;
	int		b;
	float	cte;
	float	cte_bis;
	int		**grid;
	t_point **final;
}				t_data;

int				suite1(int keycode, t_data *val);
int				suite2(int keycode, t_data *val);
int				suite3(int keycode, t_data *val);
int				suite4(int keycode, t_data *val);
int				ft_color(t_point a, t_point b);
int				my_quit(int keycode);
int				touch_rotate(int keycode, t_data *param);
void			rotate_point(int cx, int cy, t_point *p, t_data *val);
void			tab_pos(t_data *val);
void			ft_suite(char *str, t_data *val);
void			mlx_display(t_data *val);
#endif
