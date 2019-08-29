/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:27:53 by mrolfe            #+#    #+#             */
/*   Updated: 2019/08/26 18:34:28 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		clean_pathes(int nb_pathes, t_data *data, t_plist *path_list) //норма
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

int			main(int argc, char **argv)
{
	t_data	str;
	char	*line;
	t_plist	*path_list;
	t_room	*room;
	int		fd;//этого не будет
	t_array	*arr;

	line = NULL;
	room_nb = 0;
	index2 = 0;
	n_ant = 0;
	index_for_rc = 0;
 	idx_for_start = 0;
 	idx_for_end = 0;
	idx_for_make_plist = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			exit(1);
		room = reading_data(&str, line, fd);
		printf("\n");
		if (checking_data(&str))
		{
			if (!(path_list = algorithm(str.start_room, str.end_room, room)))
				map_error();
			arr = creating_of_array();
			clean_pathes(number_of_pathes(&str, path_list, arr), &str,
				path_list);
			ants_going_through_graph(path_list, str.number_of_pathes, &str);
			free(arr);
			free_pathlist(path_list->path, path_list);
		}
		free_neighb_list(room, &str);
	}
	return (0);
}

// int			main(void) //норма
// {
// 	t_data	str;
// 	char	*line;
// 	t_plist	*path_list;
// 	t_room	*room;
// 	int		fd;//этого не будет
// 	t_array	*arr;

// 	line = NULL;
// 	room_nb = 0;
// 	index2 = 0;
// 	n_ant = 0;
//     path_list = NULL;
// 	index_for_rc = 0;
// 	idx_for_start = 0;
// 	idx_for_end = 0;
// 	idx_for_make_plist = 0;
// 	// if (argc == 2)
// 	// {
// 		fd = 0;
// 		// if (fd == -1)
// 		// 	exit (1);
// 		room = reading_data(&str, line, fd);
// 		printf("\n");
// 		if (checking_data(&str))
// 		{
// 			if (!(path_list = algorithm(str.start_room, str.end_room, room)))
// 				map_error();
// 			arr = creating_of_array();
// 			clean_pathes(number_of_pathes(&str, path_list, arr), &str, path_list);
// 			ants_going_through_graph(path_list, str.number_of_pathes, &str);
// 			free(arr);
// 			free_pathlist(path_list->path, path_list);
// 		}
// 		free_neighb_list(room, &str);
// 	// }
// 	return (0);
// }

