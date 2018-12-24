/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemmeric <kemmeric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:17:36 by gmelisan          #+#    #+#             */
/*   Updated: 2018/12/24 13:38:48 by kemmeric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		display_error(void)
{
	ft_putendl("error");
}

void		display_usage(void)
{
	ft_putendl("usage: fillit FILE\n");
	ft_putendl("Takes FILE with list of Tetriminos, and arrange them");
	ft_putendl("in order to create the smallest square possible.");
}

void		populate_map(char **map, t_tet *t)
{
	int		i;
	int		k;

	i = 0;
	while (t)
	{
		k = -1;
		while (++k < 4)
			map[t->abs_coord.y + (t->coord[k]).y]
				[t->abs_coord.x + (t->coord[k]).x] = 'A' + i;
		t = t->next;
		i++;
	}
}

void		display_solution(t_tet *tets, int n)
{
	char	**map;
	int		i;

	if (!(map = (char**)ft_memalloc(sizeof(map) * (n + 1))))
		return ;
	i = -1;
	while (++i < n)
	{
		if (!(map[i] = ft_strnew(n)))
		{
			ft_strarrdel(&map);
			return ;
		}
		ft_memset((char*)(map[i]), (int)'.', n);
	}
	map[i] = 0;
	populate_map(map, tets);
	i = -1;
	while (++i < n)
		ft_putendl(map[i]);
	ft_strarrdel(&map);
}
