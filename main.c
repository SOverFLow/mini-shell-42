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
	char	*line;
	t_list	*lst_comp;
	t_comp	*comp;
	int pid;

	while (1)
	{
		line = readline("minishell:> ");
		if (line && *line)
			add_history(line);
		lst_comp = ft_parsing(line);
		if (ft_str_ichr(line, '|') == -1)
		{
			pid = fork();
			if (pid == 0)
				ft_exec(line, env);
		}
		waitpid(pid, NULL, 0);
	}
}
