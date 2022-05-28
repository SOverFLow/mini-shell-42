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
		if (thereis_infile(comp) && in == NULL)
			exit(1);
		ft_cammand_e(env, comp, infile, outfile);
	}
	waitpid(pid, &g_status, 0);
	ft_free_machine(env);
	close(fd[1]);
	return (fd[0]);
}

int	ft_cmd_norm(char *out, int what)
{
	int	outfile;

	outfile = 1;
	if (out == NULL)
		outfile = 1;
	else
		outfile = open_out_file(what, out);
	if (outfile == -1)
	{
		perror(out);
		return (-1);
	}
	return (outfile);
}

void	ft_lst_cmd(int infile, t_comp *comp, char **env, int what)
{
	int		outfile;
	int		pid;
	char	*in;
	char	*out;

	out = is_outfile(comp);
	in = is_infile(comp);
	if (ft_cmd_norm(out, what) == -1)
		return ;
	outfile = ft_cmd_norm(out, what);
	if (is_hedoc(comp) && get_limiter(comp) != NULL)
			infile = her_doc(get_limiter(comp));
	else if (in != NULL)
		infile = open(in, O_RDONLY);
	pid = fork();
	if (pid == 0)
	{
		if (thereis_infile(comp) && in == NULL)
			exit(1);
		ft_cammand_e(env, comp, infile, outfile);
	}
	waitpid(pid, &g_status, 0);
	ft_free_machine(env);
}

void	ft_execution(t_list	*lst_comp, t_env **head)
{
	t_comp	*comp;
	int		i;
	int		infile;
	int		size;

	i = 0;
	infile = 0;
	size = ft_lstsize(lst_comp);
	if (size == 1)
	{
		comp = lst_comp->content;
		if (comp->data == NULL)
			return ;
		ft_execute_one_cmd(comp, head, infile);
	}
	else
	{
		while (i < size - 1)
		{
			comp = lst_comp->content;
			if (comp->data == NULL)
				return ;
			if (is_cmd_built(comp->data))
				infile = execute_builtin_cmds(comp, infile, head,
						what_redi(comp));
			else
				infile = ft_execut(infile, comp, get_env_str(*head),
						what_redi(comp));
			lst_comp = lst_comp->next;
			i++;
		}
		comp = lst_comp->content;
		ft_execute_one_cmd(comp, head, infile);
	}
	check_for_status(comp);
}
