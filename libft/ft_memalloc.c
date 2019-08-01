/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconwy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 19:45:12 by bconwy            #+#    #+#             */
/*   Updated: 2018/12/23 19:45:15 by bconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	mem = (char *)malloc(sizeof(mem) * size);
	if (mem)
	{
		while (i < size)
		{
			mem[i] = 0;
			i++;
		}
		return ((void *)mem);
	}
	else
		return (NULL);
}
