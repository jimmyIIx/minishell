/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:32:09 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/06 20:56:53 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lstsize_env(t_env *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst-> next;
		i++;
	}
	return (i);
}
