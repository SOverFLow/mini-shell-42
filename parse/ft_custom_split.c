/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_custom_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:38:33 by salamane          #+#    #+#             */
/*   Updated: 2022/04/03 17:38:35 by salamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

static int	ft_skip(char *str, char c)
{
	int	i;
	int index;

	i = 1;
	index = 0;
	while (str[i])
	{
		if (str[i] == c)
			index = i;
		i++;
	}
	return (index + 1);
}

static int	ft_w_len(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		while (str[i] && is_space(str[i]))
			i++;
		if (str[i])
			len++;
		while (str[i] && !is_space(str[i]))
		{
			if (str[i] == '"' || str[i] == 39)
				i += ft_skip(str + i, str[i]);
			else
				i++;
		}
	}
	return (len);
}

char	**ft_custom_split(char *str)
{
	int		i = 0 ;
	int		j = 0;
	int		size = 0;
	char	**split;
	int		k;

	split = (char **)malloc(sizeof(char *) * (ft_w_len(str) + 1));
	while (j < ft_w_len(str))
	{
		k = 0;
		while (str[i] && is_space(str[i]))
			i++;
		while (str[i] && !is_space(str[i]))
		{
			if (str[i] == '"' || str[i] == 39)
			{
				size += ft_skip(str + i, str[i]);
				i += ft_skip(str + i, str[i]);
			}
			else
			{
				size++;
				i++;
			}
		}
		split[j] = malloc(sizeof(char) * size + 1);
		while (size)
			split[j][k++] = str[i - size--];
		split[j++][k] = '\0';
	}
	split[j] = NULL;
	return (split);
}
