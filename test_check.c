/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:34:00 by gmelisan          #+#    #+#             */
/*   Updated: 2018/12/24 00:40:24 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	show_list(t_tet *tet)
{
	int i, k;

	k = 0;
	while (tet)
	{
		printf("Tet: %d\n", k);
		printf("\twidth: %d\n", tet->width);
		printf("\theight: %d\n", tet->height);
		for (i = 0; i < 4; i++)
			printf("\tcoord[%d]: %d, %d\n", i, tet->coord[i].x, tet->coord[i].y);
		printf("\tabs_coord:: %d, %d\n", tet->abs_coord.x, tet->abs_coord.y);
		tet = tet->next;
		k++;
	}
}

int		main(int argc, char **argv)
{
	t_tet	*tet;

	if (argc != 2)
	{
		display_usage();
		return (0);
	}
	tet = handle_file(argv[1]);
	show_list(tet);
	del_tets(&tet);
	return (0);
}
