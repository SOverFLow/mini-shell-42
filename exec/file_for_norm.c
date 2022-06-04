/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_for_norm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:38:03 by salamane          #+#    #+#             */
/*   Updated: 2022/06/04 18:38:06 by salamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_dala(int pid, char *out, int fd, char **env)
{
	waitpid(pid, &g_status, 0);
	ft_free_machine(env);
	close(fd);
	free(out);
}

int	infile_norminette_func(int infile, t_comp *comp, char *in)
{
	if (is_hedoc(comp))
			infile = get_limiter(comp);
	else if (in != NULL)
		infile = open(in, O_RDONLY);
	return (infile);
}

void	other_func_for_norm(int pid, char *out, char **env)
{
	waitpid(pid, &g_status, 0);
	free(out);
	ft_free_machine(env);
}
