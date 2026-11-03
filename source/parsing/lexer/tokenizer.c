/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:13:48 by rdedola           #+#    #+#             */
/*   Updated: 2024/12/06 15:34:36 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_double_meta(t_ms *ms, int *x, int *y)
{
	ms->lexer.tokens_array[*y] = malloc(sizeof(char) * 3);
	if (ms->input[*x] == '<')
		ms->lexer.tokens[*y] = HEREDOC;
	else if (ms->input[*x] == '>')
		ms->lexer.tokens[*y] = APPEND_REDIR;
	ms->lexer.tokens_array[*y][0] = ms->input[*x];
	ms->lexer.tokens_array[*y][1] = ms->input[*x + 1];
	ms->lexer.tokens_array[*y][2] = '\0';
	*x += 2;
	(*y)++;
}

void	handle_meta(t_ms *ms, int *x, int *y)
{
	ms->lexer.tokens_array[*y] = malloc(sizeof(char) * 2);
	if (ms->input[*x] == '\'')
		ms->lexer.tokens[*y] = SINGLE_QUOTE;
	else if (ms->input[*x] == '\"')
		ms->lexer.tokens[*y] = DOUBLE_QUOTE;
	else if (ms->input[*x] == '|')
		ms->lexer.tokens[*y] = PIPE;
	else if (ms->input[*x] == '<')
		ms->lexer.tokens[*y] = REDIN;
	else if (ms->input[*x] == '>')
		ms->lexer.tokens[*y] = REDOUT;
	else if (ms->input[*x] == '$')
		ms->lexer.tokens[*y] = DOLLAR;
	ms->lexer.tokens_array[*y][0] = ms->input[*x];
	ms->lexer.tokens_array[*y][1] = '\0';
	(*x)++;
	(*y)++;
}

void	handle_command(t_ms *ms, int *x, int *y)
{
	int	i;

	i = 0;
	ms->lexer.tokens[*y] = WORD;
	while (ft_risprint(ms->input[*x + i]) && !ft_ismeta(ms->input[*x + i])
		&& !ft_isspace(ms->input[*x + i]))
		i++;
	ms->lexer.tokens_array[*y] = malloc(sizeof(char) * (i + 1));
	ft_strncpy(&ms->input[*x], ms->lexer.tokens_array[*y], i);
	*x += i;
	(*y)++;
}

void	handle_wspace(t_ms *ms, int *x, int *y)
{
	int	i;

	i = 0;
	ms->lexer.tokens[*y] = WSPACE;
	while (ms->input[*x + i] && ft_isspace(ms->input[*x + i])
		&& (!ft_ismeta(ms->input[*x + i]) || !ft_risprint(ms->input[*x + i])))
		i++;
	ms->lexer.tokens_array[*y] = malloc(sizeof(char) * (i + 1));
	ft_strncpy(&ms->input[*x], ms->lexer.tokens_array[*y], i);
	*x += i;
	(*y)++;
}

void	tokenizer(t_ms *ms, int x, int y)
{
	count_token(ms);
	ms->lexer.tokens = malloc(sizeof(int) * (ms->lexer.nb_of_tokens + 1));
	ms->lexer.tokens_array = malloc(sizeof(char *)
			* (ms->lexer.nb_of_tokens + 1));
	while (isspace(ms->input[x]))
		x++;
	while (ms->input[x])
	{
		if ((ms->input[x] == '>' || ms->input[x] == '<')
			&& ms->input[x + 1] == ms->input[x])
			handle_double_meta(ms, &x, &y);
		else if (ms->input && ft_ismeta(ms->input[x])
			&& (!ft_risprint(ms->input[x]) || !ft_isspace(ms->input[x])))
			handle_meta(ms, &x, &y);
		else if (ms->input && ft_isspace(ms->input[x])
			&& (!ft_risprint(ms->input[x]) || !ft_ismeta(ms->input[x])))
			handle_wspace(ms, &x, &y);
		else if (ms->input && ft_risprint(ms->input[x])
			&& (!ft_ismeta(ms->input[x]) || !ft_isspace(ms->input[x])))
			handle_command(ms, &x, &y);
	}
	ms->lexer.tokens_array[y] = NULL;
	ms->lexer.tokens[y] = END;
}
