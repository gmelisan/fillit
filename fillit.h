/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 12:38:00 by gmelisan          #+#    #+#             */
/*   Updated: 2018/12/20 15:46:12 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

typedef struct	s_tetrimino
{
	char	**map;
	int		width;
	int		height;
	int		x;
	int		y;
}				t_tetrimino;

void		ft_assert(int exp);
t_list		*handle_file(char *path);
char		**fillit(t_list *tetlist);
void		display_usage(void);
void		display_solution(char **sol);

#endif
