/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhanda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:10:29 by selhanda          #+#    #+#             */
/*   Updated: 2022/05/16 17:59:37 by selhanda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*is_outfile(t_comp *head)
{
	char	**files;
	int		i;
	int		len;

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

int open_out_file(int what, char *out)
{
	int outfile;

	if (what == 5)
		outfile = open(out, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	else if (what == 7)
		outfile = open(out, O_WRONLY | O_CREAT | O_APPEND, 0666);
	return (outfile);
}

int	what_redi(t_comp *head)
{
	int		what_redi;

	what_redi = 0;

	if (!head)
		return (0);
	while (head != NULL)
	{
		if (head->whatisthis == 5 || head->whatisthis == 7)
		{
			if (head->next->whatisthis == 4)
				what_redi = head->whatisthis;
		}
		head = head->next;
	}
	return (what_redi);
}

char	*is_infile(t_comp *head)
{
	char	**files;
	int		i;
	int		len;

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

int is_hedoc(t_comp *comp)
{
	int yes;

	yes = 0;

	while (comp)
	{
		if (comp->whatisthis == 8)
		{
			if (comp->next != NULL)
			{
				if (comp->next->whatisthis == 9)
					yes = 1;
			}
			else
			{
				ft_putstr_fd("syntax error near unexpected token `newline'\n", 2);
				return (0);
			}
		}
		comp = comp->next;
	}
	return (yes);
}

char *get_limiter(t_comp *comp)
{
	char *limiter;

	limiter = NULL;
	while (comp)
	{
		if (comp->whatisthis == 8)
		{
			if (comp->next)
			{
				if (comp->next->whatisthis == 9)
				{
					limiter = comp->next->data;
				}
			}
		}
		comp = comp->next;
	}
	return (limiter);
}
