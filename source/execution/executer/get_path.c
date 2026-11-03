/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:33:32 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/20 23:29:14 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	get_path(t_cmd *cmd, t_ms *ms)
{
	char	**paths;
	char	*path;
	char	*pathenv;
	size_t	j;

	if (access(cmd->cmd, F_OK) == 0)
		return (ft_strcpy(cmd->cmd, cmd->path), true);
	pathenv = search_var("PATH", ms->env);
	if (!pathenv)
		return (ft_perror("minishell", cmd->cmd, NULL, "No such file or \
directory"), false);
	paths = ft_split(pathenv, ':');
	j = 0;
	while (paths[j])
	{
		path = ft_strjoin_mod(ft_strjoin(paths[j], "/"), cmd->cmd);
		if (access(path, F_OK) == 0)
			return (ft_strcpy(path, cmd->path), ft_free_deep(paths),
				ft_free(path), true);
		ft_free(path);
		++j;
	}
	if (access(cmd->cmd, F_OK) != 0 && (!ft_strcmp(cmd->cmd, cmd->nme)
			|| !pathenv))
		return (ft_perror("minishell", cmd->cmd, NULL, "No such file or \
directory"), ft_free_deep(paths), false);
	return (ft_strcpy(cmd->cmd, cmd->path), ft_free_deep(paths), true);
}
