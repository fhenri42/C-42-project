/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 18:39:12 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/29 12:24:16 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			error(void)
{
	ft_putendl("error");
	return (0);
}

static void	ft_init(t_data *val)
{
	val->angle = 0;
	val->a = 0;
	val->b = 0;
	val->cte = 1.5;
	val->cte_bis = 0;
	val->droite = 100;
	val->haut = 300;
	val->rota_droite = 1000;
	val->rota_gauche = 500;
	val->largeur = 300;
	val->longeur = 150;
}

static int	ft_display(char *name, t_data *val)
{
	ft_init(val);
	tab_pos(val);
	val->mlx = mlx_init();
	val->win = mlx_new_window(val->mlx, 1400, 850, name);
	mlx_display(val);
	mlx_key_hook(val->win, touch_rotate, val);
	mlx_loop(val->mlx);
	return (0);
}

int			main(int argc, char **argv)
{
	char		*buf;
	int			fd;
	t_data		*val;

	val = malloc(sizeof(t_data));
	val->x = 0;
	if (argc != 2)
		return (error());
	fd = open(argv[1], O_RDONLY);
	if (fd != 3)
		return (error());
	val->grid = malloc(sizeof(int) * 10000000);
	while (get_next_line(fd, &buf) == 1)
	{
		ft_suite(buf, val);
		val->x++;
		free(buf);
	}
	return (ft_display(argv[1], val));
}
