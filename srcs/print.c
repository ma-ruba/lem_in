/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:44:00 by mrolfe            #+#    #+#             */
/*   Updated: 2019/08/24 15:32:32 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void 		ants_going_through_graph(t_plist *pointers, int num_of_pathes, t_data *read) //норма
{
	int 	value_of_ants;
	int 	*array_num_ant;
	int		count;

	count = 1;
	array_num_ant = (int*)ft_memalloc(sizeof(int) * read->amount_of_ants);
	ft_arrset(array_num_ant, -1, read->amount_of_ants);
	value_of_ants = 0;
	read->l = read->amount_of_ants;
	read->end_room->is_ant_inside = 0;
	read->ants_in_the_end_room = 0;
	read->number_of_pathes = num_of_pathes;
	read->delta = (int*)ft_memalloc(sizeof(int) * num_of_pathes);
	while (read->ants_in_the_end_room != read->l)
	{
		if (read->amount_of_ants > 0)
			moving_ants(array_num_ant, read, &value_of_ants, pointers);
		ants_printing(pointers, &value_of_ants, array_num_ant, read);
		if (!value_of_ants)
			break ;
		ants_inside(pointers, num_of_pathes, read);
		count++;
	}
	printf("\n");
	printf("%i", count);
    free(array_num_ant);
	free(read->delta);
}

void		ants_inside(t_plist *pointers, int j, t_data *read)//норма
{
	t_plist *tmp;
	t_path	*tmp2;
	t_path	*save;

	i = 0;
	tmp = pointers;
	while (j--)
	{
		read->end_room->is_ant_inside = END;
		tmp2 = tmp->path;
		while (tmp2->next && tmp2->room->is_ant_inside == 0)
			tmp2 = tmp2->next;
		save = tmp2;
		while (tmp2->next && tmp2->room->is_ant_inside == 1)
			tmp2 = tmp2->next;
		if (!ft_strequ(tmp2->room->name, read->end_room->name))
			tmp2->room->is_ant_inside = 1;
		else
			(read->delta[i++])++;
		save->room->is_ant_inside = 0;
		tmp = tmp->next;
	}
}

void		moving_ants(int *array_num_ant, t_data *read, int *value_of_ants, t_plist *plist) //норма
{
	int 	j;
	t_plist	*tmp;

	tmp = plist;
	j = read->number_of_pathes;
	while (j && read->amount_of_ants)
	{
		tmp->path->room->is_ant_inside = 1;
		array_num_ant[--index1] = ++n_ant;
		(read->amount_of_ants)--;
		(*value_of_ants)++;
		j--;
		tmp = tmp->next;
	}
}
