/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makespace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:12:39 by salamane          #+#    #+#             */
/*   Updated: 2022/04/21 16:12:44 by salamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


char	*ft_dowork(char *line, char token)
{
	int		size;
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	size = ft_strlen(line) + 100;
    str = (char *)malloc(sizeof(char) * size + 1);
    while (line[i])
    {
        if (line[i] == token)
        {
            if (line[i - 1] != ' ' && line[i - 1] != token)
                str[j++] = ' ';
            str[j++] = line[i];
            if (line[i + 1] != ' ' && line[i + 1] != token)
                str[j++] = ' ';
        }
        else
            str[j++] = line[i];
        i++;
    }
    str[j] = '\0';
	return (str);
}

char    *ft_makespace(char *line)
{
    char	*str;
    char	*final;

	str = ft_dowork(line, '>');
	final = ft_dowork(str, '<');
	free(str);
	return(final);
}
