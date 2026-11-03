/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigmacros.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:10:12 by rdedola           #+#    #+#             */
/*   Updated: 2025/03/24 15:35:14 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_macro(int sig)
{
	if (sig == SIGINT)
	{
		rl_on_new_line();
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_redisplay();
		g_exit_status = 130;
	}
}

void	handle_ignore(int sig)
{
	(void) sig;
}

void	handle_macro_cct(int sig)
{
	if (sig == SIGINT)
	{
		g_exit_status = 130;
		ft_write(STDOUT_FILENO, "\n");
		close(STDIN_FILENO);
	}
}

void	handle_macro_rtm(int sig)
{
	(void) sig;
}
