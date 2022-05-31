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

# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include "Libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/wait.h>

# define CMD			1 // command
# define INFILE		3 // input file
# define OUTFILE		4 // output file
# define ARG			2 // argument
# define R_R			5 // >
# define L_R			6 // <
# define R_APPEND	7 // >>
# define HER_DOC		8 // <<
# define LIMITER		9 // limiter

int	g_status;

typedef struct s_comp
{
	char			*data;
	int				whatisthis;
	struct s_comp	*next;
}		t_comp;

typedef struct s_env
{
	char			*key;
	char			*val;
	struct s_env	*next;
}		t_env;

t_comp	*ft_comp_new(char *data, int whatisthat);
t_comp	*ft_comp_last(t_comp *comp);
void	ft_comp_add(t_comp **head, t_comp *new);
char	**ft_custom_split(char *str);
t_list	*ft_parsing(char *line, t_env *env_node);
t_comp	*ft_comp_creat(char *line);
char	*ft_error_handler(char *line);

//exec
int		is_cmd_built(char *cmd);
void	execute_built_cmd(t_comp *comp, int infile, t_env **head, int what);
char	*ft_get_path(char *cmd, char **env);
void	ft_exec(char *cmd, char **env);
char	**ft_get_cmd(t_comp *head);
int		execute_builtin_cmds(t_comp *comp, int infile, t_env **head, int what);

// cammand
void	ft_pwd(int outfile);
void	ft_echo(t_comp *comp, int outfile);
void	ft_env(t_env *head, t_comp *comp, int outfile);
void	ft_unset(t_comp *comp, t_env **env_node);
void	ft_cd(t_comp *comp, t_env **env);
void	ft_exit(t_comp *comp);
void	ft_export(t_comp *comp, t_env **head, int outfile);

// utils
char	*ft_path_join(char *path, char *bin);
char	*ft_str_ndup(char *str, unsigned int n);
int		ft_str_ichr(char *str, char c);
char	*check_s_car(char *line);
char	*is_outfile(t_comp *head);
char	*is_infile(t_comp *head);
void	ft_execution(t_list	*lst_comp, t_env **head);
char	*ft_makespace(char *line);
int		thereis_infile(t_comp *comp);
int		infile_len(t_comp *head);
char	*infile_files(char **files, int len);
char	*opens_files(char **files, int len);
int		outfile_len(t_comp *head);
void	add_var(char *var, t_env *env_node);
char	*ft_env_serch(char *data, char c, t_env *env_node);
char	*ft_realvalue(char *data, t_env	*env_list);
t_list	*ft_last_parser(t_list	*lst_comp, t_env *env_node);
int		what_redi(t_comp *head);
char	*ft_cmd(t_comp *comp);
int		open_out_file(int what, char *out);
int		is_hedoc(t_comp *comp);
char	*get_limiter(t_comp *comp);
int		her_doc(char *stop_keyword);
void	hidden_env(t_env *head, int outfile);
int		check_var_env(char *var);
void	ft_print_error(char *err);
int		num_of_args(t_comp *comp);
char	**get_env_str(t_env *env);
int		get_env_len(t_env *env);
void	ft_free_machine(char **list);
void	ft_do_export_job(char *key, t_env **head);
void	add_new_var(char **split, t_env *env_node, char *var);
void	edit_env_value(t_env **head, char *key, char *val, int tr);
int		ft_is_in_env(t_env *head, char *key);
void	ft_cammand_e(char **env, t_comp *comp, int infile, int outfile);
void	ft_execute_one_cmd(t_comp *comp, t_env **head, int infile);
void	check_for_status(t_comp *comp);
void	ft_lst_cmd(int infile, t_comp *comp, char **env, int what);
int		ft_cmd_norm(char *out, int what, char **env);
int		ft_new_norm_func(char *out, int fd, int what, char **env);
int		func_for_infile_norm(int infile, char *in, t_comp *comp);
int		norm_fun_exec(int size, int infile, t_list *lst_comp, t_env **head);
int		ft_execut(int infile, t_comp *comp, char **env, int what);
char	*ft_qremove(char *str, char c);
void	ft_leaks_killer(t_list *lst);

//env
t_env	**init_env(char **env);
char	*env_key(char *str);
char	*trim_key(char *s, int start, int end);

// signals
void	handler_cntrl_c(int num);
void	handler_cntrl_c_after(int num);
void	handler_cntrl_d(int num);

#endif
