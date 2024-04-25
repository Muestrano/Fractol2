/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:15:50 by picarlie          #+#    #+#             */
/*   Updated: 2023/10/26 21:14:34 by picarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;

	if (!lst)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (NULL);
	lst = lst->next;
	first = new;
	while (lst)
	{
		new->next = ft_lstnew(f(lst->content));
		if (!new->next)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		lst = lst->next;
		new = new->next;
	}
	return (first);
}

/*
t_list *new;
t_list *tmp;
new = NULL;
while (lst)
{
	tmp = ft_lstnew(f(lst->content));
	if (!tmp)
	{
		ft_lstclear(&tmp, del) 
		return (NULL);
	}
	ft_lstadd_back(&new, tmp);
	lst = lst->next;
}
return (new);*/