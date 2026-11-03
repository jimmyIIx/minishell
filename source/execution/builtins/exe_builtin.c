/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:50:11 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/17 17:35:20 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exe_builtin(t_cmd *cmd, t_ms *ms)
{
	if (ft_strncmp(cmd->nme, "echo", 4) == 0)
		return (builtin_echo(cmd));
	else if (ft_strncmp(cmd->nme, "cd", 2) == 0)
		return (builtin_cd(cmd, ms));
	else if (ft_strncmp(cmd->nme, "pwd", 3) == 0)
		return (builtin_pwd(ms));
	else if (ft_strncmp(cmd->nme, "unset", 5) == 0)
		return (builtin_unset(cmd, ms));
	else if (ft_strncmp(cmd->nme, "export", 6) == 0)
		return (builtin_export(cmd, ms));
	else if (ft_strncmp(cmd->nme, "exit", 4) == 0)
		return (builtin_exit(cmd, ms));
	else if (ft_strncmp(cmd->nme, "env", 3) == 0)
		return (builtin_env(ms->env));
	return (1);
}
