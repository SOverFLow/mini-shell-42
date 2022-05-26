/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:52:03 by selhanda          #+#    #+#             */
/*   Updated: 2022/05/25 17:52:09 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_var_env(char *var)
{
	if (*var == '\0')
		return (0);
	if (ft_isdigit(*var))
		return (0);
	else
		return (1);
	while (*var)
	{
		if (ft_isalnum(*var) || *var == '_')
			var++;
		else
			return (0);
	}
	return (1);
}

void	ft_print_error(char *err)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("export", 2);
	ft_putstr_fd(": `", 2);
	ft_putstr_fd(err, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
}

void	hidden_env(t_env *head, int outfile)
{
	while (head)
	{
		ft_putstr_fd("declare -x ", outfile);
		ft_putstr_fd(head->key, outfile);
		if (head->val != NULL)
		{
			write(outfile, "=\"", 2);
			if (ft_strncmp(head->val, "=", 2))
				ft_putstr_fd(head->val, outfile);
			write(outfile, "\"", 1);
		}
		write(outfile, "\n", 1);
		head = head->next;
	}
}

int	num_of_args(t_comp *comp)
{
	int	num;

	num = 0;
	while (comp)
	{
		comp = comp->next;
		num++;
	}
	return (num);
}
