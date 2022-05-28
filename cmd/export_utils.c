/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 13:14:57 by selhanda          #+#    #+#             */
/*   Updated: 2022/05/28 13:15:02 by selhanda         ###   ########.fr       */
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
			if (val != NULL)
				my_head->val = ft_strdup(val);
			else
				my_head->val = NULL;
			return ;
		}
		my_head = my_head->next;
	}
}

void	add_new_var(char **split, t_env *env_node, char *var)
{
	t_env	*tmp_node;
	t_env	*new_node;

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

void	ft_do_export_job(char *key, t_env **head)
{
	int		err;

	err = check_var_env(key);
	if (err == 0)
	{
		ft_print_error(key);
		g_status = 1;
	}
	if (key[0] == '=')
	{
		ft_print_error(key);
		g_status = 1;
	}
	if (err == 1)
	{
		if (key != NULL)
			add_var(key, *head);
	}
}
