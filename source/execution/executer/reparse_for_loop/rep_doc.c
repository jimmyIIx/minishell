/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rep_doc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:01:34 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/24 15:40:47 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rep_doc(t_ms *ms, t_cmd *cmd, size_t index)
{
	ft_bzero(cmd->doc, BUFSIZ);
	cmd->has_file_i = false;
	cmd->has_pipe_i = false;
	cmd->has_heredoc = true;
	ft_strlcat(cmd->doc, ms->lexer.tokens_array[index], BUFSIZ);
}

bool	rep_is_doc(t_ms *ms, t_cmd *cmd, size_t index)
{
	(void) cmd;
	if (index > 0 && ms->lexer.tokens[index - 1] == HEREDOC)
		return (true);
	return (false);
}
