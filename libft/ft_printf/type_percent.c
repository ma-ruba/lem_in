/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:03:01 by mrolfe            #+#    #+#             */
/*   Updated: 2019/09/02 13:03:03 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_type_percent(t_specs *specs)
{
	char *val;

	val = ft_strnew(1);
	val[0] = '%';
	if (specs->flags[zero] && !specs->flags[minus]
		&& specs->width > 1)
		val = filling_zero(val, specs->width - 1);
	print_value(specs, val, ft_strlen(val));
}
