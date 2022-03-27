/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:39:22 by salamane          #+#    #+#             */
/*   Updated: 2021/11/03 18:15:47 by salamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	f;
	size_t	i;

	i = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		f = 0;
		if (haystack[i] == needle[f])
		{
			while (haystack[i + f] == needle[f] && needle[f] && i + f < len)
				f++;
		}
		if (f == ft_strlen(needle))
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
