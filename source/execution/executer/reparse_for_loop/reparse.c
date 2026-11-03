/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reparse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:24:12 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/20 19:07:13 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	reparse(t_ms *ms, t_exe *exe, t_cmd *cmd, size_t index)
{
	if (rep_is_end(ms, cmd, index))
		return (rep_end(ms, cmd, index));
	if (ms->lexer.tokens[index] == WORD)
	{
		if (rep_is_arg(ms, cmd, index))
			return (rep_arg(ms, exe, cmd, index));
		if (rep_is_cmd(ms, cmd, index))
			return (rep_cmd(ms, cmd, index));
		if (rep_is_opt(ms, cmd, index))
			return (rep_opt(ms, exe, cmd, index));
		if (rep_is_rfi(ms, cmd, index))
			return (rep_rfi(ms, exe, cmd, index));
		if (rep_is_rfo(ms, cmd, index))
			return (rep_rfo(ms, exe, cmd, index));
		if (rep_is_doc(ms, cmd, index))
			return (rep_doc(ms, cmd, index));
	}
}
