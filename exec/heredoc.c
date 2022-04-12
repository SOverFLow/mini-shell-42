/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:57:33 by selhanda          #+#    #+#             */
/*   Updated: 2022/04/12 16:57:38 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void ft_start_here_doc(char *stop, int fd)
{
	char *line;

	while (1)
	{
		ft_putstr_fd("heredoc> ", 1);
		line = readline("");
		if (!line)
			break ;
		if (ft_strncmp(line, stop, ft_strlen(stop) + 1) == 0)
			break ;
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	free(line);
	exit(0);
}

void ft_here_doc(char *stop)
{
	int pipes[2];
	pid_t pid;

	pipe(pipes);
	pid = fork();
	if (pid < 0)
		perror("fork error\n");
	if (pid == 0)
		ft_start_here_doc(stop, pipes[1]);
	close(pipes[1]);
	waitpid(pid, NULL, 0);
}
