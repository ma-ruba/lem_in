/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_data1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 11:37:18 by mrolfe            #+#    #+#             */
/*   Updated: 2019/09/02 13:31:03 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		read_start(char *line, t_data *str, t_room *room)
{
	if (!g_idx_for_start)
	{
		ft_printf("%s\n", line);
		free(line);
		if (!get_next_line(0, &line))
		{
			free(line);
			map_error(room, str);
		}
		while (line[0] == '#')
		{
			free(line);
			get_next_line(0, &line);
		}
		check_room(&line, room, str);
		ft_printf("%s\n", line);
		make_start(str, room, line);
		g_idx_for_start = 1;
	}
	else
		free(line);
}

void		read_end(char *line, t_data *str, t_room *room)
{
	if (!g_idx_for_end)
	{
		ft_printf("%s\n", line);
		free(line);
		if (!get_next_line(0, &line))
		{
			free(line);
			map_error(room, str);
		}
		while (line[0] == '#')
		{
			free(line);
			get_next_line(0, &line);
		}
		check_room(&line, room, str);
		ft_printf("%s\n", line);
		make_end(str, room, line);
		g_idx_for_end = 1;
	}
	else
		free(line);
}

t_room		*reading_data(t_data *str, char *line)
{
	t_room	*room;
	int		index;

	index = 0;
	room = make_struct_arr();
	if (!check_ants(&line))
	{
		free(line);
		line = NULL;
		map_error(room, str);
	}
	str->amount_of_ants = ft_atoi(line);
	free(line);
	line = NULL;
	g_index1 = str->amount_of_ants;
	g_index3 = str->amount_of_ants - 1;
	while (get_next_line(0, &line))
		check(line, str, room, &index);
	return (room);
}

void		make_neighb_list(t_room *rooms, char *line, t_room *room,
				t_data *str)
{
	t_nlist *new;
	t_nlist *temp;

	if (!(new = (t_nlist*)ft_memalloc(sizeof(t_nlist))))
		malloc_error();
	temp = room->neighb;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		new->room = find_room(line, rooms, str);
		new->status = OPENED;
		new->next = NULL;
	}
	else
	{
		room->neighb = new;
		new->room = find_room(line, rooms, str);
		new->status = OPENED;
		new->next = NULL;
	}
}
