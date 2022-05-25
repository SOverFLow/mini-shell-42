/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:31:40 by salamane          #+#    #+#             */
/*   Updated: 2022/05/25 14:31:43 by salamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

int	ft_count(char *str, char c)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == c)
			len++;
		i++;
	}
	return (len);
}

int	ft_qoutes_cheaker(char *line)
{
	int	dq;
	int	sq;

	dq = ft_count(line, '"');
	sq = ft_count(line, 39);

	// if (dq == 0 || sq == 0)
	// 	return (0);
	if (dq % 2 == 0 && sq % 2 == 0)
		return (0);
	return (1);
}

char	*ft_error_handler(char *line)
{
	if (ft_qoutes_cheaker(line))
	{
		write(2, "error : quote not closed\n", 25);
		return (NULL);
	}
	return (line);
}
