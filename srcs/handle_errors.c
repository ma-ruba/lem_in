/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:44:00 by mrolfe            #+#    #+#             */
/*   Updated: 2019/08/28 14:46:51 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	malloc_error(void)
{
	ft_printf("malloc error\n");
	exit(1);
}

void	map_error(t_room *room, t_data *str)
{
	write(1, "ERROR\n", 6);
	free_neighb_list(room, str);
	exit(1);
}
