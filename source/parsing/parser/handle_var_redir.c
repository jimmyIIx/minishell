/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_var_redir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:07:20 by rdedola           #+#    #+#             */
/*   Updated: 2025/03/24 16:47:35 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	handle_var_redir(t_ms *ms)
{
	int	i;

	i = 0;
	while (ms->lexer.tokens[i] != END)
	{
		if (ft_isredir(ms, i++))
		{
			if (ms->lexer.tokens_array[i][0] == '\1')
			{
				ft_perror("minishell", NULL, NULL, "ambiguous redirection.");
				return (FALSE);
			}
			if (ms->lexer.tokens_array[i][0] == '/')
			{
				ft_perror("minishell", NULL, NULL, "is a directory.");
				return (FALSE);
			}
		}
	}
	return (TRUE);
}
