/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalayci <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:02:18 by akalayci          #+#    #+#             */
/*   Updated: 2022/01/09 14:50:56 by akalayci         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*node;

	node = 0;
	if (!f && !lst)
		return (NULL);
	while (lst)
	{
		new = ft_lstnew((*f)(lst -> content));
		if (!new)
		{
			ft_lstclear(&node, del);
			return (NULL);
		}
		ft_lstadd_back(&node, new);
		lst = lst -> next;
	}
	return (node);
}
