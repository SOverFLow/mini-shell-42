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
void handler_cntrl_c(int num)
{
	ft_putendl_fd("you are press control/c", 1);
}

int	main(int argc, char **argv, char **env)
{
	char	*line;
	t_list	*lst_comp;
	t_comp	*comp;
	t_env *env_node;

	//signal(SIGINT, handler_cntrl_c);
	// while (env_node)
	// {
	// 	printf("%s=%s\n", env_node->key, env_node->val);
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
