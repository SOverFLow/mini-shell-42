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
	if (ft_strncmp(">", str, 2))
		return (R_R);
	if (ft_strncmp(">>", str, 3))
		return (R_APPEND);
	if (ft_strncmp("<", str, 2))
		return (L_R);
	if (ft_strncmp("<<", str, 3))
		return (HER_DOC);
	return (0);
}

int	whatisthis(char **splited, int index)
{
	if (index == 0)
		return (CMD);
	if (splited[0][0] == '-' && splited[0][1] != '\0')
		return (ARG);
	if (is_redirection(splited[index + 1]) == 1)
		return (OUTFILE);
	if (is_redirection(splited[index - 1]) == 3)
		return (INFILE);
	if (is_redirection(splited[index - 1]) == HER_DOC)
		return (LIMITER);
	return (ARG);
}

int	ft_arrylen(char **arry)
{
	int	i;

	i = 0;
	while (arry[i])
		i++;
	return (i);
}

t_list	*ft_parsing(char *line)
{
	char	**split;
	char	**splited;
	int		i;
	int		j;
	t_comp	*comp;
	t_list	*lst_comp;

	if(!line)
		return (0);
	lst_comp = NULL;
	split = ft_split(line, '|');
	comp = malloc(sizeof(t_comp) * ft_arrylen(split));
	i = 0;
	while (split[i] != NULL)
	{
		splited = ft_split(split[i], ' ');
		j = 0;
		//comp = ft_comp_new(splited[j], whatisthis(splited, j));
		while (splited[j])
		{
			ft_comp_add(&comp, ft_comp_new(splited[j], whatisthis(splited, j)));
			ft_lstadd_back(&lst_comp, ft_lstnew(splited[j]));
			j++;
		}
		i++;
	}
	return (lst_comp);
}
