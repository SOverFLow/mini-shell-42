/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:24:45 by selhanda          #+#    #+#             */
/*   Updated: 2022/05/16 16:44:37 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pwd(int outfile)
{
	char	path[256];
	char	*cmd;

	cmd = getcwd(path, sizeof(path));
	if (!cmd)
	{
		perror("Error");
		g_status = 0;
		return ;
	}
	ft_putendl_fd(cmd, outfile);
	g_status = 0;
}
