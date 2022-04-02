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

int main(int argc, char **argv)
{
    char *path;
    (void)argv;
    if (argc > 2)
        printf("to many parameters\n");
    else if (argc == 1)
    {
        path = getcwd(path, 50);
        printf("%s\n", path);
    }
    return (0);
}
