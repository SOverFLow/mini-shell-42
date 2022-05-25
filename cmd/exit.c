/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:01:02 by selhanda          #+#    #+#             */
/*   Updated: 2022/05/16 17:06:02 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_is_num_arg(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (ft_isdigit(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}

int	check_is_num_int(char *str, int num)
{
	while (*str == ' ' || *str == '\t')
		str++;
	if (num == -1)
	{
		if (*str != '-')
			return (0);
	}
	else if (num == 0)
	{
		if (*str == '-' || *str == '+')
			str++;
		while (*str)
		{
			if (*str != '0')
				return (0);
			str++;
		}
	}
	return (1);
}

void	ft_error_for_non_num(void)
{
	ft_putstr_fd("exit\n", 2);
	ft_putstr_fd("minishell: exit: numeric argument required\n", 2);
	exit(255);
}

void	ft_to_m_p(void)
{
	ft_putstr_fd("exit\n", 2);
	ft_putstr_fd("minishell: exit: Too many parametres\n", 2);
	g_status = 1;
}

void	ft_exit(t_comp *comp)
{
	char	*tmp;
	int		i;

	if (num_of_args(comp) > 2)
	{
		ft_to_m_p();
		return ;
	}
	if (num_of_args(comp) == 1)
	{
		ft_putstr_fd("exit\n", 1);
		exit(0);
	}
	else if (num_of_args(comp) == 2)
	{
		tmp = comp->next->data;
		i = ft_atoi(tmp);
		if (!check_is_num_arg(tmp))
			ft_error_for_non_num();
		if (!check_is_num_int(tmp, i))
			ft_error_for_non_num();
	}
	ft_putstr_fd("exit\n", 1);
	exit(i);
}
