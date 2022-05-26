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
	free(env_node->key);
	free(env_node->val);
	free(env_node);
}

void	ft_unset(t_comp *comp, t_env **env_node)
{
	t_env	*tmp_node;
	t_env   *node;

	node = *env_node;
	if (num_of_args(comp) == 1)
	{
		g_status = 1;
		ft_putstr_fd("unset: not enough arguments\n", 2);
		return ;
	}
	if (num_of_args(comp) > 1)
	{
		// if (ft_strncmp(comp->next->data, node->key,
		// 		ft_strlen(node->key) + 1) == 0)
		// {
		// 	*env_node = node->next;
		// 	free_env(node);
		// 	return ;
		// }
		tmp_node = node;
		node = node->next;
		while (node && node->next)
		{
			if (ft_strncmp(comp->next->data, node->key,
					ft_strlen(node->next->key)) == 0)
			{
				tmp_node->next = node->next;
				free_env(node);
				return ;
			}
			tmp_node = node;
			node = node->next;
		}
		if (node->next == NULL)
		{
			if (ft_strncmp(comp->next->data, node->key,
					ft_strlen(node->key) + 1) == 0)
			{
				tmp_node->next = NULL;
				free_env(node);
				return ;
			}
		}
	}
}
