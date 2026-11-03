/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:24:51 by rdedola           #+#    #+#             */
/*   Updated: 2025/01/14 19:15:33 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	convert_single_quotes(t_ms *ms)
{
	int	i;

	i = 0;
	while (i < ms->lexer.nb_of_tokens)
	{
		if (ms->lexer.tokens[i] == SINGLE_QUOTE)
		{
			i++;
			while (ms->lexer.tokens[i] != SINGLE_QUOTE
				&& ms->lexer.tokens[i] != END)
			{
				if (ms->lexer.tokens[i] != SINGLE_QUOTE)
				{
					ms->lexer.tokens[i] = WORD;
					i++;
				}
			}
		}
		i++;
	}
}

t_bool	convert_double_quotes(t_ms *ms, t_env *env, int *i)
{
	(*i)++;
	while (ms->lexer.tokens[*i] != END
		&& ms->lexer.tokens[*i] != DOUBLE_QUOTE)
	{
		if (ms->lexer.tokens[*i] == DOLLAR
			&& ft_strcmp(ms->lexer.tokens_array[(*i) + 1], "?"))
		{
			expand_retvar(ms, ++(*i));
			(*i)++;
		}
		else if (ms->lexer.tokens[*i] == DOLLAR
			&& ms->lexer.tokens[(*i) + 1] == WORD)
		{
			expand_var(ms, env, ++(*i));
			(*i)++;
		}
		else
			ms->lexer.tokens[(*i)++] = WORD;
	}
	if (ms->lexer.tokens[*i] != END
		&& ms->lexer.tokens[*i] == DOUBLE_QUOTE)
		return (TRUE);
	return (FALSE);
}

t_bool	handle_quote(t_ms *ms, t_env *env, int singleq, int doubleq)
{
	int	i;

	i = 0;
	while (i < ms->lexer.nb_of_tokens)
	{
		if (ms->lexer.tokens[i] == SINGLE_QUOTE)
		{
			convert_single_quotes(ms);
			singleq++;
		}
		else if (ms->lexer.tokens[i] == DOUBLE_QUOTE)
		{
			if (convert_double_quotes(ms, env, &i))
				doubleq += 2;
			else
				doubleq++;
		}
		i++;
	}
	if (singleq % 2 == 1 || doubleq % 2 == 1)
	{
		ft_perror("minishell", NULL, NULL, "erreur de syntaxe près du symbole \
inattendu « newline »");
		return (FALSE);
	}
	return (TRUE);
}
