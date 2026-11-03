/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rep_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:01:36 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/18 20:55:00 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rep_opt(t_ms *ms, t_exe *exe, t_cmd *cmd, size_t index)
{
	t_arg	*arg;

	cmd->has_option = true;
	arg = malloc(sizeof(t_arg));
	st_arg_init(arg);
	ft_strlcat(arg->arg, ms->lexer.tokens_array[index], BUFSIZ);
	arg->type = ft_ternary(ms->lexer.tokens_array[index][1] != '-', 2, 3);
	arg->is_strict = exe->is_strict;
	ft_lstadd_back(&cmd->arg, ft_lstnew((void *) arg));
}

bool	rep_is_opt(t_ms *ms, t_cmd *cmd, size_t index)
{
	(void) cmd;
	if ((ft_strlen(ms->lexer.tokens_array[index]) > 1
			&& ms->lexer.tokens_array[index][0] == '-')
		|| (ft_strlen(ms->lexer.tokens_array[index]) > 2
			&& ft_strncmp(ms->lexer.tokens_array[index], "--", 2) == 0))
		return (true);
	return (false);
}
