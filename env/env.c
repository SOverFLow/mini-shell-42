/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 21:01:58 by selhanda          #+#    #+#             */
/*   Updated: 2022/05/16 17:15:22 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*trim_key(char *s, int start, int end)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (end - start) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*env_key(char *str)
{
	char	*key_val;
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '=')
		{
			key_val = trim_key(str, 0, i);
			return (key_val);
		}
	}
	return (NULL);
}

t_env	*init_env(char **env)
{
	t_env	*env_node;
	t_env	*new_node;
	t_env	*head;
	int		i;

	env_node = malloc(sizeof(t_env));
	head = malloc(sizeof(t_env));
	i = 1;
	env_node->key = env_key(env[0]);
	env_node->val = ft_strdup(getenv(env_node->key));
	env_node->next = NULL;
	head = env_node;
	while (env && env[i] && env[0])
	{
		new_node = malloc(sizeof(t_env));
		new_node->key = env_key(env[i]);
		new_node->val = ft_strdup(getenv(new_node->key));
		new_node->next = NULL;
		env_node->next = new_node;
		env_node = new_node;
		i++;
	}
	return (head);
}
