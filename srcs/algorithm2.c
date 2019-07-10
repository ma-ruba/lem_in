#include "lem_in.h"

t_plist		*make_path_list(t_plist *prev, t_path *current) //норма
{
	t_plist	*plist;

	plist = (t_plist*)malloc(sizeof(t_plist));
	if (prev)
		prev->next = plist;
	plist->next = NULL;
	plist->path = current;
	return (plist);
}

t_path		*make_path(t_path *prev, t_room *current) //норма
{
	t_path	*path;

	path = (t_path*)malloc(sizeof(t_path));
	path->next = prev;
	path->room = current;
	current->status = BLOCKED;
	return (path);
}

int			check_finish(t_room *finish, t_room *current) //норма
{
	if (ft_strequ(finish->name, current->name))
		return (1);
	return (0);
}

void		clean_values(t_room *arr)
{
	int		i;

	i = 0;
	while (i < room_nb)
		arr[i++]->value = NOT_GIVEN;
}

t_room		**make_queue()
{
	t_room	**room;
	int		i;

	i = 0;
	if (!(room = (t_room**)malloc(sizeof(t_room*) * (MAXV + 1))))
		return (NULL);
	while (i != MAXV + 1)
	{
		*room[i] = NULL;
		i++;
	}
	return (room);
}
