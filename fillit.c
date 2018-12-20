/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemmeric <kemmeric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:27:21 by gmelisan          #+#    #+#             */
/*   Updated: 2018/12/20 20:28:48 by kemmeric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Algorithm:
** 1) Set tetrimino abs_coord to the current pos x,y and check for collisions
**    (between other tetriminos and bounds of map size)
** 2) Increase current pos and do step one in recursion
** TODO: handle all possible positions (move last tetrimino pos if there is no solution)
*/

int				find_collisions(t_list *tetlist, t_list *cur, int size)
{
	int			i;
	t_tetrimino	*t1;
	t_tetrimino	*t2;

	t2 = ((t_tetrimino*)cur->content);
	if (t2->abs_coord.x + t2->width > size || t2->abs_coord.y + t2->height > size)
		return (1);
	while (tetlist && tetlist != cur)
	{
		t1 = ((t_tetrimino*)tetlist->content);
		i = 0;
		while (i < 4)
		{
			if (t2->abs_coord.x + t2->coord[i].x == t2->abs_coord.x + t2->coord[i].x &&
				t2->abs_coord.y + t2->coord[i].y == t2->abs_coord.y + t2->coord[i].y)
				return (1);
		}
		tetlist = tetlist->next;
	}
	return (0);
}

int			find_solution(int x, int y, int size, t_list *tetlist)
{
	t_list		*first;
	t_tetrimino	*t;

	first = tetlist;
	while (y < size)
	{
		while (x < size)
		{
			t = ((t_tetrimino*)tetlist->content);
			t->abs_coord.x = x;
			t->abs_coord.y = y;
			x++; //= t->width; //FIXME: set next x pos
			if (find_collisions(first, tetlist, size))
				break ;
			if (!(tetlist = tetlist->next))
				return (1); // solution found
			if (find_solution(x, y, size, tetlist))
				return (1); // solution found
		}
		y++;
		if (y != size)
			x = 0;
	}
	if (y == size && x == size)
		return (0); // FIXME: solution not found for this size (not all tetriminos on the board)
	// FIXME: increase position and try again
	find_solution(x++, y, size, tetlist);
	return (0);
}

int				fillit(t_list *tetlist)
{
	int			size;

	if (!tetlist)
		return (0);

	size = ((t_tetrimino*)tetlist->content)->width > ((t_tetrimino*)tetlist->content)->height
		? ((t_tetrimino*)tetlist->content)->width
		: ((t_tetrimino*)tetlist->content)->height;
	// TODO: try sqrt(tetcount * 4) for init size of field

	while (1)
	{
		// start with coord 0,0
		if (find_solution(0, 0, size, tetlist))
			break ;
		size++;
	}
	return (size);
}
