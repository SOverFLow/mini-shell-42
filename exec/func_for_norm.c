/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_for_norm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:29:14 by selhanda          #+#    #+#             */
/*   Updated: 2022/05/28 19:22:02 by selhanda         ###   ########.fr       */
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
	if (is_hedoc(comp))
		infile = get_limiter(comp);
	else if (in != NULL)
		infile = open(in, O_RDONLY);
	return (infile);
}

int	norm_fun_exec(int size, int infile, t_list *lst_comp, t_env **head)
{
	int		i;
	t_comp	*comp;

	i = 0;
	while (i < size - 1)
	{
		comp = lst_comp->content;
		if (comp->data == NULL)
			return (0);
		if (is_cmd_built(comp->data))
			infile = execute_builtin_cmds(comp, infile, head,
					what_redi(comp));
		else
			infile = ft_execut(infile, comp, get_env_str(*head),
					what_redi(comp));
		lst_comp = lst_comp->next;
		i++;
	}
	comp = lst_comp->content;
	ft_execute_one_cmd(comp, head, infile);
	return (infile);
}
