/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:26:01 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/18 20:53:55 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	st_arg_clear(t_arg *arg)
{
	(void) arg;
}

void	st_arg_init(t_arg *arg)
{
	ft_bzero(arg->arg, BUFSIZ);
	arg->type = 0;
	arg->is_strict = true;
}
