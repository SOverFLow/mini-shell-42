/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:38:04 by salamane          #+#    #+#             */
/*   Updated: 2022/03/27 14:38:06 by salamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char *line;
	int pid;

	while (1)
	{
		line = readline("minishell:> ");
		add_history(line);
		pid = fork();
		if (pid == 0)
		{
			ft_exec(line, env);
		}
		waitpid(pid , NULL, 0);
	}
}
