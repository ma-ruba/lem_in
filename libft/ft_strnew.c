/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconwy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 20:37:50 by bconwy            #+#    #+#             */
/*   Updated: 2018/12/23 20:37:51 by bconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*chstr;
	size_t	i;

	i = 0;
	chstr = (char *)malloc(sizeof(char) * (size + 1));
	if (chstr)
	{
		while (i < size)
		{
			chstr[i] = 0;
			i++;
		}
		chstr[i] = '\0';
		return (chstr);
	}
	else
		return (NULL);
}
