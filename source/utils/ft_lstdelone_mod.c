/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_mod.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:01:18 by rdedola           #+#    #+#             */
/*   Updated: 2025/03/13 19:21:24 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstdelone_mod(t_env *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del (lst->arg);
	del (lst->name);
	lst->arg = NULL;
	lst->name = NULL;
	free(lst);
}
