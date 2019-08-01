/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconwy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 20:52:12 by bconwy            #+#    #+#             */
/*   Updated: 2018/12/23 20:52:13 by bconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*chres;

	i = 0;
	if (s)
	{
		chres = ft_strnew(len);
		if (chres)
		{
			while (i < len)
			{
				chres[i] = s[i + start];
				i++;
			}
			return (chres);
		}
	}
	return (NULL);
}
