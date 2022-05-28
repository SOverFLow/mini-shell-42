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

void	add_var(char *var, t_env *env_node)
{
	char	**split;

	split = ft_split(var, '=');
	if (split[0] != NULL)
	{
		if (ft_is_in_env(env_node, split[0]))
		{
			if (split[1])
				edit_env_value_by_key(&env_node, split[0], split[1]);
			else
			{
				if (ft_str_ichr(var, '=') > -1)
					edit_env_value_by_key(&env_node, split[0], ft_strdup(""));
				else
					edit_env_value_by_key(&env_node, split[0], NULL);
			}
			return ;
		}
		if (env_node && env_node->key == NULL)
		{
			env_node->key = ft_strdup(split[0]);
			if (split[1])
				env_node->val = ft_strdup(split[1]);
			return ;
		}
		add_new_var(split, env_node, var);
		ft_free_machine(split);
	}
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
