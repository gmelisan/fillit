/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemmeric <kemmeric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 12:34:58 by gmelisan          #+#    #+#             */
/*   Updated: 2018/12/20 20:17:33 by kemmeric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	lstdel_callback(void *content, size_t content_size)
{
	ft_memdel(&content);
	content_size = 0;
}

int		main(int argc, char **argv)
{
	t_list	*tetlist;
	int		n;

	if (argc != 2)
	{
		display_usage();
		return (0);
	}
	tetlist = handle_file(argv[1]);
	ft_assert(tetlist != NULL);
	n = fillit(tetlist);
	display_solution(tetlist, n);
	ft_lstdel(&tetlist, &lstdel_callback);
	return (0);
}
