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


int ft_get_next_size(char *line)
{
    int i;
    int size;

    i = 0;
    size = 0;
    while(line[i])
    {
        if (line[i] == '>' && line[i])
        {
            if (line[i - 1] != ' ' && line[i])
                size++;
            if (line[i + 1] == '>' && line[i])
            {
                if (line[i + 2] != ' ' && line[i])
                {
                    size++;
                    i += 2;
                }
            }
            else if (line[i + 1] != ' ' && line[i])
            {
                i++;
                size++;
            }
        }
        i++;
    }
    return (size);
}

char    *ft_makespace(char *line)
{
    int     size;
    int     i;
    int     j;
    char    *new_str;

    size = ft_get_next_size(line);
    i = 0;
    j = 0;
    if (size == 0)
        return (line);
    size += ft_strlen(line);
    new_str = (char *)malloc(sizeof(char) * size + 1);
    while (i < size)
    {
        if (line[i] == '>')
        {
            if (line[i - 1] != ' ')
                new_str[j] = ' ';
            
        }
    }

}

int main(int ac, char **av)
{
    printf("%d\n", ft_get_next_size(av[1]));
}
