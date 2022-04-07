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

void	ft_exec(char **cmd, char **env)
{
	char	**argv;
	char	*path;

	argv = cmd;
	if (ft_str_ichr(argv[0], '/') > -1)
		path = argv[0];
	else
		path = ft_get_Path(argv[0], env);
	execve(path, argv, env);
	write(2, ": command not found\n", 20);
	exit(1);
}

int main(int argc, char **argv, char **envp)
{
	if (argc > 1)
		ft_exec(argv + 1, envp);
	return (0);
}