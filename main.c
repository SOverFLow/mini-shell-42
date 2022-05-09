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
	t_env *env_node;
	struct sigaction sig;
		
	sig.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sig, NULL);
	env_node = init_env(env);
	// while (env_node)
	// {
	// 	printf("%s=\n", env_node->key);
	// 	env_node = env_node->next;
	// }

	while (1)
	{
		line = readline("minishell :>");
		if (*line)
		{
			add_history(line);
			lst_comp = ft_parsing(line);
			if (lst_comp != NULL)
			{
				ft_execution(lst_comp, env);
			}
			free(line);
		}
	}
}
