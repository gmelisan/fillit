/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemmeric <kemmeric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:27:21 by gmelisan          #+#    #+#             */
/*   Updated: 2018/12/22 19:01:56 by kemmeric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Algorithm:
** 1) Set "cur" tetrimino abs_coord to the current pos and check for collisions
**    (between other tetriminos and bounds of map mapsize)
** 2) Increase current pos and do step 1) in recursion
** 3) If "cur" tetrimino is null then solution was found (all on the map)
*/

int		find_collisions(t_tet *tets, t_tet *cur, int mapsize)
{
	int	a;
	int	b;

	if (cur->abs_coord.x + cur->width > mapsize ||
		cur->abs_coord.y + cur->height > mapsize)
		return (1);
	while (tets && tets != cur)
	{
		a = -1;
		while (++a < 4)
		{
			b = -1;
			while (++b < 4)
			{
				if (cur->abs_coord.x + cur->coord[a].x ==
					tets->abs_coord.x + tets->coord[b].x &&
					cur->abs_coord.y + cur->coord[a].y ==
					tets->abs_coord.y + tets->coord[b].y)
					return (1);
			}
		}
		tets = tets->next;
	}
	return (0);
}

int		find_solution(t_tet *tets, t_tet *cur, int mapsize)
{
	int	x;
	int	y;

	if (cur == NULL)
		return (1);
	y = -1;
	while (++y < mapsize)
	{
		x = -1;
		while (++x < mapsize)
		{
			cur->abs_coord.x = x;
			cur->abs_coord.y = y;
			if (find_collisions(tets, cur, mapsize))
				continue ;
			if (find_solution(tets, cur->next, mapsize))
				return (1);
		}
	}
	return (0);
}

int		fillit(t_tet *tets)
{
	int	mapsize;

	if (!tets)
		return (0);
	mapsize = tets->width > tets->height
		? tets->width
		: tets->height;
	while (1)
	{
		if (find_solution(tets, tets, mapsize))
			break ;
		mapsize++;
	}
	return (mapsize);
}
