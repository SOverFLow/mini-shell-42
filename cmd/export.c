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

int	ft_is_in_env(t_env *head, char *key)
{
	while (head)
	{
		if (ft_strncmp(head->key, key, ft_strlen(key)) == 0)
			return (1);
		head = head->next;
	}
	return (0);
}

void	edit_env_value_by_key(t_env **head, char *key, char *val)
{
	t_env	*my_head;

	my_head = *head;
	while (my_head)
	{
		if (ft_strncmp(my_head->key, key, ft_strlen(key)) == 0)
		{
			free(my_head->val);
			my_head->val = ft_strdup(val);
			return ;
		}
		my_head = my_head->next;
	}
}

void	add_var(char *var, t_env *env_node)
{
	t_env	*tmp_node;
	t_env	*new_node;
	char	**split;

	split = ft_split(var, '=');
	if (split[0] != NULL)
	{
		if (ft_is_in_env(env_node, split[0]))
		{
			edit_env_value_by_key(&env_node, split[0], split[1]);
			return ;
		}
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
				new_node->val = ft_strdup("");
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
	char	*key;
	int		err;

	if (num_of_args(comp) == 1)
	{
		hidden_env(head, outfile);
		return ;
	}
	else
	{
		while (comp->next)
		{
			err = check_var_env(comp->next->data);
			if (err == 0)
			{
				ft_print_error(comp->next->data);
				g_status = 1;
			}
			key = comp->next->data;
			if (key[0] == '=')
			{
				ft_print_error(&key[0]);
				g_status = 1;
			}
			if (err == 1)
			{
				if (comp->next->data != NULL)
					add_var(comp->next->data, head);
			}
			comp = comp->next;
		}
	}
}
