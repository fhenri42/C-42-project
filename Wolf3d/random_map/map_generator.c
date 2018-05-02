/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:43:31 by fhenri            #+#    #+#             */
/*   Updated: 2016/02/21 12:42:17 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_generator.h"
#include <time.h>
int ft_random2(int nb_2)
{
	int y;
	y = rand() % nb_2;
	return (y);
}

void ft_init(t_data *val)
{
	val->x = 0;
	val->test = 0;
	val->y = 0;
	val->b = 0;
}

int generateur(int fd, t_data *val)
{
	char buf[val->nb_1][val->nb_2];

	while(val->x < val->nb_1)
	{
		val->test = 0;
		val->y = 0;
		while(val->y < val->nb_2)
		{
			if(val->x== 0 || val->x == val->nb_1 -1)
				buf[val->x][val->y] = '1';
			else
			{
				if (buf[val->x][val->y] != 2)
					buf[val->x][val->y] = '0';
			}
			buf[val->x][val->nb_2 -1 ] = '1';	
			buf[val->x][0] = '1';
			if(buf[val->x][val->y] != ' ')
				buf[val->x][val->y + 1] = ' ';
			if (val->y + 2 < val->nb_2)
				val->y+= 2;
			else
				val->y++;
		}
		while( val->test <val->nb_3)
		{
			val->b = ft_random2(val->nb_2);
			if(buf[val->x][val->b+1] == ' ')
				buf[val->x][val->b] = '3';
			val->test++;
		}
		if(val->nb_2 != 11 && val->nb_2 != 51 && val->nb_2 != 31)
			buf[val->nb_1 - (val->nb_1/2)][val->nb_2 - (val->nb_2/2) + 1] = '5';
		else
			buf[val->nb_1 - (val->nb_1/2)][val->nb_2 - (val->nb_2/2) ] = '5';
		buf[val->x][val->y] = '\n';
		buf[val->x][val->y +1] = '\0';
		ft_putstr_fd(buf[val->x],fd);
		val->x++;
	}
	return (0);
}
int erreur(void)
{
	ft_putstr(GREEN);
	ft_putendl("Syntaxe : '23' '43' 'difficult' => map 23*43 and the nubmer of wall you whant ");
	ft_putendl("Syntaxe : x && y must be under 60, if you like more, go to map_generator.c->L82 -> change the if ");
	ft_putstr(RED);
	ft_putendl("Argv2 must be a odd number: (1, 3, 5, 7, 9, 11,...)");
	return (0);

}
int main(int argc, char **argv)
{
	int fd;
	time_t t;
	t_data *val;

	val = malloc(sizeof(t_data));
	if (argc == 4)
	{
		val->nb_1 = ft_atoi(argv[1]);
		val->nb_2 = ft_atoi(argv[2]);
		val->nb_3 = ft_atoi(argv[3]);
		if (argc != 4 || val->nb_2 % 2 == 0)
		{
			return (erreur());
		}

		srand((unsigned) time(&t));
		fd = open("map", O_CREAT | O_RDWR, 0777);
		ft_init(val);
		return (generateur(fd,val));
	}
	return (erreur());
}
