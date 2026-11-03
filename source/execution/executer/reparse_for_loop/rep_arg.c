/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rep_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:01:26 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/19 22:02:12 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rep_arg(t_ms *ms, t_exe *exe, t_cmd *cmd, size_t index)
{
	t_arg	*arg;

	arg = malloc(sizeof(t_arg));
	st_arg_init(arg);
	ft_strlcat(arg->arg, ms->lexer.tokens_array[index], BUFSIZ);
	arg->type = 1;
	exe->is_strict = false;
	arg->is_strict = false;
	ft_lstadd_back(&cmd->arg, ft_lstnew((void *) arg));
}

bool	rep_is_arg(t_ms *ms, t_cmd *cmd, size_t index)
{
	if (index > 0
		&& ms->lexer.tokens[index - 1] == WORD
		&& ft_strlen(cmd->cmd) > 0
		&& ft_strlen(ms->lexer.tokens_array[index]) > 0
		&& ms->lexer.tokens_array[index][0] != '-')
		return (true);
	return (false);
}
