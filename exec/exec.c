/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:59:20 by selhanda          #+#    #+#             */
/*   Updated: 2022/04/07 17:59:23 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_get_Path(char *cmd, char **env)
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

char **ft_get_cmd(t_comp *head)
{
	t_comp *cmd;
	char **cmd_tab;
	int i;

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


// said

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
			outfile = open(out, O_WRONLY, O_CREAT | 0666);
		close(fd[0]);
		dup2(outfile, 1);
		dup2(infile, 0);
		execve(ft_get_Path(comp->data, env), ft_get_cmd(comp), env);
	}
	wait(NULL);
	close(fd[1]);
	return (fd[0]);
}

void	ft_lst_cmd(int infile, t_comp *comp, char **env)
{
	int outfile;
	int pid;
	char *in;
	char *out;

	out = is_outfile(comp);
	in	= is_infile(comp);
	if (out == NULL)
		outfile = 1;
	else 
		outfile = open(out, O_WRONLY, O_CREAT | 0666);
	pid = fork();
	if (pid == 0)
	{
		dup2(infile, 0);
		dup2(outfile, 1);
		execve(ft_get_Path(comp->data, env), ft_get_cmd(comp), env);
	}
	wait(NULL);
}

void	ft_execution(t_list	*lst_comp, char **env)
{
	t_comp	*comp;
	int		cmd_len;
	int		i;
	int		infile;

	cmd_len = ft_lstsize(lst_comp);
	i = 0;
	infile = 0;
	if (cmd_len == 1)
		printf("zid chi cmd\n");
	else
	{
		while (i < cmd_len - 1)
		{
			comp = lst_comp->content;
			infile = ft_execut(infile, comp, env);
			lst_comp = lst_comp->next;
			i++;
		}
		ft_lst_cmd(infile, comp, env);
	}
}