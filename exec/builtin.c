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
	if (ft_strncmp(cmd, "echo", 5) == 0)
		return (1);
	if (ft_strncmp(cmd, "cd", 3) == 0)
		return (1);
	if (ft_strncmp(cmd, "pwd", 4) == 0)
		return (1);
	if (ft_strncmp(cmd, "env", 4) == 0)
		return (1);
	if (ft_strncmp(cmd, "export", 7) == 0)
		return (1);
	if (ft_strncmp(cmd, "unset", 6) == 0)
		return (1);
	if (ft_strncmp(cmd, "exit", 5) == 0)
		return (1);
	return (0);
}

void		execute_built_cmd(t_comp *comp, int infile)
{
	char *in;
	char *out;
	int outfile;

	out = is_outfile(comp);
	in	= is_infile(comp);
	printf("out = %s\n", out);
	printf("in = %s\n", in);
	if (out == NULL)
		outfile = 1;
	else
	{
		outfile = open(out, O_WRONLY | O_CREAT, 0666);
	}
	if (in != NULL)
	{
		infile = open(in, O_RDONLY);
		close(infile);
	}
	dup2(infile, 0);
	dup2(outfile, 1);
	if (ft_strncmp(comp->data, "echo", 5) == 0)
		ft_echo(comp);
	// if (ft_strcmp(args[0], "cd") == 0)
    // {
    //     // cd cammand
    // }
	if (ft_strncmp(comp->data, "pwd", 4) == 0)
	{
		ft_pwd();
	}
	if (out)
		close(outfile);
	if (in)
		close(infile);
	// if (ft_strncmp(comp->data, "env", 4) == 0)
    // {
    //     ft_env();
    // }
	// if (ft_strcmp(args[0], "export") == 0)
    // {
    //     // export cammand
    // }
	// if (ft_strcmp(args[0], "unset") == 0)
    // {
    //     // export cammand
    // }
}
