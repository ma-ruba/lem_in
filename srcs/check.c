/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:44:00 by mrolfe            #+#    #+#             */
/*   Updated: 2019/09/02 12:52:58 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			checking_data(t_data *str, t_room *room)
{
	if (str->amount_of_ants > 0 && str->start && str->end &&
			g_index_for_rc == 1)
		return (1);
	else
		map_error(room, str);
	return (0);
}

void		checking_duplicates(t_room *room, char *room_name, t_data *str)
{
	int i;
	int res;

	i = 0;
	while (i < g_room_nb + 1)
	{
		res = ft_strequ(room[i].name, room_name);
		if (res)
			map_error(room, str);
		i++;
	}
}

void		check(char *line, t_data *str, t_room *room, int *index)
{
	int i;

	i = 2;
	if (line[0] == '#')
		check2(line, str, room);
	else if (checking_dash(line))
	{
		ft_printf("%s\n", line);
		if (*index == 0)
			sorting_rooms(room, 0, g_room_nb - 1, str);
		*index = 1;
		room_connections(room, line, str);
		free(line);
		line = NULL;
	}
	else
	{
		check_room(&line, room, str);
		ft_printf("%s\n", line);
		other_rooms(line, room, str);
	}
}

void		check2(char *line, t_data *str, t_room *room)
{
	if (ft_strequ(line, "##start"))
		read_start(line, str, room);
	else if (ft_strequ(line, "##end"))
		read_end(line, str, room);
	else
	{
		ft_printf("%s\n", line);
		free(line);
		line = NULL;
		return ;
	}
}

int			check_ants(char **line)
{
	int i;

	i = 0;
	if (!get_next_line(0, line))
		return (0);
	ft_printf("%s\n", *line);
	if ((line[0][0] == '#' && line[0][1] == '#') || (line[0][0] == '#' &&
			line[0][1] != '#'))
	{
		if (ft_strequ(*line, "##start") || ft_strequ(*line, "##end"))
			return (0);
		else
		{
			free(*line);
			get_next_line(0, line);
		}
	}
	while (line[0][i])
	{
		if (!(line[0][i] >= '0' && line[0][i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}
