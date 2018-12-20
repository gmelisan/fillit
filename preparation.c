/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:25:56 by gmelisan          #+#    #+#             */
/*   Updated: 2018/12/20 16:16:14 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
			return (0);
		}
		i++;
	}
	return (i);
}

t_list	*handle_file(char *path)
{
	int			fd;
	int			ret;
	t_list		*tetlist;

	fd = open(path, O_RDONLY);

	
	ret = ft_get_lines(fd, &lines, 4);

	return (NULL);
}
