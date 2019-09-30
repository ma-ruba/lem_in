/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 12:57:07 by mrolfe            #+#    #+#             */
/*   Updated: 2019/09/02 12:57:09 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlist;
	t_list	*cont;
	t_list	*list;

	if (!lst || !*f)
		return (NULL);
	newlist = NULL;
	cont = f(lst);
	if ((newlist = ft_lstnew(cont->content, cont->content_size)))
	{
		list = newlist;
		lst = lst->next;
		while (lst)
		{
			cont = f(lst);
			if (!(list->next = ft_lstnew(cont->content, cont->content_size)))
				return (NULL);
			list = list->next;
			lst = lst->next;
		}
	}
	return (newlist);
}
