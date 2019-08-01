/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconwy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 20:32:22 by bconwy            #+#    #+#             */
/*   Updated: 2018/12/23 20:32:25 by bconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
				chmap[i] = f(i, s[i]);
				i++;
			}
			chmap[i] = '\0';
			return (chmap);
		}
	}
	return (NULL);
}
