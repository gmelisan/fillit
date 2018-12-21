/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 12:38:00 by gmelisan          #+#    #+#             */
/*   Updated: 2018/12/21 18:57:38 by gmelisan         ###   ########.fr       */
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

typedef struct		s_tet
{
	int				width;
	int				height;
	t_coord			coord[4];
	t_coord			abs_coord;
	struct s_tet	*next;
}					t_tet;

void		ft_assert(int exp);
t_tet		*handle_file(char *path);
int			fillit(t_tet *tet);
void		display_usage(void);
void		display_solution(t_tet *tet, int n);
void		delete_tets(t_tet **tet);

#endif
