/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:01:56 by selhanda          #+#    #+#             */
/*   Updated: 2022/05/18 20:32:23 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler_cntrl_c(int num)
{
	ft_putstr_fd("\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	g_status = 1;
}

void	handler_cntrl_c_after(int num)
{
	ft_putstr_fd("\n", 1);
	g_status = 1;
}

void	handler_cntrl_d(int num)
{
	ft_putstr_fd("exit", 1);
	exit(1);
}