/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconwy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:56:50 by bconwy            #+#    #+#             */
/*   Updated: 2018/11/30 17:56:52 by bconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char*)s1;
	ss2 = (unsigned char*)s2;
	i = 0;
	while (ss1[i] == ss2[i] && ss2[i] != '\0' && ss1[i] != '\0')
		i++;
	if (ss1[i] == '\0' && ss2[i] != '\0')
		return ((-1) * ss2[i]);
	if (ss2[i] == '\0' && ss1[i] != '\0')
		return (ss1[i]);
	if (ss1[i] != '\0' && ss2[i] != '\0')
		return (ss1[i] - ss2[i]);
	return (0);
}
