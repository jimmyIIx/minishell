/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:00:32 by rdedola           #+#    #+#             */
/*   Updated: 2025/03/18 21:09:53 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_pwd(t_ms *ms)
{
	char	*cwd;

	cwd = search_var("PWD", ms->env);
	if (cwd == NULL)
		cwd = getcwd(NULL, 0);
	if (cwd == NULL)
	{
		ft_write(STDIN_FILENO, "pwd error\n");
		return (1);
	}
	ft_write(STDIN_FILENO, cwd);
	ft_write(STDIN_FILENO, "\n");
	return (0);
}
