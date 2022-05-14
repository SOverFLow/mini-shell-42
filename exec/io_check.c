/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:10:29 by selhanda          #+#    #+#             */
/*   Updated: 2022/05/11 22:10:32 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *is_outfile(t_comp *head)
{
    char **files;
    int i;
    int len;

    len = outfile_len(head);
    files = malloc(sizeof(char *) * (len + 1));
    i = 0;
    if (!head || !files)
        return (NULL);
    while (head != NULL)
    {
        if (head->whatisthis == 4)
        {
            files[i] = head->data;
            i++;
        }
        head = head->next;
    }
    files[i] = NULL;
    return (opens_files(files, len));
}

char *is_infile(t_comp *head)
{
    char **files;
    int i;
    int len;

    len = infile_len(head);
    files = malloc(sizeof(char *) * (len + 1));
    i = 0;
    if (!head || !files)
        return (NULL);
    while (head != NULL)
    {
        if (head->whatisthis == 3)
        {
            files[i] = head->data;
            i++;
        }
        head = head->next;
    }
    files[i] = NULL;
    return (infile_files(files, len));
}