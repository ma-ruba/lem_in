/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_data2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 11:37:25 by mrolfe            #+#    #+#             */
/*   Updated: 2019/09/02 13:36:23 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	check_start_finish(t_room *room1, t_room *room2, t_data *str)
{
	if (ft_strequ(room1->name, str->start))
		str->start_room = room1;
	else if (ft_strequ(room2->name, str->start))
		str->start_room = room2;
	if (ft_strequ(room1->name, str->end))
		str->end_room = room1;
	else if (ft_strequ(room2->name, str->end))
		str->end_room = room2;
}

static int	partition(t_room *room, int low, int high, t_data *str)
{
	t_room	pivot;
	int		i;
	int		j;

	i = (low - 1);
	pivot = room[high];
	j = low;
	while (j <= high - 1)
	{
		if (ft_strcmp(room[j].name, pivot.name) <= 0)
		{
			i++;
			ft_uniswap(&room[i], &room[j], sizeof(t_room));
			check_start_finish(&room[i], &room[j], str);
		}
		j++;
	}
	ft_uniswap(&room[i + 1], &room[high], sizeof(t_room));
	check_start_finish(&room[i + 1], &room[high], str);
	return (i + 1);
}

void		sorting_rooms(t_room *room, int low, int high, t_data *str)
{
	int pi;

	if (low < high)
	{
		pi = partition(room, low, high, str);
		sorting_rooms(room, low, pi - 1, str);
		sorting_rooms(room, pi + 1, high, str);
	}
}

int			checking_dash(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

void		other_rooms(char *line, t_room *room, t_data *str)
{
	int	i;

	i = 0;
	while (line[i] != ' ')
		i++;
	line[i] = '\0';
	checking_duplicates(room, line, str);
	room[g_room_nb].name = ft_strdup(line);
	room[g_room_nb].value = NOT_GIVEN;
	room[g_room_nb].status = OPENED;
	room[g_room_nb].is_ant_inside = 0;
	g_room_nb++;
	free(line);
	line = NULL;
}
