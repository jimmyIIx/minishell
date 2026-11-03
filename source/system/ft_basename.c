/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:09:12 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/17 17:38:54 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_basename(const char *path, char *result)
{
	char	*ptr;

	if (!path || !result)
		return ;
	ptr = ft_strrchr(path, '/');
	if (ptr == NULL)
		ft_strcpy(path, result);
	else
		ft_strcpy(ptr + 1, result);
}
