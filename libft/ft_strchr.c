/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconwy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:43:45 by bconwy            #+#    #+#             */
/*   Updated: 2018/11/28 19:43:49 by bconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char *)str;
	if (ch == '\0')
	{
		while (tmp[i])
			i++;
		return (&tmp[i]);
	}
	while (tmp[i] != (char)ch && tmp[i])
		i++;
	if (!tmp[i])
		return (NULL);
	else if (tmp[i] == (char)ch)
		return (&tmp[i]);
	return (NULL);
}
