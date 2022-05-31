/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilus1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 11:49:02 by salamane          #+#    #+#             */
/*   Updated: 2022/05/28 11:49:04 by salamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_qcount(char *str, char c)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != c)
			len++;
		i++;
	}
	return (len);
}

char	*ft_qremove(char *str, char c)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_str = (char *)malloc(sizeof(char) * (ft_qcount(str, c) + 1));
	while (str[i])
	{
		if (str[i] != c)
			new_str[j++] = str[i];
		i++;
	}
	new_str[j] = '\0';
	free(str);
	return (new_str);
}
