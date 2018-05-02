/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 18:53:28 by fhenri            #+#    #+#             */
/*   Updated: 2016/02/08 13:57:33 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLOR_H
# define FT_COLOR_H

# define RED "\033[39;31m"
# define GREEN "\033[39;32m"
# define YELLOW "\033[39;33m"
# define BLUE "\033[39;34m"
# define MAGENTA "\033[39;35m"
# define CYAN "\033[39;36m"
# define WHITE "\033[39;37m"
# define BOLD_RED "\033[1;31m"
# define UNDERLINE_RED "\033[4;31m"
# define BLINK_RED "\033[5;31m"
# define ENDOF "\033[0m"
# define COLOR(c, s) triple_put(c, s, ENDOF)

#endif
