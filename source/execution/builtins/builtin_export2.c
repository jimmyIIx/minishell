/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:23:21 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/19 16:27:38 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_arg1(char *tabenv, int j);
static void	print_arg2(char *tabenv, int j);

int	export_noarg(t_env *env)
{
	char	**tabenv;
	int		i;
	int		j;

	i = 0;
	tabenv = ft_env_to_array(env);
	ft_qsort((void **) tabenv, ft_alphasort, -1);
	while (tabenv[i])
	{
		j = 0;
		ft_write(STDOUT_FILENO, "declare -x ");
		while (tabenv[i][j] != '\0' && tabenv[i][j] != '=')
			write(STDOUT_FILENO, &tabenv[i][j++], 1);
		if (tabenv[i][j++] == '=')
		{
			if (ft_is_formated(&tabenv[i][j]))
				print_arg1(tabenv[i], j);
			else
				print_arg2(tabenv[i], j);
		}
		ft_write(STDOUT_FILENO, "\n");
		++i;
	}
	return (ft_free_deep(tabenv), 1);
}

static void	print_arg1(char *tabenv, int j)
{
	ft_write(STDOUT_FILENO, "=$'");
	while (tabenv[j])
	{
		if (tabenv[j] == '\f')
			write(STDOUT_FILENO, "\\f", 2);
		else if (tabenv[j] == '\n')
			write(STDOUT_FILENO, "\\n", 2);
		else if (tabenv[j] == '\r')
			write(STDOUT_FILENO, "\\r", 2);
		else if (tabenv[j] == '\t')
			write(STDOUT_FILENO, "\\t", 2);
		else if (tabenv[j] == '\v')
			write(STDOUT_FILENO, "\\v", 2);
		else
			write(STDOUT_FILENO, &tabenv[j], 1);
		++j;
	}
	ft_write(STDOUT_FILENO, "'");
}

static void	print_arg2(char *tabenv, int j)
{
	ft_write(STDOUT_FILENO, "=\"");
	ft_write(STDOUT_FILENO, &tabenv[j]);
	ft_write(STDOUT_FILENO, "\"");
}
