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

void checking_data(t_data *str)
{
    if (str->amount_of_ants && str->start_room && str->end_room)
        return (1);
    else
    {
        write(1, "Error\n", 6);
        exit (1);
    }
}