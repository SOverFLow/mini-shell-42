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
		lst_comp = NULL;
		comp = NULL;
		add_history(line);
		line = readline("minishell:> ");
		if (*line != '\0')
		{
			lst_comp = ft_parsing(line);
			//comp = (t_comp *)lst_comp->content;
			printf("%s", lst_comp->content);
		}
	}
}
