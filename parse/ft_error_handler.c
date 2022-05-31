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

int	ft_25line(int p, char *line)
{
	while (line[p])
	{
		p++;
		while (line[p] == ' ' && line[p])
			p++;
		if (!line[p] || line[p] == '|')
		{
			write(1, "minishell: syntax error near unexpected token `|'\n", 51);
			return (0);
		}
		else
			break ;
	}
	return (1);
}

char	*ft_p_error(void)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 1);
	return (NULL);
}

char	*ft_pipe_cheaker(char *line)
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
				return (ft_p_error());
			p = i;
			if (ft_25line(p, line) == 0)
				return (NULL);
		}
		i++;
	}
	return (line);
}

int	ft_25line_1(char *line)
{
	char	c;

	if (ft_redection_cheaker(line, '<'))
	{
		c = ft_redection_cheaker(line, '<');
		if (c == '\n')
			write(1, "minishell: syntax error near unexpected token `NL'\n", 56);
		else
		{
			ft_putstr_fd("minishell: syntax error near unexpected token ", 1);
			write(1, &c, 1);
			write(1, "\n", 1);
		}
		return (0);
	}
	return (1);
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
			write(1, "minishell: syntax error near unexpected token `NL'\n", 56);
		else
		{
			ft_putstr_fd("minishell: syntax error near unexpected token ", 1);
			write(1, &c, 1);
			write(1, "\n", 1);
		}
		return (NULL);
	}
	else if (ft_25line_1(line) == 0)
		return (NULL);
	return (ft_pipe_cheaker(line));
}
