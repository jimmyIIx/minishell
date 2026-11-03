/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:55:00 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/18 15:56:44 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	unset(char *arg, t_ms *ms);

int	builtin_unset(t_cmd *cmd, t_ms *ms)
{
	t_list	*temp;

	temp = cmd->arg;
	while (temp)
	{
		unset(((t_arg *) temp->content)->arg, ms);
		temp = temp->next;
	}
	return (0);
}

static int	unset(char *arg, t_ms *ms)
{
	t_env	*env;
	t_env	*temp;

	env = ms->env;
	temp = NULL;
	while (env)
	{
		if (ft_strcmp(env->name, arg))
		{
			if (temp == NULL)
				ms->env = env->next;
			else if (env->next == NULL)
				temp->next = NULL;
			else
				temp->next = env->next;
			ft_lstdelone_mod(env, ft_free);
			return (0);
		}
		temp = env;
		env = env->next;
	}
	return (0);
}
