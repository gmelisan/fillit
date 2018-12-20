/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:25:56 by gmelisan          #+#    #+#             */
/*   Updated: 2018/12/20 17:06:32 by gmelisan         ###   ########.fr       */
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
	*lines = ft_memalloc(sizeof(*lines) * (n + 1));
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
			ft_lstaddback(&tetlist, ft_lstnew(NULL, 0));
			
		}
	}
	return (NULL);
}
