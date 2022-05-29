/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_norm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:25:45 by selhanda          #+#    #+#             */
/*   Updated: 2022/05/28 16:25:49 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_cammand_e(char **env, t_comp *comp, int infile, int outfile)
{
	dup2(infile, 0);
	dup2(outfile, 1);
	if (ft_cmd(comp) != NULL)
	{
		if (execve(ft_get_path(ft_cmd(comp), env), ft_get_cmd(comp), env) == -1)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(ft_cmd(comp), 2);
			ft_putstr_fd(" :command not found\n", 2);
			exit(127);
		}
	}
	exit(0);
}

void	ft_execute_one_cmd(t_comp *comp, t_env **head, int infile)
{
	if (is_cmd_built(comp->data))
		execute_built_cmd(comp, infile, head, what_redi(comp));
	else
		ft_lst_cmd(infile, comp, get_env_str(*head), what_redi(comp));
}

void	check_for_status(t_comp *comp)
{
	if (WIFSIGNALED(g_status) && !is_cmd_built(comp->data) && !is_hedoc(comp))
		g_status += 128;
	else
	{	
		if (!is_cmd_built(comp->data) && !is_hedoc(comp))
			g_status = WEXITSTATUS(g_status);
	}
}
