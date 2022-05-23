/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:59:20 by selhanda          #+#    #+#             */
/*   Updated: 2022/05/18 20:51:07 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void ft_cammand_e(char **env, t_comp *comp, int infile, int outfile, char *in)
{
	if (thereis_infile(comp) && in == NULL)
		exit(1);
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
}

int	ft_execut(int infile, t_comp *comp, char **env, int what)
{
	int		pid;
	int		fd[2];
	int		outfile;
	char	*in;
	char	*out;

	pipe(fd);
	out = is_outfile(comp);
	in = is_infile(comp);
	pid = fork();
	if (pid == 0)
	{
		if (out == NULL)
			outfile = fd[1];
		else
			outfile = open_out_file(what, out);
		if (outfile == -1)
		{
			perror(out);
			return (0);
		}
		if (is_hedoc(comp))
		{
			if (get_limiter(comp) != NULL)
				infile = her_doc(get_limiter(comp));
		}
		else if (in != NULL)
			infile = open(in, O_RDONLY);
		close(fd[0]);
		ft_cammand_e(env, comp, infile, outfile, in);
	}
	waitpid(pid, &g_status, 0);
	close(fd[1]);
	return (fd[0]);
}

void	ft_lst_cmd(int infile, t_comp *comp, char **env, int what)
{
	int		outfile;
	int		pid;
	char	*in;
	char	*out;

	out = is_outfile(comp);
	in = is_infile(comp);
	if (out == NULL)
		outfile = 1;
	else
		outfile = open_out_file(what, out);
	if (outfile == -1)
	{
		perror(out);
		return ;
	}
	if (is_hedoc(comp))
	{
		if (get_limiter(comp) != NULL)
			infile = her_doc(get_limiter(comp));
	}
	else if (in != NULL)
		infile = open(in, O_RDONLY);
	pid = fork();
	if (pid == 0)
		ft_cammand_e(env, comp, infile, outfile, in);
	waitpid(pid, &g_status, 0);
}

void	ft_execution(t_list	*lst_comp, char **env, t_env *head)
{
	t_comp	*comp;
	int		i;
	int		infile;
	int 	size;

	i = 0;
	infile = 0;
	size = ft_lstsize(lst_comp);
	if (size == 1)
	{
		comp = lst_comp->content;
		if (comp->data == NULL)
			return ;
		if (is_cmd_built(comp->data))
			execute_built_cmd(comp, infile, head, what_redi(comp));
		else
			ft_lst_cmd(infile, comp, env, what_redi(comp));
	}
	else
	{
		while (i < size - 1)
		{
			comp = lst_comp->content;
			if (comp->data == NULL)
				return ;
			if (is_cmd_built(comp->data))
				infile = execute_builtin_cmds(comp, infile, head, what_redi(comp));
			else
				infile = ft_execut(infile, comp, env, what_redi(comp));
			lst_comp = lst_comp->next;
			i++;
		}
		comp = lst_comp->content;
		if (is_cmd_built(comp->data))
			execute_built_cmd(comp, infile, head, what_redi(comp));
		else
			ft_lst_cmd(infile, comp, env, what_redi(comp));
	}
}
