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

int	ft_qcount(char *str, char c)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != c)
			len++;
		i++;
	}
	return (len);
}

char	*ft_qremove(char *str, char c)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_str = (char *)malloc(sizeof(char) * (ft_qcount(str, c) + 1));
	while (str[i])
	{
		if (str[i] != c)
			new_str[j++] = str[i];
		i++;
	}
	new_str[j] = '\0';
	return (new_str);
}

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

char	*ft_dollar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] != ' ' && str[i + 1] != '.')
		{
			
		}
	}
}

char	*ft_realvalue(char *data, t_env	*env_list)
{
	int	i;

	i = 0;
	while (data[i])
	{
		if (data[i] == '"' || data[i] == 39)
		{
			data = ft_qremove(data, data[i]);
			break ;
		}
		i++;
	}

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
