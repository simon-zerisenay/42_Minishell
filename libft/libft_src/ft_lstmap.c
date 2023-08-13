/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:43:46 by melsahha          #+#    #+#             */
/*   Updated: 2023/05/05 11:14:31 by melsahha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*curr;

	head = ft_lstnew(f(lst->content));
	if (!head)
		return (0);
	curr = head;
	while (lst->next)
	{
		lst = lst->next;
		curr = ft_lstnew(f(lst->content));
		if (!curr)
		{
			ft_lstclear(&head, del);
			return (head);
		}
		ft_lstadd_back(&head, curr);
	}
	return (head);
}
