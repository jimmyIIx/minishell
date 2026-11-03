/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:54:55 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/25 17:39:45 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			export_noarg(t_env *env);
static int	export_arg(t_env *env, char *args);
static bool	verif_arg(char *arg);

int	builtin_export(t_cmd *cmd, t_ms *ms)
{
	t_list	*temp;
	int		exit_code;
	int		status_code;

	exit_code = 0;
	status_code = 0;
	if (ft_lstsize(cmd->arg) == 0)
		export_noarg(ms->env);
	else
	{
		if (cmd->has_pipe_i || cmd->has_pipe_o)
			return (0);
		temp = cmd->arg;
		while (temp)
		{
			status_code = export_arg(ms->env, ((t_arg *) temp->content)->arg);
			if (status_code != 0)
				exit_code = status_code;
			temp = temp->next;
		}
	}
	return (exit_code);
}

static int	export_arg(t_env *env, char *arg)
{
	char	name[64];
	char	value[4096];
	bool	egal;
	int		i;

	i = 0;
	if (verif_arg(arg) == false)
		return (1);
	i = 0;
	egal = false;
	ft_bzero(name, 64);
	ft_bzero(value, 4096);
	while (arg[i] != '\0' && arg[i] != '=')
	{
		name[i] = arg[i];
		++i;
	}
	if (arg[i] == '=')
	{
		ft_strlcpy(value, &arg[i + 1], 4096);
		egal = true;
	}
	modify_var(name, value, egal, env);
	return (0);
}

static bool	verif_arg(char *arg)
{
	int	i;

	i = 0;
	if (ft_strchr("!@#$%^&*()-+={}[]|\\:;'\"<>,?/ 0123456789", arg[i]) != NULL)
		return (ft_perror("minishell", "export", arg, "not a valid \
identifier"), false);
	while (arg[i] != '\0' && arg[i] != '=')
	{
		if (ft_strchr("!@#$%^&*()-+={}[]|\\:;'\"<>,?/ ", arg[i]) != NULL)
			return (ft_perror("minishell", "export", arg, "not a valid \
identifier"), false);
		++i;
	}
	return (true);
}
