/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_for_norm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:29:14 by selhanda          #+#    #+#             */
/*   Updated: 2022/05/28 18:29:18 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_cmd_norm(char *out, int what, char **env)
{
	int	outfile;

	outfile = 1;
	if (out == NULL)
		outfile = 1;
	else
		outfile = open_out_file(what, out);
	if (outfile == -1)
	{
		perror(out);
		ft_free_machine(env);
		return (-1);
	}
	return (outfile);
}

int	ft_new_norm_func(char *out, int fd, int what, char **env)
{
	int	outfile;

	outfile = fd;
	if (out == NULL)
		outfile = fd;
	else
		outfile = open_out_file(what, out);
	if (outfile == -1)
	{
		perror(out);
		ft_free_machine(env);
		return (-1);
	}
	return (outfile);
}

int	func_for_infile_norm(int infile, char *in, t_comp *comp)
{
	if (is_hedoc(comp) && get_limiter(comp) != NULL)
		infile = her_doc(get_limiter(comp));
	else if (in != NULL)
		infile = open(in, O_RDONLY);
	return (infile);
}
