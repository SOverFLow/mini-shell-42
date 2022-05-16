/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:07:01 by selhanda          #+#    #+#             */
/*   Updated: 2022/05/15 18:07:04 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	int		num_of_args(t_comp *comp)
{
	int		num;

	num = 0;
	while (comp)
	{
		comp = comp->next;
		num++;
	}
	return (num);
}

void add_var(char *var, t_env *env_node)
{
    t_env *tmp_node;
    t_env *new_node;
    char **split;

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
        while (env_node && env_node->next)
            env_node = env_node->next;
        tmp_node = env_node->next;
        env_node->next = new_node;
        new_node->next = tmp_node;
    }
}

void ft_export(t_comp *comp, t_env *head)
{
    char **split;
    if (num_of_args(comp) > 1)
    {
        while (comp->next)
        {
            if (comp->next->data != NULL)
            {
                add_var(comp->next->data, head);
            }
            comp = comp->next;
        }
    }
}
