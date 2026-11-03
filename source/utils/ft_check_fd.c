/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:38:47 by rdedola           #+#    #+#             */
/*   Updated: 2025/03/17 19:05:06 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_check_fd(void)
{
	if (!isatty(STDIN_FILENO))
	{
		printf("exit\n");
		exit(1);
	}
	else if (!isatty(STDOUT_FILENO))
	{
		printf("exit\n");
		exit(1);
	}
	else if (!isatty(STDERR_FILENO))
	{
		printf("exit\n");
		exit(1);
	}
	return ;
}
