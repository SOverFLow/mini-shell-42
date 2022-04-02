/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:24:08 by selhanda          #+#    #+#             */
/*   Updated: 2022/04/02 13:24:13 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int main(int argc, char **argv)
{
    if (argc == 1)
        printf("invalid parametres\n");
    else if (argc > 2)
        printf("Too many parametres\n");
    else if (argc == 2)
    {
        if (chdir(argv[1]) != 0)
            printf("Error\n");
    }
    return (0);
}
