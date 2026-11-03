/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:55:46 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/25 12:28:15 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_close(int *fd)
{
	int	status;
	if (*fd == -1)
		return (0);

	status = close(*fd);
	*fd = -1;
	return (status);
}
