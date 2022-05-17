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
#include <fcntl.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <sys/wait.h>

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

typedef struct s_env
{
	char *key;
	char *val;
	struct s_env *next;
}		t_env;

t_comp	*ft_comp_new(char *data, int whatisthat);
t_comp	*ft_comp_last(t_comp *comp);
void	ft_comp_add(t_comp **head,t_comp *new);
char	**ft_custom_split(char *str);
t_list	*ft_parsing(char *line, t_env *env_node);
t_comp	*ft_comp_creat(char *line);

//exec
int		is_cmd_built(char *cmd);
void	execute_built_cmd(t_comp *comp, int infile, t_env *head);
char	*ft_get_path(char *cmd, char **env);
void	ft_exec(char *cmd, char **env);
char 	**ft_get_cmd(t_comp *head);
int		execute_builtin_cmds(t_comp *comp, int infile, t_env *head);

// cammand
void 	ft_pwd(int outfile);
void    ft_echo(t_comp *comp, int outfile);
void    ft_env(t_env *head, t_comp *comp, int outfile);
void 	ft_unset(t_comp *comp, t_env *env_node);
void	ft_cd(t_comp *comp, t_env *env);
void 	ft_exit(t_comp *comp);
void 	ft_export(t_comp *comp, t_env *head);

// utils
char	*ft_path_join(char *path, char *bin);
char	*ft_str_ndup(char *str, unsigned int n);
int		ft_str_ichr(char *str, char c);
char 	*check_s_car(char *line);
char 	*is_outfile(t_comp *head);
char 	*is_infile(t_comp *head);
void	ft_execution(t_list	*lst_comp, char **env, t_env *head);
char    *ft_makespace(char *line);
int 	thereis_infile(t_comp *comp);
int 	infile_len(t_comp *head);
char 	*infile_files(char **files, int len);
char 	*opens_files(char **files, int len);
int 	outfile_len(t_comp *head);
void	add_var(char *var, t_env *env_node);

//env
t_env	*init_env(char **env);
char 	*env_key(char *str);
char 	*trim_key(char *s, int start, int end);

// signals
void 	handler_cntrl_c(int num);
void 	handler_cntrl_d(int num);

#endif
