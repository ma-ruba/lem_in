/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconwy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 20:53:28 by bconwy            #+#    #+#             */
/*   Updated: 2018/12/23 20:53:33 by bconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*ft_blank(char const *s, int *i, int *len)
{
	char	*chstr;

	while (s[*i] && (s[*i] == ' ' || s[*i] == '\n' || s[*i] == '\t'))
		(*i)++;
	if (!s[*i])
	{
		chstr = ft_strnew(0);
		return (chstr);
	}
	while (s[*len] && (s[*len] == ' ' || s[*len] == '\n' || s[*len] == '\t'))
		(*len)--;
	chstr = ft_strnew(*len - *i + 1);
	return (chstr);
}

char		*ft_strtrim(char const *s)
{
	char	*chstr;
	int		j;
	int		i;
	int		len;

	j = 0;
	i = 0;
	if (s)
	{
		len = ft_strlen(s) - 1;
		chstr = ft_blank(s, &i, &len);
		if (chstr)
		{
			while (i <= len)
			{
				chstr[j] = s[i];
				j++;
				i++;
			}
			chstr[j] = '\0';
			return (chstr);
		}
	}
	return (NULL);
}
