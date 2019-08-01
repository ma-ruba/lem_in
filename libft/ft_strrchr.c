/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconwy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:47:10 by bconwy            #+#    #+#             */
/*   Updated: 2018/11/30 17:47:13 by bconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int		i;
	char	*tmp;
	int		buf;

	buf = -1;
	i = 0;
	tmp = (char *)str;
	if (ch == '\0')
	{
		while (tmp[i])
			i++;
		return (&tmp[i]);
	}
	while (tmp[i])
	{
		while (tmp[i] != ch && tmp[i])
			i++;
		if (tmp[i])
			buf = i++;
	}
	if (buf == -1)
		return (NULL);
	else if (buf != -1)
		return (&tmp[buf]);
	return (NULL);
}
