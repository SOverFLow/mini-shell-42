/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:04:46 by selhanda          #+#    #+#             */
/*   Updated: 2022/04/06 16:04:49 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int     ft_env(char **env)
{
    int i;

    i = 0;
    while (env[i] != NULL)
	{
		ft_putstr_fd(env[i], 1);
        printf("\n");
		i += 1;
	}
	return (1);
}

int main(int argc, char **argv, char **env)
{
    if (argc == 2 && ft_strncmp(argv[1], "env", 4) == 0)
    {
        //printf("%s\n", env[0]);
        ft_env(env);
    }
    return (0);
}
