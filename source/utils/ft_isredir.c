/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isredir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:18:25 by rdedola           #+#    #+#             */
/*   Updated: 2025/03/14 13:49:19 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	ft_isredir(t_ms *ms, int i)
{
	if (ms->lexer.tokens[i] == HEREDOC
		|| ms->lexer.tokens[i] == APPEND_REDIR
		|| ms->lexer.tokens[i] == REDIN
		|| ms->lexer.tokens[i] == REDOUT)
		return (TRUE);
	return (FALSE);
}
