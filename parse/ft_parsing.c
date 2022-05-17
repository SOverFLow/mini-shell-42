/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 10:36:55 by salamane          #+#    #+#             */
/*   Updated: 2022/04/02 10:37:04 by salamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_redirection(char *str)
{
	if (ft_strncmp(">", str, 2) == 0)
		return (5);
	if (ft_strncmp(">>", str, 3) == 0)
		return (7);
	if (ft_strncmp("<", str, 2) == 0)
		return (6);
	if (ft_strncmp("<<", str, 3) == 0)
		return (8);
	return (0);
}

int	whatisthis(char **splited, int index)
{
	if (index == 0)
		return (1);
	if (is_redirection(splited[index]) != 0)
		return (is_redirection(splited[index]));
	if (is_redirection(splited[index - 1]) == 5)
		return (4);
	if (is_redirection(splited[index - 1]) == 6)
		return (3);
	if (is_redirection(splited[index - 1]) == 8)
		return (9);
	if (is_redirection(splited[index - 1]) == 7)
		return (4);
	return (2);
}

t_comp	*ft_comp_creat(char *line)
{
	int		i;
	char	**splited;
	t_comp	*comp;

	i = 0;
	splited = ft_custom_split(line);
	comp = NULL;
	while (splited[i] != NULL)
	{
		ft_comp_add(&comp, ft_comp_new(splited[i], whatisthis(splited, i)));
		i++;
	}
	return (comp);
}

char	*ft_env_serch(char *data, char c, t_env *env_node)
{
	char	*str;

	str = NULL;
	if (c == '"')
		str = ft_substr(data, 1, ft_strlen(data) - 2);
	else
		str = data;
	if (str[0] == '$')
	{
		while(env_node)
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
	if ((data[0] == '$' || data[0] == '"' ) && data[1] != '\0')
		return(ft_env_serch(data, data[0], env_list));
	else
		return (data);
}

t_list	*ft_last_parser(t_list	*lst_comp, t_env *env_node)
{
	t_comp	*comp;
	t_list	*temp;

	temp = lst_comp;
	while(lst_comp)
	{
		comp = lst_comp->content;
		while(comp)
		{
			comp->data = ft_realvalue(comp->data, env_node);
			comp = comp->next;
		}
		lst_comp = lst_comp->next;
	}
	return (temp);
}

t_list	*ft_parsing(char *line, t_env *env_node)
{
	char	**split;
	int		i;
	t_list	*lst_comp;

	if(!line)
		return (0);
	line = ft_makespace(line);
	lst_comp = NULL;
	split = ft_split(line, '|');
	i = 0;
	while (split[i] != NULL)
	{
		ft_lstadd_back(&lst_comp, ft_lstnew(ft_comp_creat(split[i])));
		i++;
	}
	return (ft_last_parser(lst_comp, env_node));
}
