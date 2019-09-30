/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_data3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:13:41 by mrolfe            #+#    #+#             */
/*   Updated: 2019/09/02 13:37:13 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	set_neighb(t_room *room)
{
	int		i;

	i = -1;
	while (++i < MAXV)
		room[i].neighb = NULL;
}

void		room_connections(t_room *room, char *line, t_data *str)
{
	int		i;
	t_room	*r;
	t_room	*r2;

	i = 0;
	while (line[i] != '-')
		i++;
	line[i] = '\0';
	r = find_room(line, room, str);
	make_neighb_list(room, &line[i + 1], r, str);
	r2 = find_room(&line[i + 1], room, str);
	make_neighb_list(room, &line[0], r2, str);
	g_index_for_rc = 1;
}

void		make_start(t_data *str, t_room *room, char *line)
{
	int		i;

	i = 0;
	while (line[i] != ' ')
		i++;
	line[i] = '\0';
	checking_duplicates(room, line, str);
	room[g_room_nb].name = ft_strdup(line);
	str->start = NULL;
	str->start = ft_strdup(line);
	room[g_room_nb].value = NOT_GIVEN;
	room[g_room_nb].neighb = NULL;
	room[g_room_nb].status = OPENED;
	room[g_room_nb].is_ant_inside = 0;
	str->start_room = &room[g_room_nb];
	free(line);
	line = NULL;
	g_room_nb++;
}

void		make_end(t_data *str, t_room *room, char *line)
{
	int		i;

	i = 0;
	while (line[i] != ' ')
		i++;
	line[i] = '\0';
	checking_duplicates(room, line, str);
	if (!(room[g_room_nb].name = ft_strdup(line)))
		malloc_error();
	str->end = NULL;
	str->end = ft_strdup(line);
	room[g_room_nb].value = NOT_GIVEN;
	room[g_room_nb].status = OPENED;
	room[g_room_nb].neighb = NULL;
	room[g_room_nb].is_ant_inside = 3;
	str->end_room = &room[g_room_nb];
	free(line);
	line = NULL;
	g_room_nb++;
}

t_room		*make_struct_arr(void)
{
	t_room	*room;

	if (!(room = (t_room*)ft_memalloc(sizeof(t_room) * MAXV)))
		malloc_error();
	set_neighb(room);
	return (room);
}
