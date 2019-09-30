/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:35:51 by mrolfe            #+#    #+#             */
/*   Updated: 2019/09/02 13:37:08 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*find_room(char *buff, t_room *room, t_data *str)
{
	int start;
	int end;
	int middle;
	int	res;

	start = 0;
	end = g_room_nb - 1;
	while (start <= end)
	{
		middle = (start + end) / 2;
		res = ft_strcmp(room[middle].name, buff);
		if (res > 0)
			end = middle - 1;
		else if (res < 0)
			start = middle + 1;
		else
			return (&room[middle]);
	}
	map_error(room, str);
	return (NULL);
}

void		find_room2(t_path *path, t_room *room)
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

int			find_room3(t_path *path, t_room *room)
{
	t_nlist	*tmp;

	tmp = path->room->neighb;
	while (tmp)
	{
		if (ft_strcmp(tmp->room->name, room->name))
		{
			if (tmp->status == BLOCKED)
			{
				tmp->status = DELETED;
				tmp = room->neighb;
				while (tmp)
				{
					if (ft_strcmp(path->room->name, tmp->room->name))
					{
						tmp->status = DELETED;
						return (1);
					}
					tmp = tmp->next;
				}
			}
		}
		tmp = tmp->next;
	}
	return (0);
}
