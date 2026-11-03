/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rstrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:54:32 by rdedola           #+#    #+#             */
/*   Updated: 2025/03/16 21:06:59 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	ft_rstrchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (FALSE);
	while (str[i])
	{
		if (str[i] == c)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
