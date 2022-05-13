/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:01:56 by selhanda          #+#    #+#             */
/*   Updated: 2022/05/12 11:02:00 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void handler_cntrl_c(int num)
{
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void handler_cntrl_d(int num)
{
	ft_putstr_fd("mminishell➜ exit", 1);
	exit(1);
}
