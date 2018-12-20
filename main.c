/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 12:34:58 by gmelisan          #+#    #+#             */
/*   Updated: 2018/12/20 17:05:40 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	return (0);
}
