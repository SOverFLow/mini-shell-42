/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:04:46 by selhanda          #+#    #+#             */
/*   Updated: 2022/04/06 16:04:49 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	int		num_of_args(t_comp *comp)
{
	int		num;

	num = 0;
	while (comp)
	{
		comp = comp->next;
		num++;
	}
	return (num);
}

void    ft_env(t_env *head, t_comp *comp, int outfile)
{
    if (num_of_args(comp) > 1 && comp->next->whatisthis < 5)
    {
        ft_putstr_fd("env :", outfile);
        ft_putstr_fd(comp->next->data, outfile);
        ft_putstr_fd(": No such file or directory\n", outfile);
    }
    else
    {
        while(head)
	    {
		    ft_putstr_fd(head->key, outfile);
            write(outfile, "=", 1);
            ft_putstr_fd(head->val, outfile);
            write(outfile, "\n", 1);
            head = head->next;
	    } 
    }
}
