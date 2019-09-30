/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 11:36:39 by mrolfe            #+#    #+#             */
/*   Updated: 2019/09/02 12:09:15 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_plist		*make_path_list(t_plist *prev, t_path *current)
{
	t_plist	*plist;

	plist = NULL;
	if (current)
	{
		if (!(plist = (t_plist*)ft_memalloc(sizeof(t_plist))))
			malloc_error();
		if (prev)
			prev->next = plist;
		plist->next = NULL;
		plist->path = current;
	}
	return (plist);
}

t_path		*make_path(t_path *prev, t_room *current, int index)
{
	t_path	*path;

	path = NULL;
	if (current)
	{
		if (!(path = (t_path*)ft_memalloc(sizeof(t_path))))
			malloc_error();
		path->next = prev;
		path->room = current;
		path->print_index = NOT_PRINTED;
		if (index == 1)
			current->status = BLOCKED;
		else
			current->status = OPENED;
	}
	return (path);
}

int			check_finish(t_room *finish, t_room *current)
{
	if (ft_strequ(finish->name, current->name))
		return (1);
	return (0);
}

void		clean_values(t_room *arr)
{
	int		i;

	i = 0;
	while (i < g_room_nb)
		arr[i++].value = NOT_GIVEN;
}

t_room		**make_queue(void)
{
	t_room	**room;
	int		i;

	i = 0;
	if (!(room = (t_room**)ft_memalloc(sizeof(t_room*) * (g_room_nb + 1))))
		malloc_error();
	while (i != g_room_nb + 1)
	{
		room[i] = NULL;
		i++;
	}
	return (room);
}
