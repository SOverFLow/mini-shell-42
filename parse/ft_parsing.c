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

t_list *ft_parsing(char *line)
{
	char	**split;

	split = ft_split(line, ' ');

}