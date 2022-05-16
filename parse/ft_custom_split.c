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

static int is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

static int	ft_skip(char *str)
{
	int	i;

	i = 1;
	while(str[i] != '"')
	{
		i++;
	}
	return (i + 1);
}

static int	ft_w_len(char *str)
{
	int i;
	int len;

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
			if (str[i] == '"')
				i += ft_skip(str + i);
			else
				i++;
		}
	}
	return (len);
}

char	**ft_custom_split(char *str)
{
	int i = 0 ;
	int j = 0;
	int size = 0;
	int wlen = ft_w_len(str);
	char **split;
	int k;

	split = (char **)malloc(sizeof(char *) * (wlen + 1));
	while (j < wlen)
	{
		k = 0;
		while(str[i] && is_space(str[i]))
			i++;
		while (str[i] && !is_space(str[i]))
		{
			if (str[i] == '"')
			{
				size = ft_skip(str + i);
				i += ft_skip(str + i);
				break;
			}
			size++;
			i++;
		}
		split[j] = malloc(sizeof(char) * size + 1);
		while (size)
			split[j][k++] = str[i - size--];
		split[j++][k] = '\0';
	}
	split[j] = NULL;
	return (split);
}