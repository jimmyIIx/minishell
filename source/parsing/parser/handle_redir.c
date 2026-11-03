/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:56:30 by rdedola           #+#    #+#             */
/*   Updated: 2025/01/07 10:32:33 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	print_error(t_ms *ms, int i);

t_bool	handle_redir(t_ms *ms)
{
	int	i;

	i = 0;
	while (i < ms->lexer.nb_of_tokens)
	{
		if (ms->lexer.tokens[i] == REDIN || ms->lexer.tokens[i] == REDOUT
			|| ms->lexer.tokens[i] == HEREDOC
			|| ms->lexer.tokens[i] == APPEND_REDIR)
		{
			i++;
			if (ms->lexer.tokens[i] == END)
			{
				ft_perror("minishell", NULL, NULL, "erreur de syntaxe près du \
symbole inattendu « newline »");
				return (FALSE);
			}
			while (ms->lexer.tokens[i] == WSPACE)
				i++;
			if (ms->lexer.tokens[i] != WORD && ms->lexer.tokens[i] != DOLLAR
				&& ms->lexer.tokens[i] != SINGLE_QUOTE
				&& ms->lexer.tokens[i] != DOUBLE_QUOTE)
				return (print_error(ms, i));
		}
		i++;
	}
	return (TRUE);
}

static t_bool	print_error(t_ms *ms, int i)
{
	ft_write(STDERR_FILENO, "minishell: erreur de syntaxe près du \
symbole inattendu « ");
	ft_write(STDERR_FILENO, ms->lexer.tokens_array[i]);
	ft_write(STDERR_FILENO, " »\n");
	return (FALSE);
}
