/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconwy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:39:43 by bconwy            #+#    #+#             */
/*   Updated: 2018/11/28 17:39:46 by bconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	size_t			i;
	unsigned char	*str_arr1;
	unsigned char	*str_arr2;

	i = 0;
	str_arr1 = (unsigned char *)arr1;
	str_arr2 = (unsigned char *)arr2;
	while (i < n)
	{
		if (str_arr1[i] != str_arr2[i])
			return (str_arr1[i] - str_arr2[i]);
		i++;
	}
	return (0);
}
