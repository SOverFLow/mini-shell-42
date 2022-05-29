/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:31:40 by salamane          #+#    #+#             */
/*   Updated: 2022/05/25 14:31:43 by salamane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

int	ft_count(char *str, char c)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == c)
			len++;
		i++;
	}
	return (len);
}

int	ft_qoutes_cheaker(char *line)
{
	int	dq;
	int	sq;

	dq = ft_count(line, '"');
	sq = ft_count(line, 39);
	if (dq % 2 == 0 && sq % 2 == 0)
		return (0);
	return (1);
}

char	ft_redection_cheaker(char *line, char c)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] && line[i] == c)
		{
			i++;
			if (line[i] && line[i] == c)
				i++;
			while (line[i] == ' ' && line[i])
				i++;
			if (!line[i])
				return ('\n');
			if (line[i] && (line[i] == '>' || line[i] == '|' || line[i] == '<'))
				return (line[i]);
		}
		i++;
	}
	return (0);
}

char*	ft_pipe_cheaker(char *line)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	while (line[i])
	{
		if (line[i] == '|')
		{
			p = i - 1;
			while (p >= 0)
			{
				if (line[p] != ' ' && p != -1)
					break ;
				p--;
			}
			if (p < 0)
			{
				ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 1);
				return (NULL);
			}
			p = i;
			while (line[p])
			{
				p++;
				while (line[p] == ' ' && line[p])
					p++;
				if (!line[p] || line[p] == '|')
				{
					ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 1);
					return (NULL);
				}
				else
					break ;
			}
		}
		i++;
	}
	return (line);
}

char	*ft_error_handler(char *line)
{
	char	c;

	if (ft_qoutes_cheaker(line))
	{
		write(2, "error : quote not closed\n", 25);
		return (NULL);
	}
	else if (ft_redection_cheaker(line, '>'))
	{
		c = ft_redection_cheaker(line, '>');
		if (c == '\n')
			write(1, "minishell: syntax error near unexpected token `newline'\n", 56);
		else
		{
			ft_putstr_fd("minishell: syntax error near unexpected token ", 1);
			write(1, &c, 1);
			write(1, "\n", 1);
		}
		return (NULL);
	}
	else if (ft_redection_cheaker(line, '<'))
	{
		c = ft_redection_cheaker(line, '<');
		if (c == '\n')
			write(1, "minishell: syntax error near unexpected token `newline'\n", 56);
		else
		{
			ft_putstr_fd("minishell: syntax error near unexpected token ", 1);
			write(1, &c, 1);
			write(1, "\n", 1);
		}
		return (NULL);
	}
	return (ft_pipe_cheaker(line));
}
