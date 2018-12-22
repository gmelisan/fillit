#include "fillit.h"


t_tet		*newtet(int width, int height)
{
	t_tet	*t;

	t = (t_tet*)ft_memalloc(sizeof(*t));
	if (t)
	{
		t->width = width;
		t->height = height;
	}
	return (t);
}

int 		main(void)
{
	t_tet 	*t;
	int		mapsize;
	t_coord	c;
	t_coord	coord[4];

	// ##
	//  #
	//  #
	t = newtet( 2, 3);
	c.x = 0;
	c.y = 0;
	t->coord[0] = c;
	c.x = 1;
	c.y = 0;
	t->coord[1] = c;
	c.x = 1;
	c.y = 1;
	t->coord[2] = c;
	c.x = 1;
	c.y = 2;
	t->coord[3] = c;

	// ##
	// ##
	t->next = newtet(2, 2);
	c.x = 0;
	c.y = 0;
	t->next->coord[0] = c;
	c.x = 0;
	c.y = 1;
	t->next->coord[1] = c;
	c.x = 1;
	c.y = 0;
	t->next->coord[2] = c;
	c.x = 1;
	c.y = 1;
	t->next->coord[3] = c;

	// ##
	//  #
	//  #
	t->next->next = newtet( 2, 3);
	c.x = 0;
	c.y = 0;
	t->next->next->coord[0] = c;
	c.x = 1;
	c.y = 0;
	t->next->next->coord[1] = c;
	c.x = 1;
	c.y = 1;
	t->next->next->coord[2] = c;
	c.x = 1;
	c.y = 2;
	t->next->next->coord[3] = c;


	mapsize = fillit(t);
	display_solution(t, mapsize);

	return (0);
}
