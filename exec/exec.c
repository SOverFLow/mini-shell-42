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

void	ft_exec(char *cmd, char **env)
{
	char	**argv;
	char	*path;

	argv = ft_split(cmd, ' ');
	if (ft_str_ichr(argv[0], '/') > -1)
		path = argv[0];
	else
		path = ft_get_Path(argv[0], env);
	execve(path, argv, env);
	write(2, "command not found\n", 20);
	exit(1);
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

void ft_exec_cmd(t_comp *tokens, char **env)
{
	char **cmd;
	int i;
	int pid;

	cmd = ft_get_cmd(tokens);
	i = 0;
	while (cmd && cmd[i])
	{
		pid = fork();
		if (pid < 0)
			perror("fork error\n");
		if (pid == 0)
			ft_exec(cmd[i], env);
		i++;
		waitpid(pid , NULL, 0);
	}
// 	if (cmd && is_cmd_built(cmd[0]))
// 	{
// 		//execute_built_cmd()
// 	}
}