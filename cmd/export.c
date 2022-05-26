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
	t_env	*tmp_node;
	t_env	*new_node;
	char	**split;

	if (var)
		split = ft_split(var, '=');
	if (split[0] != NULL)
	{
		if (env_node && env_node->key == NULL)
		{
			env_node->key = ft_strdup(split[0]);
			if (split[1])
				env_node->val = ft_strdup(split[1]);
			return ;
		}
		new_node = malloc(sizeof(t_env));
		new_node->key = ft_strdup(split[0]);
		if (split[1])
			new_node->val = ft_strdup(split[1]);
		else
		{
			if (ft_str_ichr(var, '=') > -1)
				new_node->val = ft_strdup("=");
			else
				new_node->val = NULL;
		}
		while (env_node && env_node->next)
			env_node = env_node->next;
		tmp_node = env_node->next;
		env_node->next = new_node;
		new_node->next = tmp_node;
	}
}

void	ft_export(t_comp *comp, t_env *head, int outfile)
{
	char	**split;
	char	*key;

	if (num_of_args(comp) == 1)
		hidden_env(head, outfile);
	if (num_of_args(comp) > 1)
	{
		if (comp->next->next)
		{
			key = comp->next->next->data;
			if (key[0] == '=')
			{
				ft_print_error(&key[0]);
				g_status = 1;
				return ;
			}
		}
		while (comp->next)
		{
			key = comp->next->data;
			if (key[0] == '=')
			{
				ft_print_error(&key[0]);
				g_status = 1;
				return ;
			}
			// if (check_var_env(comp->next->data))
			// {
				if (comp->next->data != NULL)
					add_var(comp->next->data, head);
			// }
			// else
			// {
			// 	ft_print_error(comp->next->data);
			// 	g_status = 1;
			// }
			comp = comp->next;
		}
	}
}
