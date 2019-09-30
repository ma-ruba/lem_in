/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 12:57:22 by mrolfe            #+#    #+#             */
/*   Updated: 2019/09/02 12:57:23 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newl;

	if (!(newl = (t_list *)malloc(sizeof(*newl))))
		return (NULL);
	if (content == NULL)
	{
		newl->content = NULL;
		newl->content_size = 0;
	}
	else
	{
		if (!(newl->content = ft_memalloc(content_size)))
		{
			free(newl);
			return (NULL);
		}
		ft_memcpy(newl->content, content, content_size);
		newl->content_size = content_size;
	}
	newl->next = NULL;
	return (newl);
}
