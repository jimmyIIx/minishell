/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 00:03:12 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/25 11:13:12 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipeline_open(t_exe *exe, t_cmd *cmd, bool close)
{
	if (cmd->has_heredoc == true)
	{
		dup2(exe->pipe_here[0], STDIN_FILENO);
		ft_close(&exe->pipe_here[0]);
		ft_close(&exe->pipe_here[1]);
	}
	if (cmd->has_pipe_i == true || cmd->has_file_i == true)
		dup2(exe->fd_i, STDIN_FILENO);
	if (cmd->has_pipe_o == true)
		dup2(exe->pipe_base[1], STDOUT_FILENO);
	if (cmd->has_file_o == true)
		dup2(exe->fd_o, STDOUT_FILENO);
	ft_close(&exe->fd_i);
	ft_close(&exe->fd_o);
	if (close == true)
	{
		ft_close(&exe->pipe_base[0]);
		ft_close(&exe->pipe_base[1]);
	}
}

void	pipeline_close(t_exe *exe, t_cmd *cmd)
{
	if (cmd->has_heredoc == true)
	{
		write(exe->pipe_here[1], cmd->doc, ft_strlen(cmd->doc));
		ft_close(&exe->pipe_here[0]);
		ft_close(&exe->pipe_here[1]);
	}
	ft_close(&exe->fd_i);
	ft_close(&exe->fd_o);
	ft_close(&exe->pipe_base[1]);
	exe->fd_i = dup(exe->pipe_base[0]);
	ft_close(&exe->pipe_base[0]);
}

