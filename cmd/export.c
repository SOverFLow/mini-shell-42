/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:07:01 by selhanda          #+#    #+#             */
/*   Updated: 2022/05/24 14:56:08 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_export_norm(t_env **env_node, char *split1, char *split2)
{
	t_env	*node;

	node = *env_node;
	if (node && node->key == NULL)
	{
		node->key = ft_strdup(split1);
		if (split2)
			node->val = ft_strdup(split2);
		return (1);
	}
	return (0);
}

void	add_var(char *var, t_env *env_node)
{
	char	**split;

	split = ft_split(var, '=');
	if (split[0] != NULL)
	{
		if (ft_is_in_env(env_node, split[0]))
		{
			if (split[1])
				edit_env_value(&env_node, split[0], split[1], 0);
			else
			{
				if (ft_str_ichr(var, '=') > -1)
					edit_env_value(&env_node, split[0], ft_strdup(""), 1);
				else
					edit_env_value(&env_node, split[0], NULL, 0);
			}
			ft_free_machine(split);
			return ;
		}
		if (ft_export_norm(&env_node, split[0], split[1]))
			ft_free_machine(split);
		else
			add_new_var(split, env_node, var);
	}
	ft_free_machine(split);
}

void	ft_export(t_comp *comp, t_env **head, int outfile)
{
	if (num_of_args(comp) == 1)
	{
		hidden_env(*head, outfile);
		return ;
	}
	else
	{
		while (comp->next)
		{
			ft_do_export_job(comp->next->data, head);
			comp = comp->next;
		}
	}
}
