/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ismetatoken.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:29:00 by rdedola           #+#    #+#             */
/*   Updated: 2025/03/14 13:51:54 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	ft_ismeatoken(t_ms *ms, int i)
{
	if (ms->lexer.tokens[i] == REDIN
		|| ms->lexer.tokens[i] == REDOUT
		|| ms->lexer.tokens[i] == HEREDOC
		|| ms->lexer.tokens[i] == APPEND_REDIR
		|| ms->lexer.tokens[i] == PIPE
		|| ms->lexer.tokens[i] == DOLLAR)
		return (TRUE);
	return (FALSE);
}
