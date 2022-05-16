/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:24:08 by selhanda          #+#    #+#             */
/*   Updated: 2022/05/16 17:08:13 by selhanda         ###   ########.fr       */
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

void	ft_cd(t_comp *comp)
{
	if (num_of_args(comp) == 1)
		chdir("~");
	else if (num_of_args(comp) > 2)
		printf("minishell: cd: Too many parametres\n");
	else if (num_of_args(comp) == 2)
	{
		if (chdir(comp->next->data) != 0)
			perror(comp->next->data);
	}
}
