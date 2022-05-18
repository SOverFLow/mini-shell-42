/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utitus.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:53:18 by salamane          #+#    #+#             */
/*   Updated: 2022/05/18 11:53:20 by salamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_env_serch(char *data, char c, t_env *env_node)
{
	char	*str;

	str = NULL;
	if (c == '"')
		str = ft_substr(data, 1, ft_strlen(data) - 2);
	else if (c == 39)
		str = ft_substr(data, 1, ft_strlen(data) - 2);
	else
		str = data;
	if (str[0] == '$' && c != 39)
	{
		while (env_node)
		{
			if (ft_strncmp(env_node->key, str + 1, ft_strlen(str)) == 0)
				return (env_node->val);
			env_node = env_node->next;
		}
		str = NULL;
	}
	return (str);
}

char	*ft_realvalue(char *data, t_env	*env_list)
{
	if ((data[0] == '$' || data[0] == '"' || data[0] == 39) && data[1] != '\0')
		return (ft_env_serch(data, data[0], env_list));
	else
		return (data);
}

t_list	*ft_last_parser(t_list	*lst_comp, t_env *env_node)
{
	t_comp	*comp;
	t_list	*temp;

	temp = lst_comp;
	while (lst_comp)
	{
		comp = lst_comp->content;
		while (comp)
		{
			comp->data = ft_realvalue(comp->data, env_node);
			comp = comp->next;
		}
		lst_comp = lst_comp->next;
	}
	return (temp);
}
