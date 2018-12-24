/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemmeric <kemmeric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 12:34:58 by gmelisan          #+#    #+#             */
/*   Updated: 2018/12/24 16:18:20 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				main(int argc, char **argv)
{
	t_tet	*tet;
	int		n;

	if (argc != 2)
	{
		display_usage();
		return (0);
	}
	tet = handle_file(argv[1]);
	n = fillit(tet);
	display_solution(tet, n);
	del_tets(&tet);
	return (0);
}
