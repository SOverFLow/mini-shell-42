/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makespace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:12:39 by salamane          #+#    #+#             */
/*   Updated: 2022/04/21 16:12:44 by salamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_25(char *line, char *str, int *j, int i)
{
	while (*j < ft_skip(line, line[i]))
		str[(*j)++] = line[i++];
	return (i);
}

void	ft_init(int *j, int *i, int *size, char *line)
{
	*i = 0;
	*j = 0;
	*size = ft_strlen(line) + 100;
}

char	*ft_dowork(char *line, char token)
{
	int		size;
	int		i;
	int		j;
	char	*str;

	ft_init(&j, &i, &size, line);
	str = (char *)malloc(sizeof(char) * size + 1);
	while (line[i])
	{
		if (line[i] == '"' || line[i] == 39)
			i = ft_25(line, str, &j, i);
		if (line[i] == token)
		{
			if (line[i - 1] != ' ' && line[i - 1] != token)
				str[j++] = ' ';
			str[j++] = line[i];
			if (line[i + 1] != ' ' && line[i + 1] != token)
				str[j++] = ' ';
		}
		else
			str[j++] = line[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_makespace(char *line)
{
	char	*str;
	char	*final;

	str = ft_dowork(line, '>');
	final = ft_dowork(str, '<');
	free(str);
	return (final);
}
