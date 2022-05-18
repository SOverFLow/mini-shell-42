/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:59:20 by selhanda          #+#    #+#             */
/*   Updated: 2022/05/16 18:21:48 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	status;

int	thereis_infile(t_comp *comp)
{
	while (comp)
	{
		if (comp->whatisthis == 6)
			return (1);
		comp = comp->next;
	}
	return (0);
}

char	*ft_cmd(t_comp *comp)
{
	while (comp)
	{
		if (comp->whatisthis == 2)
			return (comp->data);
		comp = comp->next;
	}
	return (NULL);
}

char	*ft_get_path(char *cmd, char **env)
{
	char	*path;
	char	*dir;
	char	*bin;
	int		i;
	
	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	path = env[i] + 5;
	while (path && ft_str_ichr(path, ':') > -1)
	{
		dir = ft_str_ndup(path, ft_str_ichr(path, ':'));
		bin = ft_path_join(dir, cmd);
		free(dir);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		path += ft_str_ichr(path, ':') + 1;
	}
	return (cmd);
}

char	**ft_get_cmd(t_comp *head)
{
	t_comp	*cmd;
	char	**cmd_tab;
	int		i;
	
	if (!head)
		return (NULL);
	cmd = head->next;
	i = 2;
	while (cmd && cmd->whatisthis < 3)
	{
		cmd = cmd->next;
		i++;
	}
	cmd_tab = malloc(sizeof(char *) * i);
	if (!cmd_tab)
		return (NULL);
	cmd = head->next;
	cmd_tab[0] = head->data;
	i = 1;
	while (cmd && cmd->whatisthis < 3)
	{
		cmd_tab[i++] = cmd->data;
		cmd = cmd->next;
	}
	cmd_tab[i] = NULL;
	return (cmd_tab);
}

int	ft_execut(int infile, t_comp *comp, char **env)
{
	int	pid;
	int	fd[2];
	int	outfile;
	char *in;
	char *out;
	
	pipe(fd);
	out = is_outfile(comp);
	in	= is_infile(comp);
	pid = fork();
	if (pid == 0)
	{
		if (out == NULL)
			outfile = fd[1];
		else
			outfile = open(out, O_WRONLY | O_CREAT, 0666);
		if (outfile == -1)
		{
			perror(out);
			return (0);
		}
		if (in != NULL)
			infile = open(in, O_RDONLY);
		close(fd[0]);
		if (thereis_infile(comp) && in == NULL)
			exit(1);
		dup2(outfile, 1);
		dup2(infile, 0);
		if (execve(ft_get_path(ft_cmd(comp), env), ft_get_cmd(comp), env) == -1)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(ft_cmd(comp), 2);
			ft_putstr_fd(" :command not found\n", 2);
			exit(127);
		}
	}
	waitpid(pid, &status, 0);
	close(fd[1]);
	return (fd[0]);
}

void	ft_lst_cmd(int infile, t_comp *comp, char **env)
{
	int		outfile;
	int		pid;
	char	*in;
	char	*out;
	
	out = is_outfile(comp);
	in	= is_infile(comp);
	if (out == NULL)
		outfile = 1;
	else
		outfile = open(out, O_WRONLY | O_CREAT, 0666);
	if (outfile == -1)
	{
		perror(out);
		return ;
	}
	if (in != NULL)
		infile = open(in, O_RDONLY);
	pid = fork();
	if (pid == 0)
	{
		if (thereis_infile(comp) && in == NULL)
			exit(1);
		dup2(infile, 0);
		dup2(outfile, 1);
		if (execve(ft_get_path(ft_cmd(comp), env), ft_get_cmd(comp), env) == -1)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(ft_cmd(comp), 2);
			ft_putstr_fd(" :command not found\n", 2);
			exit(127);
		}
	}
	waitpid(pid, &status, 0);
}

t_comp	*find_prev_node(t_comp *head, t_comp *find)
{
	t_comp	*current_node;
	
	current_node = head;
	while (current_node->next != NULL)
	{
		if (current_node->next == find)
			return (current_node);
		current_node = current_node->next;
	}
	return (NULL);
}

void	ft_execution(t_list	*lst_comp, char **env, t_env *head)
{
	t_comp	*comp;
	int		cmd_len;
	int		i;
	int		infile;
	
	cmd_len = ft_lstsize(lst_comp);
	i = 0;
	infile = 0;
	if (cmd_len == 1)
	{
		comp = lst_comp->content;
		if (comp->data == NULL)
			return ;
		if (is_cmd_built(comp->data))
			execute_built_cmd(comp, infile, head);
		else
			ft_lst_cmd(infile, comp, env);
	}
	else
	{
		while (i < cmd_len - 1)
		{
			comp = lst_comp->content;
			if (comp->data == NULL)
				return ;
			if (is_cmd_built(comp->data))
				infile = execute_builtin_cmds(comp, infile, head);
			else
				infile = ft_execut(infile, comp, env);
			lst_comp = lst_comp->next;
			i++;
		}
		comp = lst_comp->content;
		if (is_cmd_built(comp->data))
			execute_built_cmd(comp, infile, head);
		else
			ft_lst_cmd(infile, comp, env);
	}
}
