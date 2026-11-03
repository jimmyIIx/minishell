/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_exe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:45:53 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/25 12:32:05 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	st_exe_clear(t_exe *exe)
{
	dup2(exe->fds[0], STDIN_FILENO);
	dup2(exe->fds[1], STDOUT_FILENO);
	ft_close(&exe->fds[0]);
	ft_close(&exe->fds[1]);
	ft_close(&exe->pipe_base[0]);
	ft_close(&exe->pipe_base[1]);
	ft_close(&exe->pipe_here[0]);
	ft_close(&exe->pipe_here[1]);
	ft_close(&exe->fd_i);
	ft_close(&exe->fd_o);
}

void	st_exe_init(t_exe *exe)
{
	exe->fds[0] = dup(STDIN_FILENO);
	exe->fds[1] = dup(STDOUT_FILENO);
	exe->pipe_base[0] = -1;
	exe->pipe_base[1] = -1;
	exe->pipe_here[0] = -1;
	exe->pipe_here[1] = -1;
	exe->fd_i = -1;
	exe->fd_o = -1;
	exe->is_strict = true;
	exe->is_exit = false;
}
