/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 12:48:49 by mrolfe            #+#    #+#             */
/*   Updated: 2019/09/02 13:47:41 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	check_room4(t_room *room, t_data *str, char **line)
{
	free(*line);
	line = NULL;
	map_error(room, str);
}

int			check_room(char **line, t_room *room, t_data *str)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	j = 0;
	count = 0;
	check_room2(line, room, str);
	while (line[0][i] && line[0][i] != ' ')
		i++;
	while (line[0][i])
	{
		if (!((line[0][i] >= '0' && line[0][i] <= '9') || line[0][i] == ' '))
			check_room4(room, str, line);
		if (line[0][i] == ' ')
			count++;
		i++;
	}
	check_room3(line, room, str, count);
	if (line[0][i - 1] == ' ')
		check_room4(room, str, line);
	return (1);
}

void		check_room2(char **line, t_room *room, t_data *str)
{
	if (*line == NULL)
	{
		free(line);
		line = NULL;
		map_error(room, str);
	}
	if (line[0][0] == ' ' || line[0][0] == '\t')
	{
		free(*line);
		line = NULL;
		map_error(room, str);
	}
	if (line[0][0] == 'L' || line[0][0] == '#')
	{
		free(*line);
		line = NULL;
		map_error(room, str);
	}
}

void		check_room3(char **line, t_room *room, t_data *str, int count)
{
	if (count != 2)
	{
		free(*line);
		line = NULL;
		map_error(room, str);
	}
}
