/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconwy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:56:18 by bconwy            #+#    #+#             */
/*   Updated: 2018/11/30 17:56:20 by bconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strdif(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

char		*ft_strstr(const char *str1, const char *str2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (str1 == str2)
		return ((char *)str1);
	while (str1[i])
	{
		if (ft_strdif((char *)&str1[i], (char *)str2) == 0)
			return ((char *)&str1[i]);
		i++;
	}
	return (NULL);
}
