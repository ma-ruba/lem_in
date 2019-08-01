/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconwy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 20:32:03 by bconwy            #+#    #+#             */
/*   Updated: 2018/12/23 20:32:07 by bconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*chmap;
	size_t	i;

	i = 0;
	if (s && f)
	{
		chmap = ft_strnew(ft_strlen(s));
		if (chmap)
		{
			while (s[i])
			{
				chmap[i] = f(s[i]);
				i++;
			}
			chmap[i] = '\0';
			return (chmap);
		}
	}
	return (NULL);
}
