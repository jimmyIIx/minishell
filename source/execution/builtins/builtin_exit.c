/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:48:25 by rdedola           #+#    #+#             */
/*   Updated: 2025/03/18 21:10:09 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	verif_exit(t_ms *ms, t_cmd *cmd, int *exit_code, char **args);
static int	is_numeric(char *str);

int	builtin_exit(t_cmd *cmd, t_ms *ms)
{
	int		exit_code;
	char	**args;

	args = ft_arg_to_array(cmd->arg);
	ft_write(STDOUT_FILENO, "exit\n");
	if (args[0])
		verif_exit(ms, cmd, &exit_code, args);
	else
	{
		if (!cmd->has_pipe_i && !cmd->has_pipe_o)
			ms->is_exit = true;
		exit_code = g_exit_status;
	}
	ft_free_deep(args);
	return (exit_code);
}

static void	verif_exit(t_ms *ms, t_cmd *cmd, int *exit_code, char **args)
{
	if (!is_numeric(args[0]))
	{
		ft_perror("minishell", "exit", args[0], "numeric argument required");
		*exit_code = 2;
		if (!cmd->has_pipe_i && !cmd->has_pipe_o)
			ms->is_exit = true;
	}
	else if (args[1])
	{
		ft_perror("minishell", "exit", NULL, "too many arguments");
		*exit_code = 1;
	}
	else
	{
		*exit_code = ft_atoi(args[0]) % 256;
		if (!cmd->has_pipe_i && !cmd->has_pipe_o)
			ms->is_exit = true;
	}
}

static int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
