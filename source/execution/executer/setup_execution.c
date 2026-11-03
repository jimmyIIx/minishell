/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:26:23 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/25 10:55:59 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	execute_loop(t_ms *ms, t_exe *exe, size_t index);
static void	run_execution(t_ms *ms, t_exe *exe, t_cmd *cmd, size_t index);
static void	execute_builtins(t_ms *ms, t_exe *exe, t_cmd *cmd);
static void	execute_binaries(t_ms *ms, t_exe *exe, t_cmd *cmd);

/*static void	debug(t_cmd *cmd);//Fonction debug, temporaire !*/

void	execute(t_ms *ms)
{
	t_exe	exe;

	g_exit_status = 0;
	st_exe_init(&exe);
	signal(SIGINT, handle_macro_cct);
	preparse(ms);
	if (g_exit_status == 0)
	{
		signal(SIGINT, handle_macro_rtm);
		execute_loop(ms, &exe, 0);
	}
	st_exe_clear(&exe);
}

static void	execute_loop(t_ms *ms, t_exe *exe, size_t index)
{
	t_cmd	cmd;

	st_cmd_init(&cmd);
	if (index > 0 && ms->lexer.tokens[index - 1] == PIPE)
		cmd.has_pipe_i = true;
	while (index == 0 || ms->lexer.tokens[index - 1] != END)
	{
		reparse(ms, exe, &cmd, index);
		if (cmd.is_finished == true && exe->is_exit == false)
			return (run_execution(ms, exe, &cmd, index), st_cmd_clear(&cmd));
		++index;
	}
	st_cmd_clear(&cmd);
}

static void	run_execution(t_ms *ms, t_exe *exe, t_cmd *cmd, size_t index)
{
	if (cmd->has_file_i == true)
		exe->fd_i = open(cmd->rfi, O_RDONLY, 0644);
	pipe(exe->pipe_base);
	if (cmd->has_heredoc == true)
		pipe(exe->pipe_here);
	if (cmd->is_builtin == true)
		execute_builtins(ms, exe, cmd);
	else
		execute_binaries(ms, exe, cmd);
	pipeline_close(exe, cmd);
	execute_loop(ms, exe, index + 1);
	if (cmd->is_builtin == false)
		wait_status(cmd);
}

static void	execute_builtins(t_ms *ms, t_exe *exe, t_cmd *cmd)
{
	pipeline_open(exe, cmd, false);
	g_exit_status = exe_builtin(cmd, ms);
	dup2(exe->fds[0], STDIN_FILENO);
	dup2(exe->fds[1], STDOUT_FILENO);
}

static void	execute_binaries(t_ms *ms, t_exe *exe, t_cmd *cmd)
{
	char	**earg;
	char	**eenv;

	if (get_path(cmd, ms) == false)
		return ;
	earg = init_execution(cmd);
	eenv = ft_env_to_array(ms->env);
	if (earg == NULL)
		return ;
	if (ft_fork(&cmd->pid) == 0)
	{
		pipeline_open(exe, cmd, true);
		if (access(cmd->path, F_OK) != 0)
			ft_perror(NULL, cmd->cmd, NULL, "command not found");
		else
		{
			execve(cmd->path, earg, eenv);
			ft_free_fork(earg, eenv);
			if (access(cmd->path, X_OK) != 0)
				return (ft_perror("minishell", cmd->cmd, NULL, strerror(errno)),
					exit(126));
		}
		exit(127);
	}
	ft_free_fork(earg, eenv);
}
/*
static void	debug(t_cmd *cmd)//Fonction debug, temporaire !
{
	printf("Cmd: ] %s [\n", cmd->cmd);
	printf("Arg: ");
	t_list *larg = cmd->arg;
	while (larg)
	{
		printf("] %s (%i:%i) [", (char *) ((t_arg *)larg->content)->arg,
			(int) ((t_arg *)larg->content)->type,
			(int) ((t_arg *)larg->content)->is_strict);
		larg = larg->next;
	}
	printf("\n");
	printf("Rio: file_i: %i; file_o: %i; pipe_i: %i; pipe_o: %i; doc: %i\n",
		cmd->has_file_i, cmd->has_file_o, cmd->has_pipe_i,
		cmd->has_pipe_o, cmd->has_heredoc);
	printf("Doc: ] %s [\n", cmd->doc);
}
*/
