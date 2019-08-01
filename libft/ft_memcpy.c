/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconwy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:43:53 by bconwy            #+#    #+#             */
/*   Updated: 2018/11/27 17:43:57 by bconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t n)
{
	size_t			i;
	unsigned char	*str_dest;
	unsigned char	*str_source;

	str_dest = dest;
	str_source = (unsigned char *)source;
	i = 0;
	while (i < n)
	{
		str_dest[i] = str_source[i];
		i++;
	}
	return (dest);
}
