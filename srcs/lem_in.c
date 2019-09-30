/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:27:53 by mrolfe            #+#    #+#             */
/*   Updated: 2019/09/02 12:53:19 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		clean_pathes(int nb_pathes, t_data *data, t_plist *path_list)
{
	t_plist	*tmp;
	int		count;

	count = 0;
	tmp = path_list;
	data->number_of_pathes = nb_pathes;
	while (tmp && (count++ < nb_pathes - 1))
		tmp = tmp->next;
	if (tmp->next)
	{
		free_pathlist(tmp->next->path, tmp->next);
		tmp->next = NULL;
	}
}

static int	check_start_end_connect(t_data *str)
{
	t_nlist	*tmp;

	tmp = str->start_room->neighb;
	while (tmp)
	{
		if (ft_strequ(tmp->room->name, str->end))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static void	call_alg(t_data *str, t_room *room)
{
	t_plist	*path_list;
	t_array	*arr;

	path_list = NULL;
	if (!(path_list = algorithm(str->start_room, str->end_room, room)))
		map_error(room, str);
	arr = creating_of_array();
	clean_pathes(number_of_pathes(str, path_list, arr), str,
		path_list);
	ants_going_through_graph(path_list, str->number_of_pathes, str);
	free(arr);
	free_pathlist(path_list->path, path_list);
}

int			main(void)
{
	t_data	str;
	char	*line;
	t_room	*room;

	g_room_nb = 0;
	g_index2 = 0;
	g_n_ant = 0;
	g_index_for_rc = 0;
	g_idx_for_start = 0;
	g_idx_for_end = 0;
	line = NULL;
	room = reading_data(&str, line);
	ft_printf("\n");
	if (checking_data(&str, room))
	{
		if (check_start_end_connect(&str))
			print_for_start_end(&str, room);
		else
			call_alg(&str, room);
	}
	free_neighb_list(room, &str);
	return (0);
}
