/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 12:57:15 by mrolfe            #+#    #+#             */
/*   Updated: 2019/09/02 12:57:17 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew_ptr(void const *content)
{
	t_list	*newl;

	if (!(newl = (t_list *)ft_memalloc(sizeof(*newl))))
		return (NULL);
	if (content == NULL)
	{
		newl->content = NULL;
		newl->content_size = 0;
	}
	else
	{
		newl->content = (void*)content;
		newl->content_size = sizeof(void*);
	}
	newl->next = NULL;
	return (newl);
}
