/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 09:20:40 by fhenri            #+#    #+#             */
/*   Updated: 2015/12/21 22:18:58 by ptao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"
#include "ft_color.h"

int	ft_display(char *str)
{
	int a;

	a = 0;
	ft_putstr(MAGENTA);
	ft_putstr("\tBoard:\n");
	ft_putstr(ENDOF);
	while (str[a])
	{
		ft_putchar(str[a]);
		a++;
	}
	ft_putchar('\n');
	return (0);
}

int	who_play_first(void)
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
		else if ((buf[0] != 1 && buf[0] != 2) || buf[1] != '\n')
		{
			ft_putstr(RED);
			ft_putstr("Plz choose a valid input.\n");
			ft_putstr(ENDOF);
			return (0);
		}
	}
	free(buf);
	return (0);
}

int	lets_go_my_friend(char *str)
{
	int nb;

	nb = 0;
	ft_putstr(GREEN);
	ft_putstr("1- if you like to start \n2- if you like the IA to start\n");
	ft_putstr(ENDOF);
	while (nb != 1 && nb != 2)
	{
		nb = who_play_first();
	}
	if (nb == 1)
		return (player(str));
	return (ia_turn(str));
}

int	error(int file)
{
	ft_putstr("error");
	close(file);
	return (0);
}

int	main(int argc, char **argv)
{
	int		file;
	char	buf[BUF_SIZE];
	int		index;
	int		a;
	int		y;

	y = 0;
	a = 0;
	file = 0;
	if (argc > 2)
		return (error(file));
	file = open(argv[1], O_RDONLY);
	index = read(file, buf, BUF_SIZE);
	buf[index] = '\0';
	if (file == -1)
	{
		if (argc != 1)
			return (error(file));
		return (stan(a, y, file));
	}
	if (verif_fichier(buf) == 0)
		return (error(file));
	close(file);
	return (creation(buf, a, y));
}
