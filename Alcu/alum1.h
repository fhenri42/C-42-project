/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptao <ptao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 22:52:56 by ptao              #+#    #+#             */
/*   Updated: 2015/12/21 22:53:00 by ptao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM1_H
# define ALUM1_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# define BUF_SIZE 30000

int		count_lastrow(char *str);
int		fin(char *str);
int		ft_multiple(char *str, int a);
int		ft_strlen_spe(char *str);
int		ft_win_lose(char *str);
int		ia_loss(char *str);
int		error(int file);
int		stan(int x, int y, int file);
int		ia_turn(char *str);
int		lets_go_my_friend(char *str);
int		ft_atoi(char *str);
int		creation(char *buf, int a, int y);
char	*rempli(int nb, char *buf, char *str);
int		winner(char *str);
int		winner_ia(char *str);
int		player(char *str);
size_t	ft_strlen(char *mot);
int		ft_display(char *str);
int		verif_fichier(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		count_nbrow(char **tab);

#endif
