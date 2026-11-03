/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 23:34:24 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/24 16:47:12 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	preparse_heredoc(t_ms *ms, int index);
static void	print_my_error(t_ms *ms, int index);

void	preparse(t_ms *ms)
{
	int	index;

	index = 0;
	while (ms->lexer.tokens[index] != END)
	{
		if (ms->lexer.tokens[index] == WORD
			&& ft_strlen(ms->lexer.tokens_array[index]) == 1
			&& ms->lexer.tokens_array[index][0] == '\1')
			ms->lexer.tokens_array[index][0] = '\0';
		if (ms->lexer.tokens[index] == HEREDOC)
			preparse_heredoc(ms, ++index);
		++index;
	}
}

static void	preparse_heredoc(t_ms *ms, int index)
{
	char	*line;
	char	buffer[BUFSIZ];

	ft_bzero(buffer, BUFSIZ);
	while (true)
	{
		line = readline("heredoc> ");
		if (line == NULL)
		{
			if (g_exit_status == 0)
				print_my_error(ms, index);
			break ;
		}
		if (ft_strcmp(line, ms->lexer.tokens_array[index]))
		{
			ft_free(line);
			break ;
		}
		ft_strlcat(buffer, line, BUFSIZ);
		ft_strlcat(buffer, "\n", BUFSIZ);
		ft_free(line);
	}
	ft_free(ms->lexer.tokens_array[index]);
	ms->lexer.tokens_array[index] = ft_strdup(buffer);
}

static void	print_my_error(t_ms *ms, int index)
{
	ft_write(STDERR_FILENO, "minishell: warning: here-document delimited by \
end-of-file (wanted `");
	ft_write(STDERR_FILENO, ms->lexer.tokens_array[index]);
	ft_write(STDERR_FILENO, "')\n");
}
