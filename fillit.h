/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 12:38:00 by gmelisan          #+#    #+#             */
/*   Updated: 2018/12/20 16:57:15 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

typedef struct	s_coord
{
	int x;
	int y;
}				t_coord;

typedef struct	s_tetrimino
{
	int			width;
	int			height;
	t_coord		coord[4];
	t_coord		abs_coord;
}				t_tetrimino;

void		ft_assert(int exp);
t_list		*handle_file(char *path);
char		**fillit(t_list *tetlist);
void		display_usage(void);
void		display_solution(char **sol);

#endif
