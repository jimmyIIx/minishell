/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tester_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:21:48 by rdedola           #+#    #+#             */
/*   Updated: 2024/12/06 14:41:13 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	printus(t_ms *ms, int i, const char **tokens)
{
	printf(PURP"=============== O U T P U T =============== \n"ENDCL);
	printf(PURP"INPUT: %s%s\n", ENDCL, ms->input);
	printf(PURP"NB OF TOKENS: %s%d\n", ENDCL, ms->lexer.nb_of_tokens);
	while (ms->lexer.tokens_array[i])
	{
		printf("String: \"\e[35m%s\e[0m\" Token: \e[35m%s\e[0m\n",
			ms->lexer.tokens_array[i], tokens[ms->lexer.tokens[i]]);
		i++;
	}
	printf(PURP"=============== P I P E S =============== \n"ENDCL);
	printf(PURP"NB OF PIPES : %s%d\n", ENDCL, ms->parser.nb_pipe);
}

void	print_tester_value(t_ms *ms)
{
	const char	*tokens[] = {
	[WSPACE] = "Wspace",
	[WORD] = "Word",
	[SINGLE_QUOTE] = "Single Quote",
	[DOUBLE_QUOTE] = "Double Quote",
	[PIPE] = "Pipe",
	[REDIN] = "Input Redirect",
	[REDOUT] = "Output Redirect",
	[HEREDOC] = "Heredoc",
	[APPEND_REDIR] = "Append Redirect",
	[DOLLAR] = "Dollar",
	[NA] = "NULL Token",
	};
	int			i;

	i = 0;
	printus(ms, i, tokens);
}
