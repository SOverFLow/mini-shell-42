/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:02:59 by selhanda          #+#    #+#             */
/*   Updated: 2022/05/16 16:55:09 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_env(t_env *env_node)
{
	if (env_node->next == NULL)
	{
		env_node->key = NULL;
		env_node->val = NULL;
		env_node->next = NULL;
	}
}

void	ft_unset(t_comp *comp, t_env *env_node)
{
	t_env	*tmp_node;

	if (!comp->next)
	{
		ft_putstr_fd("unset: not enough arguments\n", 1);
		return ;
	}
	if (ft_strncmp(comp->next->data, env_node->key, ft_strlen(env_node->key)) == 0)
	{
		free_env(env_node);
		return ;
	}
	while (env_node && env_node->next != NULL)
	{
		if (ft_strncmp(comp->next->data, env_node->next->key, ft_strlen(env_node->next->key)) == 0)
		{
			tmp_node = env_node->next->next;
			free_env(env_node->next);
			env_node->next = tmp_node;
			return ;
		}
		env_node = env_node->next;
	}
}
