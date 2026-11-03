/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:59:51 by rdedola           #+#    #+#             */
/*   Updated: 2025/01/15 01:14:31 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
		free(array[i++]);
	free(array);
}

int	tab_len(t_ms *ms)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < ms->lexer.nb_of_tokens)
	{
		if (ms->lexer.tokens[i] == WSPACE || ms->lexer.tokens[i] == NA)
			i++;
		res++;
		i++;
	}
	return (res);
}

void	sort_token(t_ms *ms)
{
	int	*temp;
	int	tab_size;
	int	i;
	int	j;

	i = 0;
	j = 0;
	tab_size = tab_len(ms);
	temp = malloc(sizeof(int) * (tab_size + 1));
	while (i < ms->lexer.nb_of_tokens)
	{
		if (ms->lexer.tokens[i] != WSPACE && ms->lexer.tokens[i] != NA)
		{
			temp[j] = ms->lexer.tokens[i];
			j++;
		}
		i++;
	}
	temp[j] = END;
	free(ms->lexer.tokens);
	ms->lexer.tokens = temp;
	ms->lexer.nb_of_tokens = j;
}

void	final_sort(t_ms *ms)
{
	char	**temp;
	int		tab_size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab_size = tab_len(ms);
	temp = malloc(sizeof(char *) * (tab_size + 1));
	while (i < ms->lexer.nb_of_tokens)
	{
		if (ms->lexer.tokens[i] != WSPACE && ms->lexer.tokens[i] != NA
			&& ms->lexer.tokens_array[i][0] != '\0')
		{
			temp[j] = malloc(sizeof(char)
					* (ft_rstrlen(ms->lexer.tokens_array[i]) + 1));
			ft_strcpy(ms->lexer.tokens_array[i], temp[j]);
			j++;
		}
		i++;
	}
	temp[j] = NULL;
	free_array(ms->lexer.tokens_array);
	ms->lexer.tokens_array = temp;
	sort_token(ms);
}
