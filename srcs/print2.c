/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:44:00 by mrolfe            #+#    #+#             */
/*   Updated: 2019/08/19 17:54:39 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	clear_print_index(t_plist *plist)//норма
{
	t_plist	*tmp;
	t_path	*tmp2;

	tmp = plist;
	while (tmp)
	{
		tmp2 = tmp->path;
		while (tmp2)
		{
			tmp2->print_index = NOT_PRINTED;
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

static void	clean_ants(int *array_num_ant, int nb_ant, int end_ant)//норма
{
	if (end_ant)
	{
		while (end_ant)
		{
			array_num_ant[nb_ant - 1] = -1;
			end_ant--;
			nb_ant--;
		}
	}
}

/*static void	print_arr(int *array_num_ant, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		printf("%i ", array_num_ant[i]);
	printf("\n");
}*/

void		ants_printing(t_plist *plist, int *ant_val, int *array_num_ant, t_data *read) //норма
{
	int 	k;
	t_plist	*tmp;
	int		value_of_ants;

	value_of_ants = *ant_val;
	while (array_num_ant[index3] == -1)
		index3--;
	k = index3;
	while (value_of_ants)
	{
		tmp = plist;
		i = 0;
		while (tmp && value_of_ants)
		{
			//print_arr(array_num_ant, read->l); //потом убрать
			printf("L%i-", array_num_ant[k--]);
			print_room(tmp, ant_val, read, array_num_ant);
			i++;
			tmp = tmp->next;
			if (value_of_ants-- == 1)
				printf("\n");
			else
				printf(" ");
		}
	}
	clear_print_index(plist);
}

void		print_room(t_plist *tmp, int *ant_val, t_data *read, int *array_num_ant)//норма
{
	t_path	*tmp2;

	tmp2 = tmp->path;
	if (read->delta[i])
	{
		(read->delta[i])--;
		printf("%s", read->end_room->name);
		(read->ants_in_the_end_room)++;
		(*ant_val)--;
		clean_ants(array_num_ant, read->l, read->ants_in_the_end_room);
		return ;
	}
	while (tmp2->next && tmp2->room->is_ant_inside == 0)
		tmp2 = tmp2->next;
	while (tmp2->next && tmp2->next->room->is_ant_inside == 1 && tmp2->next->print_index != PRINTED)
		tmp2 = tmp2->next;
	printf("%s", tmp2->room->name);
	tmp2->print_index = PRINTED;
}
