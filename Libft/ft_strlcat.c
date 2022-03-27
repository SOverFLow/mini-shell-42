/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:40:27 by salamane          #+#    #+#             */
/*   Updated: 2021/11/05 17:40:28 by salamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	slen;
	size_t	dlen;

	i = 0;
	slen = ft_strlen(src);
	if (dstsize == 0)
		return (slen);
	dlen = ft_strlen(dst);
	if (dstsize < dlen)
		return (slen + dstsize);
	else
	{
		while (src[i] && i + dlen < dstsize - 1)
		{
			dst[i + dlen] = src[i];
			i++;
		}
		dst[i + dlen] = '\0';
	}
	return (slen + dlen);
}
