/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:29:30 by timanish          #+#    #+#             */
/*   Updated: 2024/12/05 17:19:52 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ms_tokenize.h>

int	validate_quote(char *line)
{
	size_t	squote_cnt;
	size_t	dquote_cnt;
	size_t	i;

	squote_cnt = 0;
	dquote_cnt = 0;
	i = 0;
	while (line[i])
	{
		if (dquote_cnt % 2 == 0 && line[i] == '\'')
			squote_cnt++;
		else if (squote_cnt % 2 == 0 && line[i] == '\"')
			dquote_cnt++;
		i++;
	}
	if (squote_cnt % 2 != 0 || dquote_cnt % 2 != 0)
		return (1);
	return (0);
}

int	validate_pipe(char *line)
{
	size_t	i;
	char	quote;
	int		pipe_flag;

	pipe_flag = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '"' || line[i] == '\'')
		{
			quote = line[i];
			while (line[i] && line[i] != quote)
				i ++;
		}
		if (line[i] == '|')
			pipe_flag = 1;
		else if (line[i] && line[i] != ' ')
			pipe_flag = 0;
		i ++;
	}
	if (pipe_flag)
		return (1);
	else
		return (0);
}

int	validate_syntax(char *line)
{
	int	flag;

	flag = 0;
	flag = validate_quote(line);
	if (validate_pipe(line))
		flag = 1;
	if (flag)
		free(line);
	return (flag);
}
