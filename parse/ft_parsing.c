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
	if (index == 0 && is_redirection(splited[0]) == 0)
		return (2);
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

t_list	*ft_parsing(char *line, t_env *env_node)
{
	char	**split;
	int		i;
	t_list	*lst_comp;

	if (!line)
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
