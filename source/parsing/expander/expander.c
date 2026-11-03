/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 23:54:28 by rdedola           #+#    #+#             */
/*   Updated: 2025/01/09 11:23:22 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expander(t_ms *ms, t_env *env)
{
	int	i;

	i = 0;
	while (i < ms->lexer.nb_of_tokens)
	{
		if (ms->lexer.tokens[i] == DOLLAR
			&& ft_strcmp(ms->lexer.tokens_array[i + 1], "?"))
		{
			expand_retvar(ms, ++i);
			i++;
		}
		else if (ms->lexer.tokens[i] == DOLLAR
			&& ms->lexer.tokens[i + 1] == WORD)
		{
			expand_var(ms, env, ++i);
			i++;
		}
		else
			i++;
	}
}
