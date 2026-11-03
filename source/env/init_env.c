/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 08:41:59 by rdedola           #+#    #+#             */
/*   Updated: 2025/03/19 15:51:50 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	env_update(t_ms *ms);

void	init_env(t_ms *ms, char **envp)
{
	int		i;
	int		j;
	bool	is_egal;

	i = 0;
	ms->env = NULL;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			++j;
		if (envp[i][j] == '=')
			is_egal = true;
		ft_envadd_back(&ms->env, ft_rlstnew(
				ft_substr(envp[i], 0, j),
				ft_substr(&envp[i][j + 1], 0,
					ft_strlen(&envp[i][j]) - 1), is_egal));
		++i;
	}
	env_update(ms);
}

static void	env_update(t_ms *ms)
{
	char	*shlvl;
	char	*new;
	int		lvl;
	char	buff[BUFSIZ];

	add_var("PWD", getcwd(buff, 0), true, ms->env);
	shlvl = search_var("SHLVL", ms->env);
	if (shlvl == NULL)
		lvl = 1;
	else
		lvl = ft_atoi(shlvl) + 1;
	new = ft_itoa(lvl);
	modify_var("SHLVL", new, true, ms->env);
	ft_free(new);
}
