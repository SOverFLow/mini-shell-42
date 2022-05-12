/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:24:45 by selhanda          #+#    #+#             */
/*   Updated: 2022/04/02 13:24:48 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void ft_pwd()
{
    char path[256];
	char *cmd;
	cmd = getcwd(path, sizeof(path));
    if (!cmd)
	{
		perror("Error");
		return ;
	}
	printf("%s\n", cmd);
	//ft_putendl_fd(cmd, 1);
	// printf("oui hhhh\n");
}
