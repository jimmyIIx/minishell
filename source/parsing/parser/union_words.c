/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:57:20 by rdedola           #+#    #+#             */
/*   Updated: 2025/03/23 16:59:22 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_len(t_ms *ms, int i)
{
	int	len;

	len = 0;
	while (i < ms->lexer.nb_of_tokens && ms->lexer.tokens[i] != END
		&& ms->lexer.tokens[i] != WSPACE)
	{
		if (ms->lexer.tokens[i] != NA)
			len += ft_rstrlen(ms->lexer.tokens_array[i]);
		i++;
	}
	return (len);
}

void	split_func(t_ms *ms, char *tmp, int *i)
{
	free(ms->lexer.tokens_array[*i]);
	ms->lexer.tokens_array[*i] = ft_rstrdup(tmp);
	if (ft_risprint(ms->lexer.tokens_array[*i][0]))
		ms->lexer.tokens[*i] = WORD;
}

void	union_words(t_ms *ms, int i)
{
	char	*tmp;

	while (i < ms->lexer.nb_of_tokens)
	{
		if (ms->lexer.tokens[i] != NA && ms->lexer.tokens[i] != WSPACE
			&& (!ft_ismeatoken(ms, i)) && (!ft_ismeatoken(ms, i + 1)))
		{
			tmp = malloc(sizeof(char) * (count_len(ms, i) + 1));
			tmp[0] = '\0';
			while (i < ms->lexer.nb_of_tokens && ms->lexer.tokens[i] != END
				&& ms->lexer.tokens[i] != WSPACE)
			{
				if (ms->lexer.tokens[i] != NA)
					ft_strcat(tmp, ms->lexer.tokens_array[i]);
				if (ms->lexer.tokens[i + 1] == WSPACE
					|| ms->lexer.tokens[i + 1] == END)
					split_func(ms, tmp, &i);
				else if (ms->lexer.tokens_array[i][0] != '\1')
					ms->lexer.tokens[i] = NA;
				i++;
			}
			free(tmp);
		}
		i++;
	}
}
