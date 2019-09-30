/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 11:36:47 by mrolfe            #+#    #+#             */
/*   Updated: 2019/09/02 11:38:02 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_array	*creating_of_array(void)
{
	t_array	*pathes;

	pathes = (t_array*)ft_memalloc(sizeof(t_array) * 2);
	pathes[0].num_of_steps = 0;
	pathes[0].num_of_pathes = 0;
	pathes[1].num_of_steps = 0;
	pathes[1].num_of_pathes = 0;
	return (pathes);
}

int		number_of_pathes(t_data *read, t_plist *pointers, t_array *pathes)
{
	int		number_of_steps;
	int		sum_p;
	int		num_p;
	t_plist	*tmp;
	t_path	*tmp2;

	num_p = 1;
	sum_p = 0;
	tmp = pointers;
	while (tmp)
	{
		tmp2 = tmp->path;
		while (tmp2)
		{
			tmp2 = tmp2->next;
			sum_p += 1;
		}
		number_of_steps = (read->amount_of_ants + sum_p - 1) / num_p;
		tmp = tmp->next;
		comparing_of_values(pathes, number_of_steps, num_p++);
	}
	if (pathes[0].num_of_pathes != 0)
		return (pathes[0].num_of_pathes);
	else
		return (pathes[1].num_of_pathes);
}

void	comparing_of_values(t_array *pathes, int number_of_steps, int num_p)
{
	if (pathes[0].num_of_pathes == 0 && pathes[1].num_of_pathes == 0)
	{
		pathes[0].num_of_pathes = num_p;
		pathes[0].num_of_steps = number_of_steps;
		return ;
	}
	else if (pathes[0].num_of_pathes != 0 && pathes[1].num_of_pathes == 0)
	{
		pathes[1].num_of_pathes = num_p;
		pathes[1].num_of_steps = number_of_steps;
	}
	else if (pathes[0].num_of_pathes == 0 && pathes[1].num_of_pathes != 0)
	{
		pathes[0].num_of_pathes = num_p;
		pathes[0].num_of_steps = number_of_steps;
	}
	comparing_of_values2(pathes);
}

void	comparing_of_values2(t_array *pathes)
{
	if (pathes[0].num_of_steps > pathes[1].num_of_steps)
	{
		pathes[0].num_of_pathes = 0;
		pathes[0].num_of_steps = 0;
	}
	else
	{
		pathes[1].num_of_pathes = 0;
		pathes[1].num_of_steps = 0;
	}
}
