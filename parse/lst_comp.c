/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_comp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:08:35 by salamane          #+#    #+#             */
/*   Updated: 2022/04/02 14:08:37 by salamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_comp	*ft_comp_new(char *data, int whatisthat)
{
	t_comp *new;

	new = (t_comp *)malloc(sizeof(t_comp));
	new->data = data;
	new->whatisthis = whatisthat;
	new->next = NULL;
	return (new);
}

t_comp	*ft_comp_last(t_comp *comp)
{
	while(comp != NULL)
	{
		if (comp->next == NULL)
			return (comp);
		comp = comp->next;
	}
	return (NULL);
}

void	ft_comp_add(t_comp **head,t_comp *new)
{
	t_comp	*last;

	if (*head == NULL)
		*head = new;
	else
	{
		last = ft_comp_last((*head));
		last->next = new;
	}
}
