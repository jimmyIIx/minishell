/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:40:57 by rdedola           #+#    #+#             */
/*   Updated: 2025/03/18 17:01:02 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_echo(t_cmd *cmd)
{
	bool	nl;
	t_list	*temp;

	temp = cmd->arg;
	nl = true;
	while (temp)
	{
		if (((t_arg *) temp->content)->type == 2
			&& ((t_arg *) temp->content)->is_strict == true
			&& ft_str_other(&(((t_arg *) temp->content)->arg)[1], "n") == false)
			nl = false;
		else
		{
			ft_write(STDOUT_FILENO, ((t_arg *) temp->content)->arg);
			if (temp->next)
				ft_write(STDOUT_FILENO, " ");
		}
		temp = temp->next;
	}
	if (nl)
		ft_write(STDOUT_FILENO, "\n");
	return (0);
}
