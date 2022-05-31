/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilus2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:25:49 by salamane          #+#    #+#             */
/*   Updated: 2022/05/31 16:25:50 by salamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_count(char *str, char c)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == c)
			len++;
		i++;
	}
	return (len);
}

int	ft_qoutes_cheaker(char *line)
{
	int	dq;
	int	sq;

	dq = ft_count(line, '"');
	sq = ft_count(line, 39);
	if (dq % 2 == 0 && sq % 2 == 0)
		return (0);
	return (1);
}

char	ft_redection_cheaker(char *line, char c)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] && line[i] == c)
		{
			i++;
			if (line[i] && line[i] == c)
				i++;
			while (line[i] == ' ' && line[i])
				i++;
			if (!line[i])
				return ('\n');
			if (line[i] && (line[i] == '>' || line[i] == '|' || line[i] == '<'))
				return (line[i]);
		}
		i++;
	}
	return (0);
}
