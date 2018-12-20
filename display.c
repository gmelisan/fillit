/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemmeric <kemmeric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:17:36 by gmelisan          #+#    #+#             */
/*   Updated: 2018/12/20 20:12:33 by kemmeric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_assert(int exp)
{
	if (!exp)
	{
		ft_putendl("error");
		exit(0);
	}
}

void			display_usage(void)
{
	ft_putendl("usage: fillit FILE\n");
	ft_putendl("Takes FILE with list of Tetriminos, and arrange them");
	ft_putendl("in order to create the smallest square possible.");
}

void 				populate_map(char **map, t_list *tetlist)
{
	char			alpha[] = "ABCDEFGHIGKLMNOPQRSTUVWXYZ";
	int				i;
	int				k;
	t_tetrimino		*t;

	i = 0;
	while (tetlist)
	{
		t = ((t_tetrimino*)tetlist->content);
		k = 0;
		while (k < 4)
			map[t->abs_coord.x + (t->coord[k]).x][t->abs_coord.y + (t->coord[k]).y] = alpha[i];
		tetlist = tetlist->next;
		i++;
	}
}

void			display_solution(t_list *tetlist, int n)
{
	char 		**map;
	int			i;

	if (tetlist)
		ft_putnbr(n);
	ft_putstr("\n");

	if (!(map = (char**)ft_memalloc(sizeof(**map) * n + 1)))
		return ;
	i = -1;
	while (++i < n)
	{
		if (!(map[i] = ft_strnew(n)))
		{
			ft_strarrdel(&map);
			return ;
		}
		ft_memset((char*)map[i], (int)'.', n);
	}
	map[i] = 0;
	i = -1;
	while (++i < n)
		ft_putendl(map[i]);
	ft_strarrdel(&map);
}
