/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:25:56 by gmelisan          #+#    #+#             */
/*   Updated: 2018/12/21 21:27:48 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_tet(char **lines)
{
	return (1);
}

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
	i = 0;
	k = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (lines[i][j] == '#')
			{
				coord = ft_memalloc(sizeof(*coord));
				coord->x = j;
				coord->y = i;
				new->coord[k++] = coord;
			}
			j++;
		}
		i++;
	}
	return (fix_coord(new));
}

/* 
** Adds new tetrimino to end of the list.
*/

static void		add_tet(t_tet **first, char **lines)
{
	t_tet *i;

	i = *first;
	if (i)
	{
		while (i->next)
			i = i->next;
		i->next = new_tet(lines);
	}
	else
		*first = new_tet(lines);
}

t_tet			*handle_file(char *path)
{
	int			fd;
	int			ret;
	char		**lines;
	t_tet		*tet;
	
	fd = open(path, O_RDONLY);
	tet = NULL;
	while (1)
	{
		ret = get_lines(fd, &lines, 4); /* recode this shit */
		if (ret != 4)
		{
			ft_strarrdel(&lines);
			close(fd);
			ft_assert(0);
		}
		if (check_tet(lines))
			add_tet(&tet, lines);
		ft_strarrdel(&lines);
		ret = get_lines(fd, &lines, 1);
		if (ret == 0)

		
		if (ret == 1 && **lines == '\0');
		ft_strarrdel(&lines);
	}
	return (tetlist);
}
