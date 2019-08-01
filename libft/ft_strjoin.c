/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconwy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 20:06:47 by bconwy            #+#    #+#             */
/*   Updated: 2018/12/23 20:06:49 by bconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*chstr;
	size_t	i;

	i = 0;
	if (s1 && s2)
	{
		chstr = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (chstr)
		{
			while (s1[i])
			{
				chstr[i] = s1[i];
				i++;
			}
			while ((i - ft_strlen(s1)) < ft_strlen(s2))
			{
				chstr[i] = s2[i - ft_strlen(s1)];
				i++;
			}
			return (chstr);
		}
	}
	return (NULL);
}
