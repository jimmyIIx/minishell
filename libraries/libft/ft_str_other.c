/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_other.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nippolit <nippolit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:31:40 by nippolit          #+#    #+#             */
/*   Updated: 2025/03/18 16:57:59 by nippolit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_str_other(const char *str, const char *target)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr(target, str[i]) == NULL)
			return (true);
		++i;
	}
	return (false);
}
