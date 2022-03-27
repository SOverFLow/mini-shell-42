/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:23:17 by salamane          #+#    #+#             */
/*   Updated: 2021/11/09 09:23:19 by salamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

static size_t	ft_start(char const	*s, char const	*set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] && set[j])
	{
		if (s[i] == set[j])
		{
			i++;
			j = -1;
		}
		j++;
	}
	return (i);
}

static size_t	ft_end(char const *s, char const *set)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s) - 1;
	while (len > 0 && set[i])
	{
		if (s[len] == set[i])
		{
			len--;
			i = -1;
		}
		i++;
	}
	return (len + 1);
}

char	*ft_strtrim(char const	*s1, char const	*set)
{
	size_t	s_alloc;
	char	*str;
	size_t	i;
	size_t	start;

	if (!s1)
		return (0);
	start = ft_start(s1, set);
	if (start >= ft_end(s1, set))
		return (ft_strdup(""));
	s_alloc = ft_end(s1, set) - ft_start(s1, set);
	str = (char *)malloc(sizeof(char) * s_alloc + 1);
	if (!str)
		return (0);
	i = 0;
	while (start < ft_end(s1, set))
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
