/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:44:34 by rdedola           #+#    #+#             */
/*   Updated: 2025/01/15 00:58:47 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	end_union(t_ms *ms, char *tmp, int buf_index, int i)
{
	tmp[buf_index] = '\0';
	ms->lexer.tokens[i--] = NA;
	ms->lexer.tokens[i] = WORD;
	free(ms->lexer.tokens_array[i]);
	ms->lexer.tokens_array[i] = malloc(sizeof(char) * (ft_rstrlen(tmp) + 1));
	strcpy(ms->lexer.tokens_array[i], tmp);
	free(tmp);
}

int	count_lenwords(t_ms *ms, int i)
{
	int		res;

	res = 0;
	while (i < ms->lexer.nb_of_tokens && ms->lexer.tokens[i] != SINGLE_QUOTE
		&& ms->lexer.tokens[i] != DOUBLE_QUOTE)
	{
		if (ms->lexer.tokens_array[i] != NULL)
			res += ft_rstrlen(ms->lexer.tokens_array[i]);
		i++;
	}
	return (res);
}

void	union_quote(t_ms *ms, int i, int j)
{
	int		buf_index;
	char	*tmp;

	while (i < ms->lexer.nb_of_tokens)
	{
		if (ms->lexer.tokens[i] == SINGLE_QUOTE
			|| ms->lexer.tokens[i] == DOUBLE_QUOTE)
		{
			tmp = malloc(sizeof(char) * (count_lenwords(ms, i + 1) + 1));
			ms->lexer.tokens[i++] = NA;
			buf_index = 0;
			while (i < ms->lexer.nb_of_tokens && ms->lexer.tokens[i]
				!= SINGLE_QUOTE && ms->lexer.tokens[i] != DOUBLE_QUOTE)
			{
				if (ms->lexer.tokens_array[i][0] != '\1')
					ms->lexer.tokens[i] = NA;
				j = 0;
				while (ms->lexer.tokens_array[i][j])
					tmp[buf_index++] = ms->lexer.tokens_array[i][j++];
				i++;
			}
			end_union(ms, tmp, buf_index, i);
		}
		i++;
	}
}
