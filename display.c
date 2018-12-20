/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:17:36 by gmelisan          #+#    #+#             */
/*   Updated: 2018/12/20 15:47:04 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_assert(int exp)
{
	if (!exp)
	{
		ft_putendl("error");
		exit(0);
	}
}

void	display_usage(void)
{
	ft_putendl("usage: fillit FILE\n");
	ft_putendl("Takes FILE with list of Tetriminos, and arrange them");
	ft_putendl("in order to create the smallest square possible.");
}

void	display_solution(char **sol)
{
	int i;

	i = 0;
	while (sol[i])
		ft_putendl(sol[i++]);
}
