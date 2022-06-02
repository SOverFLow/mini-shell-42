/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:20:26 by selhanda          #+#    #+#             */
/*   Updated: 2022/05/19 12:20:29 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	thereis_infile(t_comp *comp)
{
	while (comp)
	{
		if (comp->whatisthis == 6)
			return (1);
		comp = comp->next;
	}
	return (0);
}

char	*ft_cmd(t_comp *comp)
{
	while (comp)
	{
		if (comp->whatisthis == 2)
			return (comp->data);
		comp = comp->next;
	}
	return (NULL);
}

char	*ft_get_path(char *cmd, char **env)
{
	char	*path;
	char	*dir;
	char	*bin;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	path = env[i] + 5;
	while (path && ft_str_ichr(path, ':') > -1)
	{
		dir = ft_str_ndup(path, ft_str_ichr(path, ':'));
		bin = ft_path_join(dir, cmd);
		free(dir);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		path += ft_str_ichr(path, ':') + 1;
	}
	return (cmd);
}

char	**ft_get_cmd(t_comp *head)
{
	t_comp	*cmd;
	char	**cmd_tab;
	int		i;
	int		x;

	cmd = head;
	i = 0;
	x = 0;
	while (cmd)
	{
		if (cmd->whatisthis == 2)
			i++;
		cmd = cmd->next;
	}
	cmd_tab = malloc(sizeof(char *) * i);
	cmd = head;
	while (x < i)
	{
		if (cmd->whatisthis == 2)
			cmd_tab[x++] = cmd->data;
		cmd = cmd->next;
	}
	cmd_tab[x] = NULL;
	return (cmd_tab);
}

char	**get_env_str(t_env *env)
{
	int		len;
	char	**env_tab;
	int		i;
	char	*key;

	len = get_env_len(env);
	i = 0;
	env_tab = malloc(sizeof(char *) * (len + 1));
	while (i < len)
	{
		key = ft_strjoin(env->key, "=");
		env_tab[i] = ft_strjoin(key, env->val);
		free(key);
		env = env->next;
		i++;
	}
	env_tab[i] = NULL;
	return (env_tab);
}
