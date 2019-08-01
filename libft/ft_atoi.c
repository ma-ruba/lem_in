/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconwy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:57:13 by bconwy            #+#    #+#             */
/*   Updated: 2018/11/30 17:57:16 by bconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_atoi(const char *str1)
{
	int			negative;
	long long	nb;
	char		*str;
	int			i;

	negative = 0;
	nb = 0;
	str = (char *)str1;
	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' || str[i] == ' '
	|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		negative = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		if (nb < 0)
			return (negative ? 0 : -1);
		i++;
	}
	return (negative == 1 ? -nb : nb);
}
