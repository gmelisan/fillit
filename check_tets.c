/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:30:52 by gmelisan          #+#    #+#             */
/*   Updated: 2018/12/24 15:28:11 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** If cell contains '#' return 1, else 0.
*/

static int		sharp(t_tet *tet, t_coord c)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (tet->coord[i].x == c.x && tet->coord[i].y == c.y)
			return (1);
		i++;
	}
	return (0);
}

static t_coord	move(t_coord c, t_dir dir)
{
	if (dir == up)
		c.y--;
	else if (dir == down)
		c.y++;
	else if (dir == left)
		c.x--;
	else if (dir == right)
		c.x++;
	return (c);
}

static t_dir	invert_dir(t_dir dir)
{
	if (dir == up)
		return (down);
	if (dir == down)
		return (up);
	if (dir == left)
		return (right);
	if (dir == right)
		return (left);
	return (none);
}

/*
** Goes to all directions and returns sum of '#'.
** while loop:
**		up - down - left - right
*/

static int		go(t_tet *tet, t_coord coord, t_dir dir)
{
	int		res;
	t_dir	d;

	res = 1;
	if (!sharp(tet, coord))
		return (0);
	d = up;
	while (d <= right)
	{
		if (d != dir)
			res += go(tet, move(coord, d), invert_dir(d));
		d++;
	}
	return (res);
}

/*
** Check if tetrimino is valid (at least 1 neighbour and
** all cells connected).
** Squares handles separatly because otherwise infinite
** recursive loop happens.
*/

int				check_tets(t_tet *tet)
{
	int res;

	while (tet)
	{
		if (tet->coord[0].x == 0 && tet->coord[0].y == 0 &&
			tet->coord[1].x == 1 && tet->coord[1].y == 0 &&
			tet->coord[2].x == 0 && tet->coord[2].y == 1 &&
			tet->coord[3].x == 1 && tet->coord[3].y == 1)
		{
			tet = tet->next;
			continue ;
		}
		res = go(tet, tet->coord[0], up);
		if (res != 4)
			return (0);
		tet = tet->next;
	}
	return (1);
}
