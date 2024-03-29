/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:06:47 by mrolfe            #+#    #+#             */
/*   Updated: 2019/09/02 13:06:49 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int i;
	int sqr;

	i = 1;
	sqr = 1;
	if (nb > 0)
	{
		while (sqr <= nb)
		{
			sqr = i * i;
			if (sqr == nb)
				return (i);
			i++;
		}
	}
	return (0);
}
