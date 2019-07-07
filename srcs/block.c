/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:44:00 by mrolfe            #+#    #+#             */
/*   Updated: 2019/07/01 14:48:30 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		block_direction(t_plist *plist, t_room *start)
{
	t_path	*tmp;
	t_plist	*tmp2;
	t_room	*current;

	tmp2 = plist;
	current = start;
	while (tmp2)
	{
		tmp = tmp2->path;
		while (tmp)
		{
			find_room2(tmp, current);
			current = tmp->room;
			tmp = tmp->next;
		}
		tmp2 = tmp2->next;
	}
}

void		unblock_direction()
{

}

void		find_room2(t_path *path, t_room *room)
{
	t_list	*tmp;

	tmp = room->neigb;
	while (tmp)
	{
		if (ft_strcmp(tmp->room->name, path->room->name))
			tmp->status = BLOCKED;
		tmp = tmp->next;
	}
}

int		find_room3(t_path *path, t_room *room)
{
	t_list	*tmp;
	int		count;

	count = 0;
	tmp = path->room->neigb;
	while (tmp)
	{
		if (ft_strcmp(tmp->room->name, room->name))
		{
			tmp->status = DELETED;
			count++;
		}
		tmp = tmp->next;
	}
	if (count != 0)
		return (1);
	return (0);
}

void		unblock_rooms(t_plist *plist)
{
	t_plist	*tmp;
	t_path	*tmp2;

	tmp =  plist;
	while (tmp)
	{
		tmp2 = tmp->path;
		while (tmp2)
		{
			tmp2->room->status = OPENED;
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}
