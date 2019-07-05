#include "lem_in.h"

void    	algorithm(t_room *start, t_room *finish)
{
	t_path	*path;

	path = NULL;
	while (deapth_search(start, finish, path))
	{
		make_path(path, )
	}
}



void		cutting_path()
{

}

int			deapth_search(t_room *start, t_room *finish, t_path *path)
{
	// Возможно path должно быть **
	int		path_len;
	int		val;
	t_list	*current;

	val = finish->value;
	current = finish->neigb;
	path_len = finish->value;
	start->value = 0;
	if (!give_values(start, finish, 1))
		return (0);
	while (val != 0)
	{
		while (current->status != val - 1)
			current = current->next;
		path = make_path(path, current->room, 1);
		current = current->room->neigb;
	}
	return (1);
}

t_path		*make_path(t_path *prev, t_room *current, int index)
{
	t_path	*path;

	path = (t_path*)malloc(sizeof(t_path));
	path->next = prev;
	path->room = current;
	if (index == 1)
		current->status = BLOCKED;
	return (path);
}

int			check_finish(t_room *finish, t_room *current)
{
	if (ft_strequ(finish->name, current->name))
		return (1);
	return (0);
}

int		give_values(t_room *start, t_room *finish, int cur_val)
{
	t_room		*queue;
	int			i;
	int			j;
	int			block;
	t_list		*tmp;

	i = 0;
	j = 0;
	block = 1;
	queue = make_struct_arr();
	tmp = start->neigb;
	queue[i++] = start;
	while (!check_finish(finish, queue[i - 1]) || queue[j] != NULL)
	{
		queue[j++] = NULL;
		while (tmp)
		{
			if (queue[i]->value == NOT_GIVEN && queue[i]->status == OPENED)
			{
				queue[i] = tmp->room;
				queue[i++]->value = cur_val;
			}
			tmp = tmp->next;
		}
		if (j == block || block == 1)
			cur_val++;
		if (j == block)
			block = i;
		tmp = queue[j]->neigb;
	}
	if (check_finish(finish, queue[i - 1]))
		return (1);
	return (0);
}
