/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:33:12 by rdedola           #+#    #+#             */
/*   Updated: 2025/01/15 01:08:01 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand_var(t_ms *ms, t_env *env, int i)
{
	char	*str_env;

	str_env = search_var(ms->lexer.tokens_array[i], env);
	ms->lexer.tokens[i - 1] = NA;
	free(ms->lexer.tokens_array[i - 1]);
	ms->lexer.tokens_array[i - 1] = ft_rstrdup("");
	if (str_env != NULL)
	{
		free(ms->lexer.tokens_array[i]);
		ms->lexer.tokens_array[i] = ft_rstrdup(str_env);
	}
	else if (str_env == NULL)
	{
		free(ms->lexer.tokens_array[i]);
		ms->lexer.tokens_array[i] = ft_rstrdup("\1");
		ms->lexer.tokens[i] = WORD;
	}
}

void	expand_retvar(t_ms *ms, int i)
{
	char	*str_env;

	str_env = ft_ritoa(g_exit_status);
	ms->lexer.tokens[i - 1] = NA;
	free(ms->lexer.tokens_array[i - 1]);
	ms->lexer.tokens_array[i - 1] = ft_rstrdup("");
	free(ms->lexer.tokens_array[i]);
	ms->lexer.tokens_array[i] = ft_rstrdup(str_env);
	free(str_env);
}
