/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:24:08 by selhanda          #+#    #+#             */
/*   Updated: 2022/05/18 20:37:45 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	void	edit_old_pwd(t_env **env)
{
	t_env	*my_env;
	char	cmd[256];
	char	*old;

	my_env = *env;
	if (getcwd(cmd, 256) == NULL)
	{
		perror("Error\n");
		g_status = 1;
		return ;
	}
	old = ft_strjoin("OLDPWD=", cmd);
	if (!old)
	{
		perror("Error\n");
		g_status = 1;
		return ;
	}
	add_var(old, my_env);
	free(old);
}

static	char	*get_env_path(t_env **env, char *find, int len)
{
	t_env	*my_env;

	my_env = *env;
	while (my_env)
	{
		if (ft_strncmp(my_env->key, find, len) == 0)
			return (my_env->val);
		my_env = my_env->next;
	}
	return (NULL);
}

static	void	ft_go_to_path(int par, t_env **env)
{
	char	*path;

	path = NULL;
	if (par == 0)
	{
		edit_old_pwd(env);
		path = get_env_path(env, "HOME", 4);
	}
	else if (par == 1)
	{
		path = get_env_path(env, "OLDPWD", 6);
		edit_old_pwd(env);
	}
	if (chdir(path) != 0)
	{
		g_status = 1;
		perror(path);
		return ;
	}
}

void	ft_cd(t_comp *comp, t_env **env)
{
	if (num_of_args(comp) == 1)
		ft_go_to_path(0, env);
	if (num_of_args(comp) > 1)
	{
		if (ft_strncmp(comp->next->data, "-", 2) == 0)
			ft_go_to_path(1, env);
		else if (ft_strncmp(comp->next->data, "~", 2) == 0)
			ft_go_to_path(0, env);
		else
		{
			edit_old_pwd(env);
			if (chdir(comp->next->data) != 0)
			{
				perror(comp->next->data);
				g_status = 1;
				return ;
			}
		}
	}
}
