/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 11:36:30 by mrolfe            #+#    #+#             */
/*   Updated: 2019/09/02 12:54:13 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_plist		*algorithm(t_room *start, t_room *finish, t_room *arr)
{
	t_path	*path;
	t_plist	*plist;
	int		index;
	t_plist	*first;

	plist = NULL;
	index = 0;
	path = NULL;
	first = NULL;
	while (cutting_path(start, finish, first, &index))
	{
		while (width_search(start, finish, &path, 1))
		{
			clean_values(arr);
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

int			cutting_path(t_room *start, t_room *finish, t_plist *first,
							int *index)
{
	t_plist	*tmp;
	t_path	*new;

	new = NULL;
	tmp = first;
	if (first)
	{
		unblock_rooms(tmp);
		block_direction(tmp, start);
		while (tmp->next)
			tmp = tmp->next;
		if (!width_search(start, finish, &new, 1))
			return (0);
		make_path_list(tmp, new);
		if (!both_directions(tmp->next, start))
		{
			free_path(first);
			return (0);
		}
		cutting_path2(start, finish, first);
		*index = 0;
	}
	return (1);
}

int			cutting_path2(t_room *start, t_room *finish, t_plist *first)
{
	unblock_direction(first, start);
	if (!width_search(start, finish, NULL, 0))
	{
		free_path(first);
		return (0);
	}
	free_pathlist((first)->path, first);
	return (1);
}

int			both_directions(t_plist *plist, t_room *start)
{
	t_path	*tmp;
	t_room	*tmp2;
	t_plist	*tmp3;
	int		count;

	tmp3 = plist;
	count = 0;
	tmp2 = start;
	while (tmp3)
	{
		tmp = tmp3->path;
		while (tmp)
		{
			if (find_room3(tmp, tmp2))
				count++;
			if (count == 10)
				return (1);
			tmp2 = tmp->room;
			tmp = tmp->next;
		}
		tmp3 = tmp3->next;
	}
	if (count)
		return (1);
	return (0);
}
