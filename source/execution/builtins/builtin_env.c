/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:57:52 by rdedola           #+#    #+#             */
/*   Updated: 2025/03/17 16:54:20 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_env(t_env *env)
{
	while (env)
	{
		if (env->is_egal)
		{
			ft_write(STDOUT_FILENO, env->name);
			ft_write(STDOUT_FILENO, "=");
			ft_write(STDOUT_FILENO, env->arg);
			ft_write(STDOUT_FILENO, "\n");
		}
		env = env->next;
	}
	return (0);
}
