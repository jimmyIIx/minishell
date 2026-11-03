/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rep_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:01:53 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/20 17:29:00 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rep_end(t_ms *ms, t_cmd *cmd, size_t index)
{
	if (ms->lexer.tokens[index] == PIPE && cmd->has_file_o == false)
		cmd->has_pipe_o = true;
	cmd->is_finished = true;
}

bool	rep_is_end(t_ms *ms, t_cmd *cmd, size_t index)
{
	if ((ms->lexer.tokens[index] == PIPE || ms->lexer.tokens[index] == END)
		&& ft_strlen(cmd->cmd))
		return (true);
	return (false);
}
