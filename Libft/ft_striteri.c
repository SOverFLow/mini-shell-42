/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:15:08 by salamane          #+#    #+#             */
/*   Updated: 2021/11/08 14:15:10 by salamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;
	size_t	len;

	if (!f)
		return ;
	if (s)
	{
		len = ft_strlen(s);
		i = 0;
		while (i < len)
		{
			(*f)(i, &s[i]);
			i++;
		}
	}
}
