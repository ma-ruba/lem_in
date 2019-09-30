/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:04:48 by mrolfe            #+#    #+#             */
/*   Updated: 2019/09/02 13:04:50 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_llonglen(long long num, int base)
{
	size_t	i;

	i = 0;
	if (num == 0)
		return (i = 1);
	while (num)
	{
		i++;
		num /= base;
	}
	return (i);
}

char			*ft_itoa_base(long long num, int base)
{
	char		*str;
	size_t		digits;
	long long	n;

	n = num;
	if (num == -9223372036854775807 - 1)
		return (str = ft_strdup("-9223372036854775808"));
	digits = ft_llonglen(num, base);
	if (num < 0)
		digits++;
	if (!(str = ft_strnew(digits)))
		return (NULL);
	if (num < 0)
		n *= -1;
	while (digits-- > 0)
	{
		if (num < 0 && digits == 0)
			str[digits] = '-';
		else if (n % base < 10)
			str[digits] = n % base + '0';
		else
			str[digits] = n % base + 87;
		n /= base;
	}
	return (str);
}
