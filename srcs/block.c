/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:44:00 by mrolfe            #+#    #+#             */
/*   Updated: 2019/08/24 15:49:44 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		block_direction(t_plist *plist, t_room *start) //норма
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

void		unblock_direction(t_plist *plist, t_room *start) //норма
{
	t_path	*tmp;
	t_plist	*tmp2;
	t_nlist	*tmp3;

	tmp2 = plist;
	while (tmp2)
	{
		tmp = tmp2->path;
		while (tmp)
		{
			tmp3 = tmp->room->neighb;
			while (tmp3)
			{
				if (tmp3->status == BLOCKED)
					tmp3->status = OPENED;
				tmp3 = tmp3->next;
			}
			tmp = tmp->next;
		}
		tmp2 = tmp2->next;
	}
	unblock_start(start);
}

void		unblock_start(t_room *start)//норма
{
	t_nlist	*tmp3;

	tmp3 = start->neighb;
	while (tmp3)
	{
		if (tmp3->status == BLOCKED)
			tmp3->status = OPENED;
		tmp3 = tmp3->next;
	}
}

void		find_room2(t_path *path, t_room *room) //норма
{
	t_nlist	*tmp;

	tmp = room->neighb;
	while (tmp)
	{
		if (ft_strequ(tmp->room->name, path->room->name))
		{
			tmp->status = BLOCKED;
			return ;
		}
		tmp = tmp->next;
	}
}

int			find_room3(t_path *path, t_room *room) // не норма (+6 строк)
{
	t_nlist	*tmp;
	int		count;

	count = 0;
	tmp = path->room->neighb;
	while (tmp)
	{
		if (ft_strcmp(tmp->room->name, room->name))
		{
			if (tmp->status == BLOCKED)
			{
				tmp->status = DELETED;
				count++;
				tmp = room->neighb;
				while (tmp)
				{
					if (ft_strcmp(path->room->name, tmp->room->name))
					{
						tmp->status = DELETED;
						break ;
					}
					tmp = tmp->next;
				}
			}
			break ;
		}
		tmp = tmp->next;
	}
	if (count != 0)
		return (1);
	return (0);
}

void		unblock_rooms(t_plist *plist) // норма
{
	t_plist	*tmp;
	t_path	*tmp2;

	if (plist)
	{
		tmp =  plist;
		while (tmp)
		{
			tmp2 = tmp->path;
				while (tmp2 && tmp2->room)
				{
					tmp2->room->status = OPENED;
					tmp2 = tmp2->next;
				}
				tmp = tmp->next;
		}

	}
}
