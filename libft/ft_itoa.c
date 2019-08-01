/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconwy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 19:06:03 by bconwy            #+#    #+#             */
/*   Updated: 2018/12/23 19:06:24 by bconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_swap(char *a, char *b)
{
	char	c;

	c = *a;
	*a = *b;
	*b = c;
}

static size_t	ft_size(int n)
{
	int		unsig_n;
	size_t	size;

	size = 0;
	if (n == -2147483648)
	{
		return (11);
	}
	if (n < 0)
		size++;
	unsig_n = ABS(n);
	while (unsig_n > 9)
	{
		unsig_n /= 10;
		size++;
	}
	size++;
	return (size);
}

static void		real(char *chstr, int n, int *i)
{
	int	unsig_n;

	unsig_n = ABS(n);
	while (unsig_n > 9)
	{
		chstr[(*i)++] = (unsig_n % 10) + '0';
		unsig_n = unsig_n / 10;
	}
	chstr[(*i)++] = unsig_n + '0';
	chstr[*i] = '\0';
}

static void		ft_realization(char *chstr, int n, int i, int j)
{
	real(chstr, n, &i);
	if (n < 0)
	{
		while (j <= i / 2)
		{
			ft_swap(&chstr[j], &chstr[i - j]);
			j++;
		}
	}
	else
	{
		while (j < i / 2)
		{
			ft_swap(&chstr[j], &chstr[i - 1 - j]);
			j++;
		}
	}
}

char			*ft_itoa(int n)
{
	char	*chstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	chstr = ft_strnew(ft_size(n));
	if (chstr)
	{
		if (n == -2147483648)
		{
			ft_strcpy(chstr, "-2147483648");
			return (chstr);
		}
		else
		{
			if (n < 0)
			{
				chstr[i++] = '-';
				j++;
			}
			ft_realization(chstr, n, i, j);
		}
	}
	return (chstr);
}
