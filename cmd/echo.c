/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:05:20 by selhanda          #+#    #+#             */
/*   Updated: 2022/04/06 16:05:26 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


static	int		num_of_args(char **args)
{
	int		num;

	num = 0;
	while (args[num])
		num++;
	return (num);
}

int     ft_echo(char **args)
{
    int		i;
	int		n;

	i = 1;
	n = 0;
	if (nb_args(args) > 1)
	{
		while (args[i] && ft_strcmp(args[i], "-n") == 0)
		{
			n = 1;
			i++;
		}
		while (args[i])
		{
			ft_putstr_fd(args[i], 1);
			if (args[i + 1] && args[i][0] != '\0')
				write(1, " ", 1);
			i++;
		}
	}
    if (n == 0)
		write(1, "\n", 1);
	return (1);
}
