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
	free(str);
	return (new_str);
}

char	*ft_env_search(char *data, t_env *env_node)
{
	if (data[0] == '\0')
		return (NULL);
	while (env_node)
	{
		if (ft_strncmp(env_node->key, data, ft_strlen(env_node->key) + 1) == 0)
		{
			free(data);
			return (env_node->val);
		}
		env_node = env_node->next;
	}
	free(data);
	return (NULL);
}

int	ft_contunue(char *dollar, char *s, int *j, t_env *env_nod)
{
	size_t	len;
	int		i;
	char	*str;

	i = 0;
	len = 0;
	if (ft_isdigit(s[i]))
		return (1);
	if (s[i] != '?')
	{
		while (ft_isalnum(s[len]) || s[len] == '_')
			len++;
		str = ft_env_search(ft_substr(s, 0, len), env_nod);
	}
	else
	{
		str = ft_itoa(g_status);
		len++;
	}
	if (!str)
		return (len);
	while (str[i])
	{
		dollar[(*j)++] = str[i];
		i++;
	}
	return (len);
}

char	*ft_dollar(char *str, t_env *env_nod)
{
	int		i;
	int		j;
	char	*dollar;

	i = 0;
	j = 0;
	dollar = malloc(sizeof(char) * 1024);
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1])
		{
			i += ft_contunue(dollar, str + (i + 1), &j, env_nod);
		}
		else
			dollar[j++] = str[i];
		i++;
	}
	dollar[j] = '\0';
	free(str);
	return (dollar);
}

char	*ft_realvalue(char *data, t_env	*env_list)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (data[i])
	{
		if (data[i] == 39)
		{
			c = 39;
			break ;
		}
		else if (data[i] == '"')
		{
			c = 34;
			break ;
		}
		else if (data[i] == '$')
		{
			c = 36;
			break ;
		}
		i++;
	}
	if (c != 39)
		data = ft_dollar(data, env_list);
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
