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

//signal(SIGINT, handle_sigint);
	while (1)
	{
		line = argv[1];
		if (*line)
		{
			//add_history(line);
			lst_comp = ft_parsing(line);
			if (lst_comp != NULL)
			{
				ft_execution(lst_comp, env);
				break;
			}
			//free(line);
		}
	}
}
