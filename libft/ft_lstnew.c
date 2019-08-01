/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconwy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 19:44:17 by bconwy            #+#    #+#             */
/*   Updated: 2018/12/23 19:44:20 by bconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ret;

	ret = ft_memalloc(sizeof(t_list));
	if (ret)
	{
		if (content)
		{
			ret->content = ft_memalloc(content_size);
			if (ret->content)
			{
				content = ft_memcpy(ret->content, content, content_size);
				ret->content_size = content_size;
			}
			else
				ret->content_size = 0;
		}
		else
		{
			ret->content = NULL;
			content_size = 0;
		}
		ret->next = NULL;
	}
	return (ret);
}
