/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 10:10:06 by fhenri            #+#    #+#             */
/*   Updated: 2016/02/11 14:33:59 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void		ft_read(void)
{
	int		fd;
	char	*line;

	fd = open("info-frac", O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		free(line);
	}
}

static void	initiali(t_data *val)
{
	val->mlx = mlx_init();
	val->win = mlx_new_window(val->mlx, 1000, 650, "fractol");
	val->img = mlx_new_image(val->mlx, 1000, 650);
	val->zoom = 1;
	val->stop = 0;
	val->colo = 0;
	val->movex = 0.0;
	val->movey = 0.0;
	val->cre = -0.7;
	val->cim = 0.27015;
	val->iteration = 50;
	val->x1 = -3;
	val->x2 = -3 + 6 * 1000 / 650;
	val->y1 = -3;
	val->y2 = 3;
}

static void	ft_luncher(t_data *val)
{
	initiali(val);
	if (val->info == 1)
		ft_julia(val);
	if (val->info == 2)
		ft_mandelbrot(val);
	if (val->info == 3)
		ft_ship(val);
	mlx_put_image_to_window(val->mlx, val->win, val->img, 0, 0);
	mlx_key_hook(val->win, touch_rotate, val);
	mlx_mouse_hook(val->win, mouse_hook, val);
	mlx_hook(val->win, 6, (1L << 6), expose_hook, val);
	mlx_loop(val->mlx);
}

int			which_fractol(void)
{
	char *buf;

	buf = malloc(sizeof(char) * BUF_SIZE);
	if (buf == NULL)
		return (0);
	while ((read(0, buf, BUF_SIZE)) > 0)
	{
		if (buf[0] == '1' && buf[1] == '\n')
			return (1);
		else if (buf[0] == '2' && buf[1] == '\n')
			return (2);
		else if (buf[0] == '3' && buf[1] == '\n')
			return (3);
		else if (buf[0] == '4' && buf[1] == '\n')
			return (4);
		else if ((buf[0] != 1 && buf[0] != 2) || buf[1] != '\n')
		{
			ft_putstr(RED);
			ft_putstr("Plz choose a valid input.\n");
			ft_putstr(ENDOF);
			return (0);
		}
	}
	return (0);
}

int			main(void)
{
	t_data *val;

	val = malloc(sizeof(t_data));
	val->info = 0;
	ft_putstr(GREEN);
	ft_putendl("welcome to Fractol:");
	ft_putstr(YELLOW);
	ft_putstr("1-Julia\n2-Mandelbrot\n3-burning ship\n");
	ft_putendl("4-All you need to know about a fractol");
	ft_putstr(ENDOF);
	while (val->info != 1 && val->info != 2 && val->info != 3)
	{
		val->info = which_fractol();
		if (val->info == 2 || val->info == 1 || val->info == 3)
		{
			ft_luncher(val);
			return (0);
		}
		if (val->info == 4)
			ft_read();
	}
	return (0);
}
