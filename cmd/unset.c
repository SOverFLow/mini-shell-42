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

void	free_env(t_env *env)
{
	free(env->key);
	free(env->val);
	free(env);
}

void	ft_delete_env(t_env **env, char *key)
{
	t_env	*node;
	t_env	*tmp_env;

	node = *env;
	if (ft_strncmp(node->key, key, ft_strlen(key)) == 0)
	{
		*env = node->next;
		free_env(node);
		return ;
	}
	tmp_env = node;
	node = node->next;
	while (node)
	{
		if (ft_strncmp(node->key, key, ft_strlen(key)) == 0)
		{
			tmp_env->next = node->next;
			free_env(node);
			return ;
		}
		tmp_env = node;
		node = node->next;
	}
}

void	ft_unset(t_comp *comp, t_env **env)
{
	if (num_of_args(comp) == 1)
	{
		g_status = 1;
		ft_putstr_fd("unset: not enough arguments", 2);
		return ;
	}
	while (comp->next)
	{
		ft_delete_env(env, comp->next->data);
		comp = comp->next;
	}
}
