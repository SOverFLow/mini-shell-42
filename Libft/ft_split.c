/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 09:55:14 by salamane          #+#    #+#             */
/*   Updated: 2021/11/10 09:55:20 by salamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	char	**ft_alloc(char const *str, char c, int *x, int *len)
{
	char	**arr;
	int		count;
	int		i;
	int		j;

	i = 0;
	count = 0;
	*len = 0;
	*x = -1;
	while (str[i])
	{
		j = i;
		while (str[j] != c && str[j] != '\0')
			j++;
		if (j > i)
		{
			count++;
			i = j;
			continue ;
		}
		i++;
	}
	arr = (char **)malloc((count + 1) * sizeof(char *));
	return (arr);
}

static	char	**ft_memefree(char **str, int count)
{
	int	i;

	i = 0;
	while (i < count + 1)
	{
		free(str[i++]);
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		count;
	int		i;
	int		j;

	str = ft_alloc(s, c, &i, &count);
	if (!s || !str)
		return (NULL);
	while (s[++i] != '\0')
	{
		j = i;
		while (s[j] != c && s[j] != '\0')
			j++;
		if (j > i)
		{
			str[count] = (char *)malloc(sizeof(char) * (j - i + 1));
			if (!str[count])
				return (ft_memefree(str, count));
			ft_strlcpy(str[count++], s + i, j - i + 1);
			i = j - 1;
		}
	}
	str[count] = 0;
	return (str);
}
