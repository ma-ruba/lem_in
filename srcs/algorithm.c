#include "lem_in.h"

void    	algorithm(t_room *start)
{
	while ()
	{

	}
}

void    	deapth_search(t_room *start, t_room *finish)
{
	int		path_len;

	path_len = finish->value;
	start->value = 0;
	give_values(start, finish, 1);
}

int			check_finish(t_room *finish, t_room *current)
{
	if (ft_strequ(finish->name, current->name))
		return (1);
	return (0);
}

void		give_values(t_room *start, t_room *finish, int cur_val)
{
	t_room		*queue[MAXV];
	int			i;
	int			j;
	int			block;
	t_list		*tmp;

	i = 0;
	j = 0;
	block = 1;
	tmp = start->neigb;
	queue[i++] = start;
	while (!check_finish(finish, queue[i - 1]))
	{
		queue[j++] = NULL;
		while (tmp)
		{
			queue[i] = tmp->room;
			if (queue[i]->value == NOT_GIVEN)
				queue[i]->value = cur_val;
			i++;
			tmp = tmp->next;
		}
		if (j == block || block == 1)
			cur_val++;
		if (j == block)
			block = i;
		tmp = queue[j]->neigb;
	}
}
