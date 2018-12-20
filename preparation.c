/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:25:56 by gmelisan          #+#    #+#             */
/*   Updated: 2018/12/20 18:00:46 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* 
** Gets array of n lines readed from fd. Returns number of readed lines
** or -1 in case of error.
*/

int		ft_get_lines(int fd, char ***lines, int n)
{
	int	i;
	int	ret;

	if (n <= 0 || fd < 0 || !lines)
		return (0);
	*lines = ft_memalloc(sizeof(**lines) * (n + 1));
	i = 0;
	while (i < n)
	{
		if ((ret = get_next_line(fd, *lines + i)) == 0)
			return (i);
		if (ret == -1)
		{
			i--;
			while (i >= 0)
			{
				ft_memdel((void **)(*lines + i));
				i--;
			}
			ft_memdel((void **)lines);
			return (-1);
		}
		i++;
	}
	return (i);
}

int		check_tet(char **lines)
{
	return (1);
}

void	push(t_list *tetlist, char **lines)
{
	t_tetrimino	*tet;
	t_coord		*coord;
	int			i;
	int			j;
	int			k;

	tet = ft_memalloc(sizeof(*tet));
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
				tet->coord[k++] = coord;
			}
			j++;
		}
		i++;
	}
}

t_list	*handle_file(char *path)
{
	int			fd;
	int			ret;
	char		**lines;
	t_list		*tetlist;

	fd = open(path, O_RDONLY);

	tetlist = NULL;
	while (1)
	{
		ret = ft_get_lines(fd, &lines, 4);
		ft_assert(ret == 4); 
		if (check_tet(lines))
		{
			push(tetlist, lines);
		}
	}
	return (tetlist);
}

