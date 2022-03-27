/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_substr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:46:02 by salamane          #+#    #+#             */
/*   Updated: 2021/11/05 15:46:04 by salamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (0);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		sub = ft_strdup(&s[start]);
	else
	{
		sub = (char *)ft_calloc(sizeof(char), (len + 1));
		if (!sub)
			return (0);
		ft_strlcpy(sub, &s[start], len + 1);
	}
	return (sub);
}
