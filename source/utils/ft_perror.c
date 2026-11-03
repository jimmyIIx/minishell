/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:20:09 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/17 16:47:07 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_perror(const char *shell, char const *cmd, char const *arg,
			char const *msg)
{
	if (shell != NULL)
	{
		ft_write(STDERR_FILENO, shell);
		ft_write(STDERR_FILENO, ": ");
	}
	if (cmd != NULL)
	{
		ft_write(STDERR_FILENO, cmd);
		ft_write(STDERR_FILENO, ": ");
	}
	if (arg != NULL)
	{
		ft_write(STDERR_FILENO, arg);
		ft_write(STDERR_FILENO, ": ");
	}
	if (msg != NULL)
	{
		ft_write(STDERR_FILENO, msg);
	}
	ft_write(STDERR_FILENO, "\n");
}
