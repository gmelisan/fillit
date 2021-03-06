/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemmeric <kemmeric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 12:38:00 by gmelisan          #+#    #+#             */
/*   Updated: 2018/12/24 17:02:18 by kemmeric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_tet
{
	int				width;
	int				height;
	t_coord			coord[4];
	t_coord			abs_coord;
	struct s_tet	*next;
}					t_tet;

typedef enum		e_dir
{
	none,
	up,
	down,
	left,
	right
}					t_dir;

t_tet				*handle_file(char *path);
int					fillit(t_tet *tets);
void				display_solution(t_tet *tets, int n);
void				display_error(void);
void				display_usage(void);
void				add_tet(t_tet **first, char **lines);
void				del_tets(t_tet **tet);
int					check_tets(t_tet *tet);
size_t				ft_tetsize(t_tet *tets);

#endif
