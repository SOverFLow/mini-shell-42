/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:05:20 by selhanda          #+#    #+#             */
/*   Updated: 2022/05/16 16:47:36 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	int	num_of_args(t_comp *comp)
{
	int	num;

	num = 0;
	while (comp)
	{
		comp = comp->next;
		num++;
	}
	return (num);
}

void	ft_echo(t_comp *comp, int outfile)
{
	int	n;

	n = 0;
	if (num_of_args(comp) > 1)
	{
		while (comp->next->data && ft_strncmp(comp->next->data, "-n", 3) == 0)
		{
			n = 1;
			comp = comp->next;
		}
		while (comp->next && comp->next->whatisthis < 3)
		{
			ft_putstr_fd(comp->next->data, outfile);
			if (comp->next->next != NULL)
				write(outfile, " ", 1);
			comp = comp->next;
		}
	}
	if (n == 0)
		write(outfile, "\n", 1);
}
