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

#define CMD 		1 // command
#define	INFILE		3 // input file
#define OUTFILE		4 // output file
#define ARG 		2 // argument
#define R_R			5 // >
#define L_R 		6 // <
#define R_APPEND	7 // >>
#define HER_DOC 	8 // <<
#define LIMITER		9 // limiter

typedef struct s_comp
{
	char *data;
	int whatisthis;
	struct s_comp *next;
}		t_comp;

t_comp	*ft_comp_new(char *data, int whatisthat);
t_comp	*ft_comp_last(t_comp *comp);
void	ft_comp_add(t_comp **head,t_comp *new);
char	**ft_custom_split(char *str);

#endif
