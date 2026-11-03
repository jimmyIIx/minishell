/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:12:01 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/19 16:02:11 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*search_var(char *str, t_env *env)
{
	t_env	*temp;

	if (!env)
		return (NULL);
	temp = env;
	while (temp)
	{
		if (ft_strcmp(str, temp->name))
			return (temp->arg);
		temp = temp->next;
	}
	return (NULL);
}

void	modify_var(char *name, char *new, bool egal, t_env *env)
{
	t_env	*last;

	while (env)
	{
		if (ft_strcmp(name, env->name))
		{
			ft_free(env->arg);
			env->arg = ft_strdup(new);
			env->is_egal = egal;
			return ;
		}
		last = env;
		env = env->next;
	}
	ft_envadd_back(&last, ft_rlstnew(ft_strdup(name), ft_strdup(new), egal));
}

void	add_var(char *name, char *new, bool egal, t_env *env)
{
	t_env	*last;

	while (env)
	{
		if (ft_strcmp(name, env->name))
			return ;
		last = env;
		env = env->next;
	}
	ft_envadd_back(&last, ft_rlstnew(ft_strdup(name), ft_strdup(new), egal));
}

bool	ft_is_formated(char *arg)
{
	size_t	i;

	i = 0;
	while (arg[i])
	{
		if (ft_strchr("\f\n\r\t\v", arg[i]) != NULL)
			return (true);
		++i;
	}
	return (false);
}
