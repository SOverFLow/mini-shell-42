/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 11:37:18 by salamane          #+#    #+#             */
/*   Updated: 2021/11/13 11:37:24 by salamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	i;
	int	lstlen;

	if (!lst)
		return (0);
	i = 0;
	lstlen = ft_lstsize(lst);
	while (i < lstlen)
	{
		if (lst->next == 0)
			return (lst);
		lst = lst->next;
		i++;
	}
	return (lst);
}
