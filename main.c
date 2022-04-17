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

	while (1)
	{
		line = readline("minishell:> ");
		add_history(line);
		lst_comp = ft_parsing(line);
		ft_execution(lst_comp, env);
		// //lst_comp = lst_comp->next;
		// comp = lst_comp->content;
		// while(comp)
		// {
		// 	printf("%s   %d\n", comp->data, comp->whatisthis);
		// 	comp = comp->next;
		// }
		// printf("\n pathis %s\n", ft_get_Path(line, env));
	}
}
