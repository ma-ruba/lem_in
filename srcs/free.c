#include "lem_in.h"

void		free_pathlist(t_path *path, t_plist *plist) //норма
{
	t_path	*tmp;
	t_plist	*tmp2;

	while (plist)
	{
		tmp2 = plist;
		while (path)
		{
			tmp = path;
			path = path->next;
			free (tmp);
		}
		plist = plist->next;
		free (tmp2);
	}
}

void		free_path(t_plist *plist) //норма
{
	t_plist	*tmp;
	t_path	*tmp2;
	t_path	*path;

	tmp = plist;
	while (tmp->next->next)
		tmp = tmp->next;
	path = tmp->next->path;
	while (path)
	{
		tmp2 = path;
		path = path->next;
		free (tmp2);
	}
	free (tmp->next);
	tmp->next = NULL;
}

void		free_neighb_list(t_room *room) //норма
{
	int		i;
	t_nlist	*tmp;
	t_nlist	*tmp2;

	i = 0;
	while (i < room_nb)
	{
		tmp = room[i++]->neighb;
		while (tmp)
		{
			tmp2 = tmp;
			tmp = tmp->next;
			free (tmp2);
		}
	}
	free (room);
}
