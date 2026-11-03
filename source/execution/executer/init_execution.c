/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:32:25 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/19 16:39:53 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**init_execution(t_cmd *cmd)
{
	char	arg[BUFSIZ];
	t_list	*larg;

	ft_bzero(arg, BUFSIZ);
	ft_strlcat(arg, cmd->cmd, BUFSIZ);
	ft_strlcat(arg, " ", BUFSIZ);
	larg = cmd->arg;
	while (larg)
	{
		ft_strlcat(arg, " ", BUFSIZ);
		ft_strlcat(arg, ((t_arg *) larg->content)->arg, BUFSIZ);
		larg = larg->next;
	}
	return (ft_split(arg, ' '));
}
