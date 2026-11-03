/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freebox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:30:49 by rdedola           #+#    #+#             */
/*   Updated: 2025/01/07 15:09:12 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tok(t_ms *ms)
{
	int	i;

	if (ms->input)
		free(ms->input);
	i = 0;
	while (ms->lexer.tokens_array && ms->lexer.tokens_array[i])
		free(ms->lexer.tokens_array[i++]);
	free(ms->lexer.tokens_array);
	free(ms->lexer.tokens);
	ms->lexer.tokens_array = NULL;
	ms->lexer.tokens = NULL;
}

// void	free_envarray(t_ms *ms, char **envp)
// {
// 	int	i;

// 	i = 0;
// 	if (ms->env_array)
// 	{
// 		while (ms->env_array[i])
// 			free(ms->env_array[i++]);
// 	}
// 	free(ms->env_array);
// 	// i = 0;
// 	// if (!ms->is_env)
// 	// {
// 	// 	while (envp[i])
// 	// 		free (envp[i++]);
// 	// 	free(envp);
// 	// }
// }

void	free_env(t_env *env)
{
	t_env	*next;

	while (env)
	{
		next = env->next;
		ft_free(env->name);
		ft_free(env->arg);
		ft_free(env);
		env = next;
	}
}
