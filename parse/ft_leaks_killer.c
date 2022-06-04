/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leaks_killer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:48:14 by salamane          #+#    #+#             */
/*   Updated: 2022/05/29 18:48:16 by salamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_comp_freer(t_comp *comp)
{
	t_comp	*tmp;

	tmp = comp;
	while (tmp)
	{
		tmp = comp->next;
		if (comp->data[0])
			free(comp->data);
		free(comp);
		comp = tmp;
	}
}

void	ft_leaks_killer(t_list *lst)
{
	t_comp	*comp;
	t_list	*tmp;
	t_list	*list;

	list = lst;
	while (lst)
	{
		comp = lst->content;
		ft_comp_freer(comp);
		lst = lst->next;
	}
	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}
