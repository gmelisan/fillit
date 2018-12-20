/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 12:34:58 by gmelisan          #+#    #+#             */
/*   Updated: 2018/12/20 15:46:50 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_list	*tetlist;
	char	**solution;

	if (argc != 2)
	{
		display_usage();
		return (0);
	}
	tetlist = handle_file(argv[1]);
	ft_assert(tetlist != NULL);
	solution = fillit(tetlist);
	ft_assert(solution != NULL);
	display_solution(solution);
	return (0);
}
