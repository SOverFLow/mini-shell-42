/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:38:04 by salamane          #+#    #+#             */
/*   Updated: 2022/05/17 11:20:53 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	*line;
	t_list	*lst_comp;
	t_env	**env_node;

	signal(SIGQUIT, SIG_IGN);
	(void)argc;
	(void)argv;
	env_node = init_env(env);
	while (1)
	{
		signal(SIGSEGV, handler_cntrl_d);
		signal(SIGINT, handler_cntrl_c);
		line = readline("\033[1;32mminishell➜ ");
		signal(SIGINT, handler_cntrl_c_after);
		if (*line)
		{
			add_history(line);
			lst_comp = ft_parsing(line, *env_node);
			if (lst_comp != NULL)
				ft_execution(lst_comp, env_node);
			free(line);
			free(lst_comp);
		}
	}
}
