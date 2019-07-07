#include "lem_in.h"

t_plist    	*algorithm(t_room *start, t_room *finish)
{
	t_path	*path;
	t_plist	*plist;
	int		index;
	t_plist	*first;

	plist = NULL;
	index = 0;
	while (cutting_path(start, finish))
	{
		while (deapth_search(start, finish, path))
		{
			plist = make_path_list(plist, path);
			if (index == 0)
			{
				first = plist;
				index = 1;
			}
		}
	}
	return (first);
}

t_plist		*make_path_list(t_plist *prev, t_path *current)
{
	t_plist	*plist;

	plist = (t_plist*)malloc(sizeof(t_plist));
	if (prev)
		prev->next = plist;
	plist->next = NULL;
	plist->path = current;
	return (plist);
}

int			cutting_path(t_room *start, t_room *finish, t_plist *plist)
{
	t_plist	*tmp;

	tmp = plist;
	if (plist)
	{
		unblock_rooms(plist);
		block_direction(plist, start);
		while (tmp->next)
			tmp = tmp->next;
		deapth_search(start, finish, tmp);
		if (!both_directions(tmp))
			return (0);
	}
	return (1);
}

int			both_directions(t_plist *plist, t_room *start)
{
	t_path	*tmp;
	t_room	*tmp2;
	int		count;

	count = 0;
	tmp = plist->path;
	tmp2 = start;
	while (tmp)
	{
		if (find_room3(tmp, tmp2))
			count++;
		tmp2 = tmp->room;
		tmp = tmp->next;
	}
	if (count != 0)
		return (1);
	return (0);
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
		path = make_path(path, current->room);
		current = current->room->neigb;
	}
	return (1);
}

t_path		*make_path(t_path *prev, t_room *current)
{
	t_path	*path;

	path = (t_path*)malloc(sizeof(t_path));
	path->next = prev;
	path->room = current;
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
			if (queue[i]->value == NOT_GIVEN && queue[i]->status == OPENED && tmp->status == OPENED)
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
