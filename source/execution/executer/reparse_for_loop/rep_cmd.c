/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rep_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:01:31 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/19 22:29:51 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rep_cmd(t_ms *ms, t_cmd *cmd, size_t index)
{
	char	*builtin;

	ft_strcpy(ms->lexer.tokens_array[index], cmd->cmd);
	ft_basename(cmd->cmd, cmd->nme);
	builtin = ft_strjoin_mod(ft_strjoin(";", cmd->nme), ";");
	if (ft_strnstr(";cd;echo;env;exit;export;pwd;unset;", builtin, 35) != NULL)
		cmd->is_builtin = true;
	ft_free(builtin);
}

bool	rep_is_cmd(t_ms *ms, t_cmd *cmd, size_t index)
{
	(void) cmd;
	if (((index == 0 || ms->lexer.tokens[index - 1] == PIPE)
			|| (ms->lexer.tokens[index - 1] != REDIN
				&& ms->lexer.tokens[index - 1] != REDOUT
				&& ms->lexer.tokens[index - 1] != HEREDOC
				&& ms->lexer.tokens[index - 1] != APPEND_REDIR))
		&& (ft_strlen(ms->lexer.tokens_array[index]) > 0
			&& ms->lexer.tokens_array[index][0] != '-'))
		return (true);
	return (false);
}
