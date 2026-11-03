/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:45:53 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/18 20:49:57 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	st_cmd_clear(t_cmd *cmd)
{
	ft_lstclear(&cmd->arg, ft_free);
}

void	st_cmd_init(t_cmd *cmd)
{
	cmd->pid = -1;
	cmd->arg = NULL;
	ft_bzero(cmd->cmd, BUFSIZ);
	ft_bzero(cmd->nme, BUFSIZ);
	ft_bzero(cmd->rfi, BUFSIZ);
	ft_bzero(cmd->rfo, BUFSIZ);
	ft_bzero(cmd->doc, BUFSIZ);
	ft_bzero(cmd->path, BUFSIZ);
	cmd->has_file_i = false;
	cmd->has_file_o = false;
	cmd->has_pipe_i = false;
	cmd->has_pipe_o = false;
	cmd->has_option = false;
	cmd->is_builtin = false;
	cmd->has_heredoc = false;
	cmd->is_finished = false;
	cmd->count = 0;
}
