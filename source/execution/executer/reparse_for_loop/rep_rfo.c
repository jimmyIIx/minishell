/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rep_rfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:01:41 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/24 16:57:50 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rep_rfo(t_ms *ms, t_exe *exe, t_cmd *cmd, size_t index)
{
	int	flags;

	cmd->has_file_o = true;
	cmd->has_pipe_o = false;
	ft_strcpy(ms->lexer.tokens_array[index], cmd->rfo);
	flags = ft_ternary(ms->lexer.tokens[index - 1] == REDOUT,
			(O_WRONLY | O_TRUNC), (O_WRONLY | O_APPEND));
	ft_close(&exe->fd_o);
	exe->fd_o = open(cmd->rfo, flags | O_CREAT, 0644);
	if (exe->fd_o == -1)
	{
		exe->is_exit = true;
		ft_perror("minishell", NULL, cmd->rfo, strerror(errno));
	}
}

bool	rep_is_rfo(t_ms *ms, t_cmd *cmd, size_t index)
{
	(void) cmd;
	if (index > 0 && (ms->lexer.tokens[index - 1] == REDOUT
			|| ms->lexer.tokens[index - 1] == APPEND_REDIR))
		return (true);
	return (false);
}
