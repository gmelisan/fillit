/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tet.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:25:37 by gmelisan          #+#    #+#             */
/*   Updated: 2018/12/24 16:20:52 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Defines width and height of tetrimino.
*/

static t_tet	*calc_wh(t_tet *tet)
{
	int i;
	int max_x;
	int max_y;

	max_x = -1;
	max_y = -1;
	i = 0;
	while (i < 4)
	{
		if (max_x < tet->coord[i].x)
			max_x = tet->coord[i].x;
		if (max_y < tet->coord[i].y)
			max_y = tet->coord[i].y;
		i++;
	}
	tet->width = max_x + 1;
	tet->height = max_y + 1;
	return (tet);
}

/*
** Translates absolute coordinates to relative.
*/

static t_tet	*fix_coord(t_tet *tet)
{
	int i;
	int min_x;
	int min_y;

	min_x = 5;
	min_y = 5;
	i = 0;
	while (i < 4)
	{
		if (min_x > tet->coord[i].x)
			min_x = tet->coord[i].x;
		if (min_y > tet->coord[i].y)
			min_y = tet->coord[i].y;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		tet->coord[i].x -= min_x;
		tet->coord[i].y -= min_y;
		i++;
	}
	tet = calc_wh(tet);
	return (tet);
}

/*
** Allocates new tetrimino.
*/

static t_tet	*new_tet(char **lines)
{
	t_tet		*new;
	int			i;
	int			j;
	int			k;

	new = ft_memalloc(sizeof(*new));
	i = -1;
	k = 0;
	while (++i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (lines[i][j] == '#')
			{
				if (k > 3)
					return (NULL);
				new->coord[k].x = j;
				new->coord[k].y = i;
				k++;
			}
			j++;
		}
	}
	return (fix_coord(new));
}

/*
** Adds new tetrimino to end of the list.
*/

void			add_tet(t_tet **first, char **lines)
{
	t_tet	*i;
	int		k;

	i = *first;
	if (i)
	{
		while (i->next)
			i = i->next;
		i->next = new_tet(lines);
	}
	else
		*first = new_tet(lines);
	k = 0;
	while (k < 5)
		free(lines[k++]);
	free(lines);
}

/*
** Delete list of tetriminos.
*/

void			del_tets(t_tet **tet)
{
	t_tet *t;

	while (*tet)
	{
		t = (*tet)->next;
		free(*tet);
		*tet = t;
	}
}
