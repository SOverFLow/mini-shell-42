/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 11:23:48 by salamane          #+#    #+#             */
/*   Updated: 2021/11/14 11:23:51 by salamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*temp;

	if (!lst)
		return (0);
	result = ft_lstnew(f(lst->content));
	temp = result;
	lst = lst->next;
	while (lst)
	{
		ft_lstadd_back(&result, ft_lstnew(f(lst->content)));
		lst = lst->next;
		if (!result)
			ft_lstclear(&result, del);
	}
	return (temp);
}
