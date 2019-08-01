/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconwy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:43:21 by bconwy            #+#    #+#             */
/*   Updated: 2018/11/28 19:43:23 by bconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	dest += dest_len;
	dest_len = dest_len > size ? size : dest_len;
	size -= dest_len;
	while (size-- > 1 && *src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest_len + src_len);
}
