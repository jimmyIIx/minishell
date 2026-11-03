/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 00:05:16 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/20 23:35:25 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_status(t_cmd *cmd)
{
	int	status;

	waitpid(cmd->pid, &status, 0);
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		status = WTERMSIG(status);
		if (status == SIGSEGV)
		{
			status = 139;
			ft_write(STDERR_FILENO, "Segmentation fault (core dumped)\n");
		}
		if (status == SIGBUS)
		{
			status = 135;
			ft_write(STDERR_FILENO, "Bus error (core dumped)\n");
		}
		if (status == SIGINT)
		{
			status = 130;
			ft_write(STDERR_FILENO, "\n");
		}
	}
	g_exit_status = status;
}
