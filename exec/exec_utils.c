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

	if (!head)
		return (NULL);
	cmd = head->next;
	i = 2;
	while (cmd && cmd->whatisthis < 3)
	{
		cmd = cmd->next;
		i++;
	}
	cmd_tab = malloc(sizeof(char *) * i);
	if (!cmd_tab)
		return (NULL);
	cmd = head->next;
	cmd_tab[0] = head->data;
	i = 1;
	while (cmd && cmd->whatisthis < 3)
	{
		cmd_tab[i++] = cmd->data;
		cmd = cmd->next;
	}
	cmd_tab[i] = NULL;
	return (cmd_tab);
}
