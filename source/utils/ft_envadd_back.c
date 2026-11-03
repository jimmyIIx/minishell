/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:44:44 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/18 18:20:30 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_envadd_back(t_env **env, t_env *new)
{
	t_env	*last;

	if (*env)
	{
		last = *env;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	else
		*env = new;
}
