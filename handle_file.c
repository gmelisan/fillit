/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:25:56 by gmelisan          #+#    #+#             */
/*   Updated: 2018/12/24 16:18:21 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Invokes in read_tet().
*/

static int		check_str(char *str)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (str[i] != '.' && str[i] != '#')
			return (0);
		i++;
	}
	if (str[i] != '\n')
		return (0);
	str[i] = '\0';
	return (1);
}

/*
** Pre-check to have exactly 4 '#'. Need to not go out of
** coords[4] range while adding to list subroutine.
*/

static int		check_lines(char **lines)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (lines[i][j] == '#')
				k++;
			if (k > 4)
				return (0);
			j++;
		}
		i++;
	}
	return (k < 4 ? 0 : 1);
}

/*
** Reads 1 tetrimino. If lines are not 4-wide each,
** forbidden symbols exists then return NULL.
** If check fails, free previous lines.
*/

static char		**read_tet(int fd)
{
	char	**lines;
	int		ret;
	int		i;

	lines = (char **)ft_memalloc(sizeof(*lines) * 5);
	i = 0;
	while (i < 4)
	{
		lines[i] = (char *)ft_memalloc(sizeof(**lines) * 5);
		ret = read(fd, lines[i], 5);
		if (ret == -1 || !check_str(lines[i]))
		{
			while (i != -1)
				free(lines[i--]);
			free(lines);
			return (NULL);
		}
		i++;
	}
	return (lines);
}

/*
** Free list in case of error and exit.
*/

static void		ft_assert(int exp, t_tet **tet)
{
	if (!exp)
	{
		del_tets(tet);
		display_error();
		exit(0);
	}
}

/*
** Read 4 lines. Check. Add tetrimino to list.
** Read 1 line. Check for '\n' or EOF.
** Repeat.
*/

t_tet			*handle_file(char *path)
{
	int			fd;
	int			ret;
	char		**lines;
	char		endl;
	t_tet		*tet;

	fd = open(path, O_RDONLY);
	tet = NULL;
	while (1)
	{
		lines = read_tet(fd);
		ft_assert(lines != NULL && check_lines(lines), &tet);
		add_tet(&tet, lines);
		ret = read(fd, &endl, 1);
		if (ret == 0)
			break ;
		ft_assert(ret != -1 && endl == '\n', &tet);
	}
	ft_assert(check_tets(tet) != 0, &tet);
	return (tet);
}
