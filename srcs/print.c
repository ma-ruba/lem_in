/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:44:00 by mrolfe            #+#    #+#             */
/*   Updated: 2019/07/01 14:48:30 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void ants_going_through_graph(t_plist *pointers, t_array *pathes, t_data *read) // нигде не плюсуются муравьи в конечной комнате
{
	int value_of_ants;
	int *array_num_ant;
	t_plist *tmp;
	t_path *tmp2;
	int		i;
	int		l;

	array_num_ant = malloc(sizeof(int) * read->amount_of_ants);
	ft_memset(array_num_ant, -1, read->amount_of_ants);
	ft_bzero(); // is_ant_inside
	tmp = pointers;
	l = read->amount_of_ants;
	read->ants_in_the_end_room = 0;
	while (read->ants_in_the_end_room != l)
	{
		if (read->amount_of_ants > 0)
			moving_ants(pathes, array_num_ant, read, &value_of_ants, pointers);
		ants_printing(pointers, &value_of_ants);
		i = pathes->num_of_pathes;
		while (i--)
		{
			tmp2 = tmp->path;
			while (tmp2->room->is_ant_inside == 1 && tmp2->next)
				tmp2 = tmp2->next;
			tmp->path->room->is_ant_inside = 0;
			if (tmp2->next)
				tmp2->room->is_ant_inside == 1;
			if (tmp->next)
				tmp = tmp->next;
		}
	}
}

void		moving_ants(t_array *pathes, int *array_num_ant, t_data *read, int *value_of_ants, t_plist *plist) //не помечаются в массиве муравьи пришедшие к финишу
{
	int 	j;
	t_plist	*tmp;

	tmp = plist;
	j = pathes->num_of_pathes;
	while (j && read->amount_of_ants)
	{
		plist->path->room->is_ant_inside = 1;
		array_num_ant[index--] = ++n_ant;
		(read->amount_of_ants)--;
		value_of_ants++;
		j--;
		if (tmp->next)
			tmp = tmp->next;
		if (tmp->path->next == NULL)
			(read->ants_in_the_end_room)++;
	}
}

void		ants_printing(t_plist *plist, int *value_of_ants, int *array_num_ant) // Проблемы с распечаткой. каждому муравью печатается не та комната
{
	int 	k;
	t_plist	*tmp;
	t_path	*tmp2;

	tmp = plist;
	while (*value_of_ants > 0)
	{
		tmp2 = tmp->path;
		write(1, "L", 1);
		while (array_num_ant[index3] == -1)
			index3++;
		k = index3;
		printf("%i", array_num_ant[k++]);
		write(1, "-", 1);
		while (tmp2->next->room->is_ant_inside != 0)
			tmp2 = tmp2->next;
		printf("%s", tmp2->room->name);
		tmp = tmp->next;
		if (*value_of_ants == 1)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
		(*value_of_ants)--;
	}
}
