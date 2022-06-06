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
	char	*file;

	len = outfile_len(head);
	files = malloc(sizeof(char *) * (len + 1));
	i = 0;
	if (!head || !files)
		return (NULL);
	while (head != NULL)
	{
		if (head->whatisthis == 4)
		{
			files[i] = ft_strdup(head->data);
			i++;
		}
		head = head->next;
	}
	files[i] = NULL;
	file = opens_files(files, len);
	ft_free_machine(files);
	return (file);
}

int	open_out_file(int what, char *out)
{
	int	outfile;

	outfile = 1;
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
	char	*file;

	len = infile_len(head);
	files = malloc(sizeof(char *) * (len + 1));
	i = 0;
	if (!head || !files)
		return (NULL);
	while (head != NULL)
	{
		if (head->whatisthis == 3)
		{
			files[i] = ft_strdup(head->data);
			i++;
		}
		head = head->next;
	}
	files[i] = NULL;
	file = infile_files(files, len);
	ft_free_machine(files);
	return (file);
}

int	is_hedoc(t_comp *comp)
{
	int	yes;

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
				ft_putstr_fd("syntax error near unexpected token `newline'\n",
					2);
				return (0);
			}
		}
		comp = comp->next;
	}
	return (yes);
}
