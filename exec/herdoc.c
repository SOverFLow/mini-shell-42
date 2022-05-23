/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:37:36 by selhanda          #+#    #+#             */
/*   Updated: 2022/05/18 20:44:35 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_get_herdoc(char *stop, int fd)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (ft_strncmp(line, stop, ft_strlen(stop) + 1) == 0 || !line)
			break ;
		ft_putstr_fd(line, fd);
		write(fd, "\n", 1);
		free(line);
	}
	free(line);
	exit(0);
}

int	her_doc(char *stop_keyword)
{
	int	fd[2];
	int	pid;

	pipe(fd);
	if (stop_keyword == NULL)
		return (0);
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		ft_get_herdoc(stop_keyword, fd[1]);
	}
	close(fd[1]);
	waitpid(pid, NULL, 0);
	return (fd[0]);
}
