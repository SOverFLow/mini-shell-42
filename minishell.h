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

# define STDIN 0
# define STDOUT 1
# define STDERR 2

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
t_list	*ft_parsing(char *line);

//exec
int		is_cmd_built(char *cmd);
int		execute_built_cmd(char **args);
char	*ft_get_Path(char *cmd, char **env);
void	ft_exec(char *cmd, char **env);
char 	**ft_get_cmd(t_comp *head);

// cammand
int ft_pwd();
int     ft_echo(char **args);
int     ft_env(char **env);

// utils
char	*ft_path_join (char *path, char *bin);
char	*ft_str_ndup (char *str, unsigned int n);
int		ft_str_ichr (char *str, char c);

#endif
