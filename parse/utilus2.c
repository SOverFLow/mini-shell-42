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
	int	c;
	int	i;

	c = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == 39 || line[i] == '"')
		{
			c = line[i];
			break ;
		}
		i++;
	}
	dq = ft_count(line, c);
	if (dq % 2 == 0)
		return (0);
	return (1);
}

char	ft_redection_cheaker(char *line, char c)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '"' || line[i] == 39)
			i += ft_skip(line, line[i]);
		else if (line[i] && line[i] == c)
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

char	*ft_else(size_t *len, int *leaks)
{
	*leaks = 1;
	*len += 1;
	return (ft_itoa(g_status));
}
