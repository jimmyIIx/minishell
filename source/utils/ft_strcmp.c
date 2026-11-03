/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:40:32 by rdedola           #+#    #+#             */
/*   Updated: 2025/01/07 10:44:01 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (str1)
	{
		while (str1[i] || str2[i])
		{
			if (str1[i] != str2[i])
				return (FALSE);
			i++;
		}
		return (TRUE);
	}
	return (FALSE);
}
