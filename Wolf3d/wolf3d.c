/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 10:19:36 by fhenri            #+#    #+#             */
/*   Updated: 2016/02/22 10:06:32 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	ft_player_pos(t_data *val)
{
	int x;
	int y;
	int conteur;

	x = 0;
	conteur = 0;
	while (x < val->x)
	{
		y = 0;
		while (y < val->y)
		{
			if (val->grid[x][y] == 5)
			{
				val->pos_x = x;
				val->pos_y = y;
				val->grid[x][y] = 0;
				conteur++;
			}
			y++;
		}
		x++;
	}
	if (conteur != 1)
		exit(0);
}

void	ft_parcing(t_data *val, int fd, char *buf)
{
	val->x = 0;
	val->grid = malloc(sizeof(int) * 10000);
	while (get_next_line(fd, &buf) == 1)
	{
		ft_verife(buf);
		ft_suite(buf, val);
		val->x++;
		free(buf);
	}
}

void	ft_intitial(t_data *val)
{
	val->mlx = mlx_init();
	val->win = mlx_new_window(val->mlx, W, H, "Menu");
	val->img = mlx_new_image(val->mlx, W, H);
	val->plane_y = 1;
	ft_player_pos(val);
	val->dir_y = 0;
	val->diff = 5;
	val->forbid = 0;
	val->plane_x = 0;
	val->dir_x = -1;
	val->conteur = 0;
	val->r_cou = 2;
}

void	ft_game(t_data *val)
{
	map_gene(val);
	mlx_put_image_to_window(val->mlx, val->win, val->img, 0, 0);
	mlx_key_hook(val->win, touch_rotate, val);
	mlx_loop(val->mlx);
}

int		main(int argc, char **argv)
{
	t_data	*val;
	char	*buf;
	int		fd;

	buf = NULL;
	val = malloc(sizeof(t_data));
	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
	{
		ft_putendl("erreur");
		return (0);
	}
	if (fd != 3)
	{
		ft_putendl("erreur");
		return (0);
	}
	ft_parcing(val, fd, buf);
	ft_verife_valid(val);
	ft_intitial(val);
	ft_game(val);
	return (0);
}
