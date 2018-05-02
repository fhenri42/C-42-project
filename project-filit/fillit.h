/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:09:59 by fhenri            #+#    #+#             */
/*   Updated: 2016/01/10 17:03:11 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_position	t_position;
typedef struct s_tetriminos	t_tetriminos;

struct					s_position
{
	short				x;
	short				y;
	t_position			*next;
};

struct					s_tetriminos
{
	t_position			blocs[4];
	unsigned short		number;
	t_position			pos;
	t_tetriminos		*next;
};

t_tetriminos			*tnew(t_tetriminos *src);
t_tetriminos			*tlist_pushback(t_tetriminos *list, t_tetriminos *src);
t_tetriminos			*tlist_copy(t_tetriminos *list);
void					remove_tetriminos(char **grid, t_tetriminos *piece,
						t_position *pos);
void					ft_putchar(char c);
void					ft_putstr(char *str);
char					**full(char *str);
char					**supp(char **str);
int						verif_fichier(char **grid);
int						ligne_vide(char **str, int a_from);
int						collone_vide(char **str, int a_from);
int						second_test(char **grid, int a, int b, int forbid);
t_position				renvoi_piece(char **grid, t_position x, int a_from);
void					insert_tetriminos(char **grid, t_tetriminos *piece,
						t_position *pos);
t_position				*poscpy(t_position src);
t_position				*pospushback(t_position *list, t_position *src);
t_position				*pushback360(t_position *list, t_position p);
t_position				*reasonable_positions(char **grid, int *best_len);
int						is_empty_grid(char **grid);
void					copy_grid(char **dst, char **src);
void					print_grid(char **grid);
char					**create_grid(int size);
int						sizeof_grid(char **grid);
t_position				*get_positions(char **grid, t_tetriminos *piece,
						int *best_len);
t_position				*get_positions_empty(char **grid, t_position *list);
char					**ft_fillit(t_tetriminos *list, int numero_piece);
void					print_grid(char **grid);
short					is_valid_position(char **grid, t_tetriminos *piece,
						t_position *p, int *best_len);
int						lets_go(char **grid, int nombre, int y, int x);

#endif
