/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:39:14 by salamane          #+#    #+#             */
/*   Updated: 2022/03/27 14:39:15 by salamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <unistd.h>
#include <stdlib.h>
#include "Libft/libft.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_comp
{
	char *data;
	int whatisthis;
	struct s_comp *next;
}		t_comp;

t_comp	*ft_comp_new(char *data, int whatisthat);
t_comp	*ft_comp_last(t_comp *comp);
void	ft_comp_add(t_comp **head,t_comp *new);

#endif
