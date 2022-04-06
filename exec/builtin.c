/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:07:09 by selhanda          #+#    #+#             */
/*   Updated: 2022/04/06 15:07:12 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		is_cmd_built(char *cmd)
{
	if (ft_strcmp(cmd, "echo") == 0)
		return (1);
	if (ft_strcmp(cmd, "cd") == 0)
		return (1);
	if (ft_strcmp(cmd, "pwd") == 0)
		return (1);
	if (ft_strcmp(cmd, "env") == 0)
		return (1);
	if (ft_strcmp(cmd, "export") == 0)
		return (1);
	if (ft_strcmp(cmd, "unset") == 0)
		return (1);
	return (0);
}

int		execute_built_cmd(char **args)
{
	int		r;

	r = 0;
	if (ft_strcmp(args[0], "echo") == 0)
    {
        // echo cammand
        r = ft_echo(args);
    }
	if (ft_strcmp(args[0], "cd") == 0)
    {
        // cd cammand
    }
	if (ft_strcmp(args[0], "pwd") == 0)
    {
        // pwd cammand
        r = ft_pwd();
    }
	if (ft_strcmp(args[0], "env") == 0)
    {
        // env cammand
    }
	if (ft_strcmp(args[0], "export") == 0)
    {
        // export cammand
    }
	if (ft_strcmp(args[0], "unset") == 0)
    {
        // export cammand
    }
	return (r);
}
