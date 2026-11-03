/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rep_rfi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:01:38 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/24 15:40:10 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rep_rfi(t_ms *ms, t_exe *exe, t_cmd *cmd, size_t index)
{
	cmd->has_file_i = true;
	cmd->has_pipe_i = false;
	cmd->has_heredoc = false;
	ft_strcpy(ms->lexer.tokens_array[index], cmd->rfi);
	if (access(cmd->rfi, F_OK) != 0 || access(cmd->rfi, R_OK) != 0)
	{
		exe->is_exit = true;
		ft_perror("minishell", NULL, cmd->rfi, strerror(errno));
	}
}

bool	rep_is_rfi(t_ms *ms, t_cmd *cmd, size_t index)
{
	(void) cmd;
	if (index > 0 && ms->lexer.tokens[index - 1] == REDIN)
		return (true);
	return (false);
}
