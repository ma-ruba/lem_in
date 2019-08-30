#include "lem_in.h"

t_plist    	*algorithm(t_room *start, t_room *finish, t_room *arr) //норма
{
	t_path	*path;
	t_plist	*plist;
	int		index;
	t_plist	*first;

	plist = NULL;
	index = 0;
	first = NULL;
	while (cutting_path(start, finish, &first, &index))
	{
		path = NULL;
		while (width_search(start, finish, &path))
		{ 
			clean_values(arr);
			plist = make_path_list(plist, path);
			//idx_for_make_plist = 1;
			if (index == 0)
			{
				first = plist;
				index = 1;
			}
		}
	}
	return (first);
}

int			cutting_path(t_room *start, t_room *finish, t_plist **first, int *index) //норма
{
	t_plist	*tmp;
	t_path	*new;
	
	new = NULL;
	tmp = *first;
	if (*first != NULL)
	{
		//return (0);
		//idx_for_make_plist = 0;
		unblock_rooms(tmp);
		block_direction(tmp, start);
		while (tmp->next)
			tmp = tmp->next;
		if (!width_search(start, finish, &new))
			return (0);
		make_path_list(tmp, new);
		if (!both_directions(tmp->next, start))
		{
			free_path(*first);
			return (0);
		}
		unblock_direction(*first, start);
		free_pathlist((*first)->path, *first);
		*index = 0;
		*first = NULL;
	}
	return (1);
}

int			both_directions(t_plist *plist, t_room *start) //норма
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

int			width_search(t_room *start, t_room *finish, t_path **path) //норма
{
	int		val;
	t_nlist	*current;

	current = finish->neighb;
	start->value = 0;
	if (!give_values(&start, finish, 1))
		return (0);
	*path = make_path(NULL, finish, 0);
	val = finish->value;
	while (val != 1)
	{
		while (current->room->value != val - 1)
			current = current->next;
		*path = make_path(*path, current->room, 1);
		current = current->room->neighb;
		val--;
	}
	return (1);
}

int			give_values(t_room **start, t_room *finish, int cur_val) //не норма (+12 строк)
{
	t_room	**queue; // спросить у папы
	int		i;
	int		j;
	int		block;
	t_nlist	*tmp;

	i = 0;
	j = 0;
	block = 1;
	queue = make_queue();
	tmp = (*start)->neighb;
	queue[i++] = *start;
	while (queue[j] != NULL)
	{
		queue[j++] = NULL;
		while (tmp)
		{
			if (tmp->room->value == NOT_GIVEN && tmp->room->status == OPENED && tmp->status == OPENED)
			{
				queue[i] = tmp->room;
				queue[i++]->value = cur_val;
				if (check_finish(finish, queue[i - 1]))
				{
					free (queue);
					return (1);
				}
			}
			tmp = tmp->next;
		}
		if (j == block || block == 1)
			cur_val++;
		if (j == block)
			block = i;
		if (queue[j])
			tmp = queue[j]->neighb;
	}
	free (queue);
	return (0);
}
