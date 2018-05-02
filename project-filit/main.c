/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 11:54:19 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/07 16:59:41 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#define BUF_SIZE 4096

int				error(void)
{
	ft_putstr("error\n");
	return (0);
}

int				intialis(char **grid)
{
	int nombre;
	int y;
	int numero_piece;

	nombre = 0;
	y = 0;
	numero_piece = 0;
	return (lets_go(grid, nombre, y, numero_piece));
}

t_tetriminos	*ft_while(char **grid, t_tetriminos *range, int y)
{
	if (grid[y - 1] != 0)
	{
		range->next = tnew(NULL);
		range = range->next;
		range->next = NULL;
	}
	return (range);
}

int				lets_go(char **grid, int nombre, int y, int numero_piece)
{
	t_position		pos;
	t_tetriminos	*range;
	t_tetriminos	*list;

	range = NULL;
	numero_piece = 0;
	list = tnew(NULL);
	range = list;
	while (grid[y] != 0 && grid[y + 1] != 0)
	{
		pos.y = ligne_vide(grid, y);
		pos.x = collone_vide(grid, y);
		nombre = 0;
		while (nombre <= 3)
		{
			range->blocs[nombre] = renvoi_piece(grid, pos, y);
			nombre++;
		}
		range->number = numero_piece;
		y += 5;
		numero_piece++;
		range = ft_while(grid, range, y);
	}
	ft_fillit(list, numero_piece);
	return (0);
}

int				main(int argc, char **argv)
{
	int		file;
	char	buf[BUF_SIZE];
	int		index;
	char	**grid;

	if (argc != 2)
		return (error());
	file = open(argv[1], O_RDONLY);
	index = read(file, buf, BUF_SIZE);
	buf[index] = '\0';
	close(file);
	if (file == -1)
		return (error());
	grid = full(buf);
	if (verif_fichier(grid) == 0)
		return (error());
	return (intialis(grid));
}
