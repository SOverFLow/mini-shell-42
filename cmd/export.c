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

void add_var(char *var, t_env *env_node)
{
    t_env *tmp_node;
    t_env *new_node;

    if (env_node && env_node->key == NULL)
    {
        env_node->key = env_key(var);
        env_node->val = ft_strdup(getenv(env_node->key));
        return ;
    }
    new_node = malloc(sizeof(t_env));
    new_node->key = env_key(var);
    new_node->val = ft_strdup(getenv(new_node->key));
    while (env_node && env_node->next)
        env_node = env_node->next;
    tmp_node = env_node->next;
    env_node->next = new_node;
    new_node->next = tmp_node;
}

void *ft_export(char **args, t_env *env_node)
{

}
