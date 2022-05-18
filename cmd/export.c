/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:07:01 by selhanda          #+#    #+#             */
/*   Updated: 2022/05/16 17:00:20 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	int	num_of_args(t_comp *comp)
{
	int	num;

	num = 0;
	while (comp)
	{
		comp = comp->next;
		num++;
	}
	return (num);
}

void	add_var(char *var, t_env *env_node)
{
	t_env	*tmp_node;
	t_env	*new_node;
	char	**split;

	if (var)
		split = ft_split(var, '=');
	printf("0 => %s\n", split[0]);
	printf("1 => %s\n", split[1]);
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
		while (env_node && env_node->next)
			env_node = env_node->next;
		tmp_node = env_node->next;
		env_node->next = new_node;
		new_node->next = tmp_node;
	}
}

static void hidden_env(t_env *head, int outfile)
{
	while (head)
	{
		ft_putstr_fd("declare -x ", outfile);
		ft_putstr_fd(head->key, outfile);
		write(outfile, "=\"", 2);
		ft_putstr_fd(head->val, outfile);
		write(outfile, "\"", 1);
		write(outfile, "\n", 1);
		head = head->next;
	}
}

void	ft_export(t_comp *comp, t_env *head, int outfile)
{
	char	**split;
	char *key;

	if (num_of_args(comp) == 1)
		hidden_env(head, outfile);
	// while (comp)
	// {
	// 	printf("comp => %s\n", comp->data);
	// 	comp = comp->next;
	// }
	if (num_of_args(comp) > 1)
	{
		if (comp->next->next)
		{
			key = comp->next->next->data;
			if (key[0] == '=')
			{
				ft_putstr_fd("bash: export: `=': not a valid identifier\n", 2);
				return ;
			}
		}
		while (comp->next)
		{
			key = comp->next->data;
			if (key[0] == '=')
			{
				ft_putstr_fd("bash: export: `=': not a valid identifier\n", 2);
				return ;
			}
			if (comp->next->data != NULL)
			{
				add_var(comp->next->data, head);
			}
			comp = comp->next;
		}
	}
}
